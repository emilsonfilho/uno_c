#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

typedef enum
{
    RED,
    GREEN,
    BLUE,
    YELLOW,
    WILD,
} Color;

typedef union
{
    unsigned int number;
    char action[8];
} NumberAction;

typedef struct
{
    Color color;
    NumberAction numberAction;
    bool isNumber;
} Card;

extern char *color_mapper[];

#endif