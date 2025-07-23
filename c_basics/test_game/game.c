#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // Used for file operations

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
    int isJumping;
} Player;

int load_level(const char *filename) {
    FILE *f = fopen(filename, "r");

    if (!f) {
        perror("Could not open leve file");
        return 0;
    }

    char line[MAX_WIDTH];
    int y = 0;

    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\n")] = 0;
        strcpy(level[y], line);
        if ((int)strlen(line) > level_width) {
            level_width = strlen(line);
        }
        y++;
    }

    level_height = y;
    fclose(f);
    return 1;
}

int main() {
    if (!load_level("level.txt"))
        return 1;

    for (int y = 0; y < level_height; y++) {
        printf("%s\n", level[y]);
    }

    return 0;
}