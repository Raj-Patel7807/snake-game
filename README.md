# Snake Game 🐍

A terminal-based Snake Game built in **C++** with clean architecture, colorful console rendering, power-ups, obstacles,
animations, and persistent high scores.

Designed using modular OOP principles to keep the codebase scalable, maintainable, and fun to extend.

This Snake Game will work in both Windows and Linux OS.

---

## ✨ Features

- Multiple fruit types with different scoring
- Timed bonus rewards
- Dangerous poison fruits
- Dynamic obstacle system
- Pause & resume functionality
- Ghost / Shield / Slow-motion powerups
- High score persistence using file handling
- Start screen & end screen UI
- Colorful terminal rendering
- Clean modular project structure
- CMake build support

---

## ⚙️ Tech Stack

- **Language:** C++
- **Build System:** CMake
- **Concepts Used:**
    - Object-Oriented Programming
    - Modular Design
    - File Handling
    - Game Loop
    - Collision Detection
    - Console Rendering

---

## 🚀 Quick Start

### Clone Repository

```bash
git clone https://github.com/your-username/snake-game.git
cd snake-game
```

### Run Directly

```bash
./SnakeGame.exe
```

Or just double click on the "SnakeGame.exe" file.

No setup needed — executable is already included in the repository 😄

---

## 🎮 Controls

| Key   | Action           |
|-------|------------------|
| W / ↑ | Move Up          |
| A / ← | Move Left        |
| S / ↓ | Move Down        |
| D / → | Move Right       |
| P     | Pause Game       |
| R     | Resume Game      |
| H     | Toggle Help Menu |
| X     | Reset Game       |
| ESC   | Exit Game        |

---

## ⚡ Power-Ups

| Power-Up | Effect            |
|----------|-------------------|
| S        | Shield Protection |
| T        | Slow Motion       |
| G        | Ghost Mode        |

---

## 🧠 Game Elements

| Symbol | Meaning       |
|--------|---------------|
| `@`    | Normal Fruit  |
| `$`    | Special Fruit |
| `!`    | Poison Fruit  |
| `*`    | Timed Bonus   |
| `#`    | Obstacles     |
| `O`    | Snake Head    |
| `o`    | Snake Body    |

---

## 📂 Project Structure

```bash
src/
├── config/         # Game settings & configuration
├── food/           # Fruit spawning & logic
├── game/           # Core game engine
├── obstacles/      # Obstacle generation system
├── persistence/    # High score handling
├── powerups/       # Power-up mechanics
├── snake/          # Snake movement & collision
├── ui/             # Start/end screens
└── utils/          # Input, colors, animation, helpers
```

---

## 💡 Highlights

- Beginner-friendly project
- Well-structured and scalable architecture
- Easy to extend with new mechanics
- Great practice project for OOP & game loops
- Clean separation of logic and rendering

---

## 📌 Future Improvements

- Multiple difficulty modes
- Sound effects & background music
- Better animations
- Multiplayer support
- Save & load game state

---

Built by Raj Patel
