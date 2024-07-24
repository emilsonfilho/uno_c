#ifndef TYPES_H
#define TYPES_H

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

char *color_mapper[] = {
    "Vermelho",
    "Verde",
    "Azul",
    "Amarelo",
    "Especial"};

#endif // TYPES_H