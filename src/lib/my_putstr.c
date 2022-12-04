/*
** MY_HUNTER PROJECT, 2022
** My_Hunter
** File description:
** my_putstr
*/

#include "../../includes/include.h"

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
