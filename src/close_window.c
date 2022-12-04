/*
** MY_HUNTER PROJECT, 2022
** My_Hunter
** File description:
** close_window
*/

#include "../includes/include.h"

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ)
        sfRenderWindow_close(window);
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased) {
        manage_mouse_click(window);
    }
}
