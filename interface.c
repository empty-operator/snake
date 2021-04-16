#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "header.h"

extern int field[HEIGHT][WIDTH];
extern direction snake_direction;
extern point apple;

void print_field(void) {
    system("cls");
    printf_s(" ╔");
    for (int i = 0; i < WIDTH; ++i) printf_s("═");
    printf_s("╗\n");
    for (int i = 0; i < HEIGHT; ++i) {
        printf_s(" ║");
        for (int j = 0; j < WIDTH; ++j) {
            if (i == apple.x && j == apple.y)
                printf_s("%c", FOOD);
            else if (field[i][j])
                printf_s("%c", SNAKE);
            else
                printf_s("%c", FIELD);
        }
        puts("║");
    }
    printf_s(" ╚");
    for (int i = 0; i < WIDTH; ++i) printf_s("═");
    printf_s("╝\n");
}

void read_key(void) {
    if (GetAsyncKeyState(VK_LEFT) & 0x0001 && snake_direction != RIGHT)
        snake_direction = LEFT;
    else if (GetAsyncKeyState(VK_UP) & 0x0001 && snake_direction != DOWN)
        snake_direction = UP;
    else if (GetAsyncKeyState(VK_RIGHT) & 0x0001 && snake_direction != LEFT)
        snake_direction = RIGHT;
    else if (GetAsyncKeyState(VK_DOWN) & 0x0001 && snake_direction != UP)
        snake_direction = DOWN;
}
