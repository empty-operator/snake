#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "header.h"

HANDLE hStdin;
DWORD fdwSaveOldMode;
int score, field[HEIGHT][WIDTH];
point head, tail, apple;
direction snake_direction;

void init_field(void) {
    DWORD fdwMode;
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    GetConsoleMode(hStdin, &fdwSaveOldMode);
    SetConsoleMode(hStdin, fdwMode);
    srand(time(NULL));
    head.x = rand() % (HEIGHT - 6) + 3, head.y = rand() % (WIDTH - 6) + 3;
    field[head.x][head.y] = true;
    switch (rand() % 4) {
        case 0:
            field[head.x][head.y + 1] = LEFT;
            tail.x = head.x; tail.y = head.y + 2;
            field[tail.x][tail.y] = LEFT;
            snake_direction = LEFT;
            break;
        case 1:
            field[head.x + 1][head.y] = UP;
            tail.x = head.x + 2; tail.y = head.y;
            field[tail.x][tail.y] = UP;
            snake_direction = UP;
            break;
        case 2:
            field[head.x][head.y - 1] = RIGHT;
            tail.x = head.x; tail.y = head.y - 2;
            field[tail.x][tail.y] = RIGHT;
            snake_direction = RIGHT;
            break;
        case 3:
            field[head.x - 1][head.y] = DOWN;
            tail.x = head.x - 2; tail.y = head.y;
            field[tail.x][tail.y] = DOWN;
            snake_direction = DOWN;
            break;
    }
    place_food();
}

bool update_position(void) {
    switch (snake_direction) {
        case RIGHT:
            if (head.y + 1 == WIDTH || field[head.x][head.y + 1])
                return true;
            field[head.x][head.y] = RIGHT;
            field[head.x][++head.y] = true;
            break;
        case DOWN:
            if (head.x + 1 == HEIGHT || field[head.x + 1][head.y])
                return true;
            field[head.x][head.y] = DOWN;
            field[++head.x][head.y] = true;
            break;
        case LEFT:
            if (head.y - 1 < 0 || field[head.x][head.y - 1])
                return true;
            field[head.x][head.y] = LEFT;
            field[head.x][--head.y] = true;
            break;
        case UP:
            if (head.x - 1 < 0 || field[head.x - 1][head.y])
                return true;
            field[head.x][head.y] = UP;
            field[--head.x][head.y] = true;
            break;
    }
    if (head.x == apple.x && head.y == apple.y) {
        place_food();
        ++score;
    } else
        switch ((int) field[tail.x][tail.y]) {
            case RIGHT:
                field[tail.x][tail.y++] = false;
                break;
            case DOWN:
                field[tail.x++][tail.y] = false;
                break;
            case LEFT:
                field[tail.x][tail.y--] = false;
                break;
            case UP:
                field[tail.x--][tail.y] = false;
                break;
        }
    return false;
}

void place_food(void) {
    do {
        apple.x = rand() % HEIGHT;
        apple.y = rand() % WIDTH;
    } while (field[apple.x][apple.y]);
}
