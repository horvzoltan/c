Absolutely! Here's a **step-by-step beginner-friendly tutorial** to walk you through creating a **basic Mario-style game in the terminal using C**, with ASCII art for the map.

---

# 🎮 Terminal Mario Game in C — Beginner Tutorial

> You'll create a terminal-based Mario-style platformer with:
>
> * Movement (left, right, jump)
> * Gravity
> * ASCII map (external level file)
> * No enemies, coins, or scoring (keeping it simple)

---

## 🧰 1. Prerequisites

You'll need:

* A **C compiler** (e.g. `gcc`)
* The **`ncurses` library** (for drawing on the terminal)
* A text editor (like VS Code, Vim, or Nano)
* A terminal (Linux/macOS, or WSL on Windows)

### 🔧 Install `ncurses` (only once):

For Debian/Ubuntu/macOS:

```bash
sudo apt install libncurses5-dev libncursesw5-dev
```

---

## 📁 2. Create the Project Files

### 🔹 Create these two files:

```bash
touch simple_mario.c level.txt
```

---

## 🧱 3. Write the Level (`level.txt`)

Open `level.txt` and paste this:

```txt
##############################
#                            #
#                            #
#                            #
#          ===              #
#                            #
#                            #
#                            #
#                            #
#     @               ======#
##############################
```

Explanation:

* `#` and `=` are platforms
* `@` is the **starting position of the player**
* Space is empty

---

## 💻 4. Write the Game Code (`simple_mario.c`)

Open `simple_mario.c` and paste this:

```c
#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 256
#define MAX_HEIGHT 64
#define DELAY 30000
#define GRAVITY 1
#define JUMP_VELOCITY -3

char level[MAX_HEIGHT][MAX_WIDTH];
int level_height = 0, level_width = 0;

typedef struct {
    int x, y;
    int vy;
    int is_jumping;
} Player;

int load_level(const char *filename, Player *player) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("Could not open level file");
        return 0;
    }

    char line[MAX_WIDTH];
    int y = 0;
    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\n")] = 0;
        strcpy(level[y], line);
        if ((int)strlen(line) > level_width)
            level_width = strlen(line);
        char *p = strchr(line, '@');
        if (p) {
            player->x = p - line;
            player->y = y;
            level[y][player->x] = ' ';
        }
        y++;
    }
    level_height = y;
    fclose(f);
    return 1;
}

void draw(Player *player) {
    clear();
    for (int y = 0; y < level_height; y++) {
        mvprintw(y, 0, level[y]);
    }
    mvprintw(player->y, player->x, "@");
    refresh();
}

int is_empty(int x, int y) {
    if (y < 0 || y >= level_height || x < 0 || x >= level_width)
        return 0;
    char c = level[y][x];
    return c == ' ';
}

int main() {
    Player player = {0, 0, 0, 0};

    if (!load_level("level.txt", &player))
        return 1;

    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    int ch;
    while (1) {
        ch = getch();
        if (ch == 'q') break;

        if (ch == KEY_LEFT && is_empty(player.x - 1, player.y))
            player.x--;
        if (ch == KEY_RIGHT && is_empty(player.x + 1, player.y))
            player.x++;

        if (ch == ' ' && !player.is_jumping) {
            player.vy = JUMP_VELOCITY;
            player.is_jumping = 1;
        }

        player.vy += GRAVITY;
        int new_y = player.y + player.vy;

        if (player.vy > 0) {
            for (int i = player.y + 1; i <= new_y && i < level_height; i++) {
                if (!is_empty(player.x, i)) {
                    player.y = i - 1;
                    player.vy = 0;
                    player.is_jumping = 0;
                    goto skip_fall;
                }
            }
        }

        if (is_empty(player.x, new_y))
            player.y = new_y;
skip_fall:

        draw(&player);
        usleep(DELAY);
    }

    endwin();
    return 0;
}
```

---

## 🛠️ 5. Compile the Code

In your terminal:

```bash
gcc simple_mario.c -lncurses -o simple_mario
```

> This creates an executable named `simple_mario`

---

## ▶️ 6. Run the Game!

```bash
./simple_mario
```

---

## 🎮 Controls

* `←` and `→` — move left/right
* `Spacebar` — jump
* `q` — quit the game

---

## 📚 How It Works

### 🧱 Map

* Loaded from `level.txt` as a 2D array
* `@` sets the initial player position
* `#` and `=` are solid

### 🕹 Player

* Moves with arrow keys
* Has a vertical velocity (`vy`)
* Gravity is simulated each frame

### ⛔ Collision

* Checks if the space below is solid
* Stops falling if it hits a platform

---

## ✅ What You Just Built

* A working terminal game loop in C
* Real-time player input with `ncurses`
* Gravity and jumping
* An ASCII level system

---

## 🔜 Want to Keep Going?

You can now:

* Create new levels by editing `level.txt`
* Add coins (`o`), spikes (`^`), doors, etc.
* Build an interactive level editor (I can help!)
* Add horizontal level scrolling

---

Would you like me to:

* Help you add horizontal camera movement?
* Add more mechanics like death zones or checkpoints?
* Build a terminal-based level editor?

Let me know what you’d like to build next!
