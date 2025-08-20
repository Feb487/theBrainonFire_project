
# Brain on Fire 🔥🧠

**Brain on Fire** è un gioco progettato per allenare il cervello in modo divertente, concentrandosi su tre abilità fondamentali:
- **Memoria**
- **Concentrazione**
- **Linguaggio**

Il gioco è sviluppato in **C++** e utilizza la libreria **SDL2** per la gestione di grafica, audio e input.

---

## 📌 Requisiti per Collaborare

Per contribuire allo sviluppo di **Brain on Fire**, assicurati di avere:
- Un sistema **Linux** (Ubuntu, Fedora, Arch, ecc.).
- **SDL2** installato sulla tua macchina.
- Un compilatore **C++** (ad esempio, `g++` o `clang++`).
- **Git** per clonare il repository.

---

## 🛠️ Installazione di SDL2 su Linux

Se non hai già **SDL2**, puoi installarlo facilmente con il seguente comando:

### Su Debian/Ubuntu:
```bash
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
```

### Su Fedora:
```bash
sudo dnf install SDL2-devel SDL2_image-devel SDL2_ttf-devel SDL2_mixer-devel
```

### Su Arch Linux:
```bash
sudo pacman -S sdl2 sdl2_image sdl2_ttf sdl2_mixer
```

---

## 📥 Clonare il Progetto

Per clonare il repository e iniziare a collaborare, esegui i seguenti passaggi:

1. Apri il terminale.
2. Esegui il comando:
   ```bash
   git clone https://github.com/tuo-username/brain-on-fire.git
   ```
   *(Sostituisci `tuo-username` con il nome utente o l’URL del repository.)*

3. Entra nella cartella del progetto:
   ```bash
   cd brain-on-fire
   ```

4. Compila il progetto (esempio con `g++`):
   ```bash
   g++ -std=c++11 main.cpp -o brain_on_fire `sdl2-config --cflags --libs`
   ```

5. Esegui il gioco:
   ```bash
   ./brain_on_fire
   ```

---

## 🎮 Cos’è SDL2?

**SDL2 (Simple DirectMedia Layer)** è una libreria multipiattaforma che permette di gestire:
- **Grafica 2D** (finestre, rendering, sprite).
- **Input** (tastiera, mouse, gamepad).
- **Audio** (effetti sonori e musica).
- **Timer e threading**.

È ampiamente utilizzata nello sviluppo di giochi e applicazioni multimediali grazie alla sua semplicità e flessibilità.

---

## 🤝 Come Contribuire

Se vuoi contribuire al progetto:
1. **Forka** il repository su GitHub.
2. Crea un **branch** per le tue modifiche:
   ```bash
   git checkout -b mia-feature
   ```
3. Apporta le tue modifiche e **commita**:
   ```bash
   git commit -m "Aggiunta nuova feature"
   ```
4. **Pusha** il branch:
   ```bash
   git push origin mia-feature
   ```
5. Apri una **Pull Request** sul repository principale.

---

## 📧 Contatti

Per domande o suggerimenti, puoi contattarci tramite:
- **Email**: [tua-email@example.com](mailto:tua-email@example.com)
- **GitHub Issues**: [Issues di Brain on Fire](https://github.com/tuo-username/brain-on-fire/issues)

---

**Divertiti a sviluppare e a migliorare il tuo cervello con Brain on Fire!** 🚀
