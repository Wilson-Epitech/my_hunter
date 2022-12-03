/*
** MY_HUNTER PROJECT, 2022
** My_Hunter
** File description:
** meteor
*/

#include "../includes/include.h"

void move_rect(sfIntRect *rect, sfClock *clock)
{
    sfTime time;
    float seconds;
    int max_value = 330;
    int offset = 110;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    //printf("seconds : %f\n", seconds);
    if (seconds > 0.2) {
        rect->left = rect->left + offset;
        sfClock_restart(clock);
    }
    if (rect->left == max_value)
        rect->left = 0;
    //printf("One more second elapsed ...\n");
}
