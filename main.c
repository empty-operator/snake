#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "header.h"

extern HANDLE hStdin;
extern DWORD fdwSaveOldMode;
extern int score;

int main() {
    system("chcp 65001");
    init_field();
    print_field();
    while (true) {
        Sleep(200);
        read_key();
        if (update_position())
            break;
        print_field();
    }
    printf_s("Ви програли.\n"
             "Ваш результат: %d\n", score);
    if (update_stats(score))
        printf_s("Новий рекорд!\n");
    SetConsoleMode(hStdin, fdwSaveOldMode);
    getchar(); getchar();
    return 0;
}
