# 🐍 Snake Game

---

## 📌 Table of Contents

- [📖 Introduction](#-introduction)
- [✨ Features](#-features)
- [🎮 How to Play](#-how-to-play)
- [🎯 Game Controls](#-game-controls)
- [🚀 Installation Guide](#-installation-guide)
- [🕹️ Game Mechanics](#-game-mechanics)
- [💡 Code Structure](#-code-structure)
- [🚀 Future Enhancements](#-future-enhancements)
- [👥 Contributors](#-contributors)

---

## 📖 Introduction

This project is a console-based Snake Game implemented in C++. It follows an object-oriented approach using classes and
inheritance to manage game components like the snake, fruit, and game board.**Our code is for Windows and Linux. It will
work in both OS.**

---

## ✨ Features

- 🎯 Grid-based gameplay.
- 🎮 Snake movement using keyboard controls.
- 🍏 Normal and special fruits for scoring.
- 🚧 Obstacles appear as the game progresses.
- 🧱 Wall collision mode (can be enabled or disabled).
- 🔄 Dynamic difficulty adjustment.
- 📺 Clear UI with instructions and score tracking.

---

## 🎮 How to Play

- Control the snake using `W, A, S, D` or arrow keys.
- 🍏 Eat fruits (`@` for normal, `$` for special) to grow and score points.
- 🚧 Avoid walls and obstacles (`#`).
- ☠️ Game over if the snake collides with itself or obstacles.
- 🔄 Restart or exit after game over.

---

## 🎯 Game Controls

| 🎮 Key   | 🏹 Action  |
|----------|------------|
| `W / ⬆️` | Move Up    |
| `S / ⬇️` | Move Down  |
| `A / ⬅️` | Move Left  |
| `D / ➡️` | Move Right |
| `P`      | Pause      |
| `R`      | Resume     |
| `X`      | Reset Game |
| `ESC`    | Exit Game  |

---

## 🚀 Installation Guide

Follow these steps to install and run the **Snake Game** on your machine:

### 1️⃣ Clone the Repository 🖥️

- Ensure you have **Git** installed, then run:

```bash

git clone https://github.com/Raj-Patel7807/snake-game.git

```  

### 2️⃣ Navigate to the Project Directory 📂

```bash

cd snake-game

```  

### Run the .exe file in your terminal and Play the Game..🥳

```bash
./SnakeGame.exe
```

[//]: # ()

[//]: # (### 3️⃣ Compile the Source Code ⚙️)

[//]: # (- Make sure you have **g++** &#40;GCC compiler&#41; installed, then compile the code:  )

[//]: # (```bash)

[//]: # (g++ main.cpp -o main)

[//]: # (```  )

[//]: # ()

[//]: # (### 4️⃣ Run & Play the Game 🎮  )

[//]: # ()

[//]: # (- **For Linux Users 🐧:**  )

[//]: # (```bash)

[//]: # (./main)

[//]: # (```  )

[//]: # (- **For Windows Users 🪟:**  )

[//]: # (```bash)

[//]: # (main.exe)

[//]: # (```  )

[//]: # ()

[//]: # (### 5️⃣ &#40;Optional&#41; Clone with SSH 🔑  )

[//]: # (- If you prefer SSH over HTTPS:  )

[//]: # (```bash)

[//]: # (git clone git@github.com:Raj-Patel7807/Snake_Game.git)

[//]: # (```  )

[//]: # ()

[//]: # (### 6️⃣ &#40;Optional&#41; Pull Latest Updates 🔄  )

[//]: # (- If you have already cloned the repo and want to get the latest updates:  )

[//]: # (```bash)

[//]: # (git pull origin main)

[//]: # (```  )

[//]: # ()

[//]: # (**Enjoy the game! 🐍🔥**)

[//]: # ()

[//]: # (---)

## 🕹️ Game Mechanics

- 🐍 The snake moves continuously in the last chosen direction.
- 🍏 Eating a normal fruit (@) increases the score by **5 points**.
- 💰 Eating a special fruit ($) increases the score by **20 points**.
- 🚧 Once the score reaches **50**, obstacles appear.
- 🔼 The difficulty increases dynamically with score progression.

---

## 💡 Code Structure

The game is implemented using **Object-Oriented Programming (OOP) principles**:

- 🛠️ `Game` (Base Class): Defines the core game logic and properties.
- 🐍 `Snake` (Inherits from Game): Handles the snake’s movement.
- 🍏 `Fruit` (Inherits from Snake): Manages fruit generation.
- 🎮 `Main` (Inherits from Fruit): Controls the game loop, rendering, and input handling.

---

## 🚀 Future Enhancements

- 🎮 Multiple levels with increasing complexity.
- 👫 Multiplayer mode with two snakes.
- 🏆 High score tracking system.
- 🤖 AI-controlled opponent snakes.
- 🎨 GUI-based version using a graphics library.

---

**Happy Coding 🧑🏻‍💻✨**
---
