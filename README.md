# Brain on Fire 🔥🧠

**Brain on Fire** è un gioco progettato per allenare il cervello in modo divertente, concentrandosi su tre abilità fondamentali:
- 🧩 **Memoria**
- 🎯 **Concentrazione**
- 🔤 **Linguaggio**

Il gioco è sviluppato in **C++** e utilizza la libreria **[SDL2](https://www.libsdl.org/)** per la gestione di grafica, audio e input.  

---

## 📌 Requisiti

Per collaborare allo sviluppo, assicurati di avere:  
- Un sistema **Linux** (Ubuntu, Fedora, Arch, ecc.)  
- **SDL2** installato  
- Un compilatore **C++** (`g++` o `clang++`)  
- **Git** installato  

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

## 📥 Clonare il Progetto

Clona il repository:  
```bash
git clone https://github.com/Feb487/theBrainonFire_project.git
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

## 🎮 Cosa è SDL2?

**[SDL2 (Simple DirectMedia Layer)](https://www.libsdl.org/)** è una libreria **multipiattaforma** scritta in C che fornisce un’interfaccia semplice per:  
- 🎨 **Grafica 2D** → finestre, rendering e gestione degli sprite.  
- 🎮 **Input** → tastiera, mouse, controller e gamepad.  
- 🔊 **Audio** → effetti sonori e musica.  
- ⏱️ **Timer e threading** → sincronizzazione e multitasking.  

SDL2 è utilizzata da molte aziende e progetti famosi (tra cui **Valve**, **id Software** e **Epic Games**) ed è uno strumento fondamentale per chi sviluppa videogiochi **indie** o applicazioni multimediali.  

---

## 🤝 Come Contribuire

Vuoi aiutarci a migliorare **Brain on Fire**? Segui questi passaggi:  

1. **Forka** il repository su GitHub.  
2. **Clona** il tuo fork in locale:  
   ```bash
   git clone https://github.com/tuo-username/brain-on-fire.git
   cd brain-on-fire
   ```
3. **Crea un branch dedicato** per la tua modifica (non lavorare mai direttamente su `main`):  
   ```bash
   git checkout -b nome-feature
   ```
   Esempio:  
   ```bash
   git checkout -b fix-input-handler
   ```
4. **Fai le modifiche** e committale:  
   ```bash
   git add .
   git commit -m "Fix gestione input del player"
   ```
5. **Pusha il branch** sul tuo fork:  
   ```bash
   git push origin nome-feature
   ```
6. Apri una **Pull Request (PR)** dal tuo branch al branch `main` del repository principale.  

---

## 📧 Contatti
Per domande, suggerimenti o collaborazioni, apri una **Issue** su GitHub o utilizza la sezione discussioni del progetto.

---

*Divertiti a sviluppare e a migliorare il tuo cervello con Brain on Fire!** 🚀
