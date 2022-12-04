/*
** MY_HUNTER PROJECT, 2022
** My_Hunter
** File description:
** mouse_pos
*/

#include "../includes/include.h"

sfVector2i manage_mouse_click(sfRenderWindow *window)
{
        sfVector2i mouse;
        sfRenderWindow_display(window);
        mouse = sfMouse_getPositionRenderWindow(window);
        return mouse;
}
