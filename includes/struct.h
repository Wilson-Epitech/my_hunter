/*
** MY_HUNTER PROJECT, 2022
** My_Hunter
** File description:
** struct
*/

#include "include.h"

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct WINDOW_GAME {
        sfRenderWindow *window;
        sfVideoMode video_mode;
        sfEvent event;
    } WINDOW_GAME_T;

    typedef struct TEXTURE_GAME {
        sfTexture *texture_start_btn;
        sfSprite *start_btn;
        sfTexture *texture_bg;
        sfSprite *bg;
        sfTexture *texture_meteor;
        sfSprite *meteor;
        sfTexture *texture_bg_removed;
        sfSprite *bg_removed;
        sfTexture *texture_echap_menu;
        sfSprite *echap_menu;
        sfTexture *texture_bg_blur;
        sfSprite *bg_blur;
        sfTexture *texture_life_point_1;
        sfSprite *life_point_1;
        sfTexture *texture_life_point_2;
        sfSprite *life_point_2;
        sfTexture *texture_life_point_3;
        sfSprite *life_point_3;
        sfTexture *texture_no_life_point;
        sfSprite *no_life_point;
        sfTexture *texture_play_menu;
        sfSprite *play_menu;
        sfTexture *texture_rules_menu;
        sfSprite *rules_menu;
        sfTexture *texture_game_over_menu;
        sfSprite *game_over_menu;
        sfTexture *texture_credit_menu;
        sfSprite *credit_menu;
    } TEXTURE_GAME_T;

    typedef struct SPRITE_ACTION {
        sfVector2f sprite_move;
        sfVector2f size_bg;
        sfVector2f size_play_menu_bg;
        sfVector2f size_echap_menu_bg;
        sfVector2f meteor_position;
        sfVector2f life_point_position_1;
        sfVector2f life_point_position_2;
        sfVector2f life_point_position_3;
        sfVector2f spawn_sprite;
        sfVector2f spawn_sprite_after;
    } SPRITE_ACTION_T;

    typedef struct SPRITE_RECT {
        sfIntRect rect;
    } SPRITE_RECT_T;

    typedef struct SPRITE_HITBOX {
        sfRectangleShape *rectangle;
        sfVector2f rectangle_position;
    } SPRITE_HITBOX_T;

    typedef struct HUNTER {
        WINDOW_GAME_T settings;
        TEXTURE_GAME_T texture;
        SPRITE_ACTION_T sp_action;
        SPRITE_RECT_T sp_rect;
        SPRITE_HITBOX_T hitbox;
    } HUNTER_T;

#endif //struct
