#include <stdio.h>
#include <stdbool.h>

bool update_stats(int new) {
    FILE *f = fopen("stats.dat", "rb");
    if (f == NULL) {
        f = fopen("stats.dat", "w+b");
        fwrite(&new, sizeof(int), 1, f);
        fclose(f);
        return true;
    }
    int old;
    fread(&old, sizeof(int), 1, f);
    if (new > old) {
        fclose(f);
        f = fopen("stats.dat", "w+b");
        fwrite(&new, sizeof(int), 1, f);
        fclose(f);
        return true;
    } else {
        printf_s("Найкращий результат: %d\n", old);
        fclose(f);
        return false;
    }
}
