#Istruzione build debug e release BrainOnFire
#
# Build Release (include AppImage)
#mkdir -p build/release
#cd build/release
#cmake ../.. -DCMAKE_BUILD_TYPE=Release
#cmake --build . -j$(nproc)
#cmake --build . --target run
#cmake --build . --target appimage

# Build Debug (senza AppImage)
#mkdir -p build/debug
#cd build/debug
#cmake ../.. -DCMAKE_BUILD_TYPE=Debug
#cmake --build . -j$(nproc)
#cmake --build . --target run

cmake_minimum_required(VERSION 3.15)
project(theBrainOnFire LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tipo di build
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose build type: Debug or Release" FORCE)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Abilita flag extra in Debug
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Compilazione in Debug con AddressSanitizer e UBsan")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -fno-omit-frame-pointer -g -O0")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address,undefined")
endif()


# Dipendenze con pkg-config
 
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

# Sorgenti
file(GLOB SOURCES src/*.cpp)
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    include
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
)

# Copia assets nella build dir
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)

# Target run
 
add_custom_target(run
    COMMAND $<TARGET_FILE:${PROJECT_NAME}>
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)


# Packaging solo per Release
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(APPDIR "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.AppDir")
    set(RELEASE_DIR "${CMAKE_BINARY_DIR}/release")

    # --- AppDir structure ---
    add_custom_target(appdir ALL
        COMMAND ${CMAKE_COMMAND} -E rm -rf ${APPDIR}
        COMMAND ${CMAKE_COMMAND} -E make_directory
            ${APPDIR}/usr/bin
            ${APPDIR}/usr/share/applications
            ${APPDIR}/usr/share/icons/hicolor/256x256/apps
    )

    # --- Copy binary ---
    add_custom_command(TARGET appdir POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:${PROJECT_NAME}> ${APPDIR}/usr/bin/${PROJECT_NAME}
    )

    # --- Copy assets ---
    add_custom_command(TARGET appdir POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets ${APPDIR}/usr/assets
    )

    # --- Copy icon ---
    add_custom_command(TARGET appdir POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/assets/game_logo/logo.png
            ${APPDIR}/${PROJECT_NAME}.png
        COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/assets/game_logo/logo.png
            ${APPDIR}/usr/share/icons/hicolor/256x256/apps/${PROJECT_NAME}.png
    )

    # --- Desktop file ---
    file(WRITE ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.desktop
    "[Desktop Entry]\n"
    "Name=Brain On Fire\n"
    "Exec=${PROJECT_NAME}\n"
    "Icon=${PROJECT_NAME}\n"
    "Type=Application\n"
    "Categories=Game;\n"
    )
    add_custom_command(TARGET appdir POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.desktop
            ${APPDIR}/${PROJECT_NAME}.desktop
    )

    # --- AppRun ---
    file(WRITE ${CMAKE_BINARY_DIR}/AppRun
    "#!/bin/bash\n"
    "HERE=\"$(dirname \"$(readlink -f \"$0\")\")\"\n"
    "cd \"$HERE/usr\"\n"
    "exec \"$HERE/usr/bin/${PROJECT_NAME}\" \"$@\"\n"
    )
    file(CHMOD ${CMAKE_BINARY_DIR}/AppRun PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ)
    add_custom_command(TARGET appdir POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/AppRun ${APPDIR}/AppRun
    )

    # --- appimage target ---
    add_custom_target(appimage
        DEPENDS ${PROJECT_NAME} appdir
        COMMAND ${CMAKE_COMMAND} -E make_directory ${RELEASE_DIR}
        COMMAND wget -nc -O ${CMAKE_BINARY_DIR}/appimagetool-x86_64.AppImage
                https://github.com/AppImage/AppImageKit/releases/download/continuous/appimagetool-x86_64.AppImage
        COMMAND chmod +x ${CMAKE_BINARY_DIR}/appimagetool-x86_64.AppImage
        COMMAND ARCH=x86_64 ${CMAKE_BINARY_DIR}/appimagetool-x86_64.AppImage
                ${APPDIR} ${RELEASE_DIR}/${PROJECT_NAME}-x86_64.AppImage
        COMMENT "Packaging Linux AppImage"
    )
endif()

