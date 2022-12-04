/*
** MY_HUNTER PROJECT, 2022
** My_Hunter
** File description:
** include
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/RectangleShape.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include "struct.h"

    #define WINDOW ALL->settings.window
    #define EVENT ALL->settings.event

    #define BG_BLUR ALL->texture.bg_blur
    #define TEXTURE_BG_BLUR ALL->texture.texture_bg_blur
    #define START_BTN ALL->texture.start_btn
    #define TEXTURE_START_BTN ALL->texture.texture_start_btn
    #define ECHAP_MENU ALL->texture.echap_menu
    #define TEXTURE_ECHAP_MENU ALL->texture.texture_echap_menu
    #define BG ALL->texture.bg
    #define TEXTURE_BG ALL->texture.texture_bg
    #define METEOR ALL->texture.meteor
    #define TEXTURE_METEOR ALL->texture.texture_meteor
    #define BG_REMOVED ALL->texture.bg_removed
    #define TEXTURE_BG_REMOVED ALL->texture.texture_bg_removed
    #define RECT ALL->sp_rect.rect
    #define RECTANGLE ALL->hitbox.rectangle
    #define LIFE_POINT_1 ALL->texture.life_point_1
    #define TEXTURE_LIFE_POINT_1 ALL->texture.texture_life_point_1
    #define LIFE_POINT_2 ALL->texture.life_point_2
    #define TEXTURE_LIFE_POINT_2 ALL->texture.texture_life_point_2
    #define LIFE_POINT_3 ALL->texture.life_point_3
    #define TEXTURE_LIFE_POINT_3 ALL->texture.texture_life_point_3
    #define LIFE_POINT_POSITION_1 ALL->sp_action.life_point_position_1
    #define LIFE_POINT_POSITION_2 ALL->sp_action.life_point_position_2
    #define LIFE_POINT_POSITION_3 ALL->sp_action.life_point_position_3

    #define SPRITE_MOVE ALL->sp_action.sprite_move
    #define SIZE_BG ALL->sp_action.size_bg
    #define METEOR_POSITION ALL->sp_action.meteor_position
    #define SPAWN_SPRITE ALL->sp_action.spawn_sprite
    #define SPAWN_SPRITE_AFTER ALL->sp_action.spawn_sprite_after

void move_rect(sfIntRect *rect, sfClock *clock);
sfVector2i manage_mouse_click(sfRenderWindow *window);
void close_window(sfRenderWindow *window, sfEvent event);
void analyse_events(sfRenderWindow *window, sfEvent event);
void init(HUNTER_T *ALL);
int flag_h(int ac, char **av);
int my_putstr(char const *str);
void my_putchar(char c);
#endif //include.h
