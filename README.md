# 2048
The classic 2048 game written in C++. This was my second project and I might have some refactoring to consider, but this endeavor reflects the progress I've made since my early days of programming.
 
## Features
- Move the tiles using **W A S D**
- Monitor your current score and highscore
- Options to start a new game or quit

## Quick Start

### 1. Clone the project

```sh
git clone https://github.com/JellyGamez/2048.git
```

### 2. Go to the project directory

```sh
cd 2048
```

### 3. Compile

- Windows
```sh
g++ main.cpp -o main
```

- Linux

The linux version makes use of an external library you need to install:
```sh
sudo apt-get install ncurses-dev
g++ main.cpp -lncurses -o main
```

### 4. Launch the game

```sh
./main
```

## Note
The default terminal window may be too small, so make sure to resize it to fit the whole board and menu.
