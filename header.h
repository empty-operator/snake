#ifndef SNAKE_HEADER_H
#define SNAKE_HEADER_H

#define HEIGHT 10
#define WIDTH 20

typedef struct {
    int x;
    int y;
} point;

typedef enum {
    UP = 1,
    DOWN,
    LEFT,
    RIGHT
} direction;

typedef enum {
    FIELD = ' ',
    SNAKE = '@',
    FOOD = '*'
} type;

void read_key(void);
void place_food(void);
void init_field(void);
void print_field(void);
bool update_stats(int);
bool update_position(void);

#endif //SNAKE_HEADER_H