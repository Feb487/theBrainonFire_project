# Brain on Fire 🔥🧠

**Brain on Fire** è un gioco progettato per allenare il cervello in modo divertente, concentrandosi su tre abilità fondamentali:
- 🧩 **Memoria**
- 🎯 **Concentrazione**
- 🔤 **Linguaggio**

Il gioco è sviluppato in **C++** e utilizza la libreria  per la gestione di grafica, audio e input.  

---

## 📌 Requisiti

Per collaborare allo sviluppo, assicurati di avere:  
- Un sistema **Linux** (Ubuntu, Fedora, Arch, ecc.)  
- **[SDL2](https://www.libsdl.org/)** installato.
- Un compilatore **C++** (`cmake`)
- **[Git](https://git-scm.com/)** installato.

---

## 💾​ Cos'è SDL2?

**[SDL2 (Simple DirectMedia Layer)](https://www.libsdl.org/)** è una libreria **multipiattaforma** scritta in C che fornisce un’interfaccia semplice per:  
- 🎨 **Grafica 2D** → finestre, rendering e gestione degli sprite.  
- 🎮 **Input** → tastiera, mouse, controller e gamepad.  
- 🔊 **Audio** → effetti sonori e musica.  
- ⏱️ **Timer e threading** → sincronizzazione e multitasking.  

SDL2 è utilizzata da molte aziende e progetti famosi (tra cui **Valve**, **id Software** e **Epic Games**) ed è uno strumento fondamentale per chi sviluppa videogiochi **indie** o applicazioni multimediali.  

---

## 💻 Cos'è CMake?

**[CMake](https://cmake.org/)** è un sistema di build **multipiattaforma** scritto in C++ che permette di:

- 📂 **Gestire progetti complessi** → organizza codice sorgente e dipendenze.
- ⚙️ **Generare build system** → produce file per Makefile, Ninja, Visual Studio, Xcode, ecc.
- 🔗 **Gestire librerie** → rileva e configura automaticamente pacchetti esterni.
- 🚀 **Portabilità** → lo stesso progetto può essere compilato su Linux, Windows, macOS e altre piattaforme.

CMake è ampiamente usato in progetti open source e commerciali, tra cui **LLVM/Clang**, **Qt**, **Blender** e **KDE**.

---

## 🛠️ Installazione di SDL2

### Debian/Ubuntu
```bash
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
```

### Fedora
```bash
sudo dnf install SDL2-devel SDL2_image-devel SDL2_ttf-devel SDL2_mixer-devel
```

### Arch Linux
```bash
sudo pacman -S sdl2 sdl2_image sdl2_ttf sdl2_mixer
```

---

## 🛠️ Installazione di CMake

### Debian/Ubuntu
```bash
sudo apt-get install cmake
```

### Fedora
```bash
sudo dnf install cmake
```

### Arch Linux
```bash
sudo pacman -S cmake
```

Compila il progetto:  
```bash
g++ -o theBrainOnFire main.cpp src/*.cpp -Iheader -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
```

Esegui il gioco:  
```bash
./theBrainOnFire
```

---

## 🤝 Come Contribuire

Vuoi aiutarci a migliorare **Brain on Fire**? Segui questi passaggi:  

1. **Forka** il repository su GitHub.  
2. **Clona** il tuo fork in locale:  
   HTTPS:
   ```bash
   git clone https://github.com/Feb487/theBrainonFire_project.git
   ```
   SSH:
   ```bash
   git clone git@github.com:tuo-nickname/theBrainonFire_project.git
   ```
3. **Spostati** nella cartella del progetto
   ```bash
   cd theBrainonFire_project
   ```
4. **Crea** un branch dedicato per la tua modifica (non lavorare mai direttamente su `main`):  
   ```bash
   git checkout -b feature-nome-feature
   ```
   Esempio:  
   ```bash
   git checkout -b feature-fix-player
   ```
5. **Effettua** le modifiche e committale:  
   ```bash
   git add .
   git commit -m "Commenta la commit con ciò che hai modificato"
   ```
6. **Pusha** il branch sul tuo fork:  
   ```bash
   git push origin feature-nome-feature
   ```
7. **Apri** una **Pull Request (PR)** dal tuo branch al branch `main` del repository principale.  
8. Una volta accettata la **Pull Request (PR)** potrai eliminare il branch utilizzato:
   ```bash
   git checkout -d feature-nome-feature
   ```
---

## 🎮 Come eseguire il Gioco

Vuoi giocare a **Brain on Fire**? Segui questi passaggi:

1. **Spostati** nella cartella debug:
   ```bash
   cd build/release
   ```
2. **Compila** utilizzando cmake:
   ```bash
   #cmake --build . -j$(nproc)
   ```
3. **Esegui** il file compilato:
   ```bash
   #cmake --build . --target run
   ```
4. **Divertiti**!

---

## 📧 Contatti
Per domande, suggerimenti o collaborazioni, apri una **Issue** su GitHub o utilizza la sezione discussioni del progetto.

---

*Divertiti a sviluppare e a migliorare il tuo cervello con Brain on Fire!* 🚀