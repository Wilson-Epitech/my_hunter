/*
** MY_HUNTER PROJECT, 2022
** My_Hunter
** File description:
** init
*/

#include <unistd.h>
#include "../includes/include.h"
#include "../includes/struct.h"
#define WIN ALL->settings.window
#define MODE ALL->settings.video_mode

void init_window(HUNTER_T *ALL)
{
    MODE.bitsPerPixel= 32;
    MODE.height = 865;
    MODE.width = 1536;
    WIN = sfRenderWindow_create(MODE, "My_Hunter", sfResize | sfClose, NULL);

}

void init_sprite(HUNTER_T *ALL)
{
    ALL->texture.texture_start_btn
        = sfTexture_createFromFile("src/ressources/btn.png", NULL);
    ALL->texture.start_btn = sfSprite_create();
    ALL->texture.texture_bg
        = sfTexture_createFromFile("src/ressources/bg.jpg", NULL);
    ALL->texture.bg = sfSprite_create();
    ALL->texture.texture_meteor
        = sfTexture_createFromFile("src/ressources/meteor.png", NULL);
    ALL->texture.meteor = sfSprite_create();
    ALL->texture.texture_bg_removed
        = sfTexture_createFromFile("src/ressources/bg_gimped.png", NULL);
    ALL->texture.bg_removed = sfSprite_create();
    ALL->texture.texture_echap_menu
        = sfTexture_createFromFile("src/ressources/Echap_Menu2.png", NULL);
    ALL->texture.echap_menu = sfSprite_create();
    ALL->texture.texture_bg_blur
        = sfTexture_createFromFile("src/ressources/bg_blur.jpg", NULL);
    ALL->texture.bg_blur = sfSprite_create();
    ALL->texture.texture_life_point_1
        = sfTexture_createFromFile("src/ressources/one_life_point.png", NULL);
    ALL->texture.life_point_1 = sfSprite_create();
    ALL->texture.texture_life_point_2
        = sfTexture_createFromFile("src/ressources/one_life_point.png", NULL);
    ALL->texture.life_point_2 = sfSprite_create();
    ALL->texture.texture_life_point_3
        = sfTexture_createFromFile("src/ressources/one_life_point.png", NULL);
    ALL->texture.life_point_3 = sfSprite_create();
    ALL->texture.texture_no_life_point
        = sfTexture_createFromFile("src/ressources/no_life_point.png", NULL);
    ALL->texture.no_life_point = sfSprite_create();
    ALL->texture.texture_play_menu
        = sfTexture_createFromFile("src/ressources/play_menu_bg.png", NULL);
    ALL->texture.play_menu = sfSprite_create();
    ALL->texture.texture_rules_menu
        = sfTexture_createFromFile("src/ressources/rules_menu.png", NULL);
    ALL->texture.rules_menu = sfSprite_create();
    ALL->texture.texture_game_over_menu
        = sfTexture_createFromFile("src/ressources/game_over_menu.png", NULL);
    ALL->texture.game_over_menu = sfSprite_create();
    ALL->texture.texture_credit_menu
        = sfTexture_createFromFile("src/ressources/credits_menu.png", NULL);
    ALL->texture.credit_menu = sfSprite_create();
}

void init_sprite_action(HUNTER_T *ALL)
{
    ALL->sp_action.sprite_move.x = 11;
    ALL->sp_action.sprite_move.y = 12;
    ALL->sp_action.size_bg.x = 0.8;
    ALL->sp_action.size_bg.y = 1;
    ALL->sp_action.size_play_menu_bg.x = 0.75;
    ALL->sp_action.size_play_menu_bg.y = 0.75;
    ALL->sp_action.size_echap_menu_bg.x = 0.90;
    ALL->sp_action.size_echap_menu_bg.y = 0.80;

    ALL->sp_action.meteor_position.x;
    ALL->sp_action.meteor_position.y;
    ALL->sp_action.life_point_position_1.x = 0;
    ALL->sp_action.life_point_position_1.y = 830;
    ALL->sp_action.life_point_position_2.x = 50;
    ALL->sp_action.life_point_position_2.y = 830;
    ALL->sp_action.life_point_position_3.x = 100;
    ALL->sp_action.life_point_position_3.y = 830;
    ALL->sp_action.spawn_sprite.x = 0;
    ALL->sp_action.spawn_sprite.y = 0;
    ALL->sp_action.spawn_sprite_after.x = rand() % 800;
    ALL->sp_action.spawn_sprite_after.y = -250;
}

void init_rect(HUNTER_T *ALL)
{
        ALL->sp_rect.rect.top = 0;
        ALL->sp_rect.rect.left = 0;
        ALL->sp_rect.rect.width = 95;
        ALL->sp_rect.rect.height = 195;
}

void init_struct(HUNTER_T *ALL)
{
    srand(time(NULL));
    sfSprite_scale(ALL->texture.bg, ALL->sp_action.size_bg);
    sfSprite_scale(ALL->texture.bg_removed, ALL->sp_action.size_bg);
    sfSprite_scale(ALL->texture.play_menu, ALL->sp_action.size_play_menu_bg);
    sfSprite_scale(ALL->texture.rules_menu, ALL->sp_action.size_play_menu_bg);
    sfSprite_scale(ALL->texture.echap_menu, ALL->sp_action.size_echap_menu_bg);
    sfSprite_scale(ALL->texture.game_over_menu,
                   ALL->sp_action.size_play_menu_bg);
    sfSprite_scale(ALL->texture.credit_menu, ALL->sp_action.size_play_menu_bg);               
    sfSprite_setTexture(ALL->texture.bg_blur,
                        ALL->texture.texture_bg_blur, sfTrue);
    sfSprite_setTexture(ALL->texture.start_btn,
                        ALL->texture.texture_start_btn, sfTrue);
    sfSprite_setTexture(ALL->texture.echap_menu,
                        ALL->texture.texture_echap_menu, sfTrue);
    sfSprite_setTexture(ALL->texture.bg, ALL->texture.texture_bg, sfTrue);
    sfSprite_setTexture(ALL->texture.meteor,
                        ALL->texture.texture_meteor, sfTrue);
    sfSprite_setTexture(ALL->texture.credit_menu,
                        ALL->texture.texture_credit_menu, sfTrue);
    sfSprite_setTexture(ALL->texture.bg_removed,
                        ALL->texture.texture_bg_removed, sfTrue);
    sfSprite_setTextureRect(ALL->texture.meteor, ALL->sp_rect.rect);
    sfSprite_setPosition(ALL->texture.meteor, ALL->sp_action.spawn_sprite);

    sfSprite_setTexture(ALL->texture.play_menu,
                        ALL->texture.texture_play_menu, sfTrue);
    sfSprite_setTexture(ALL->texture.rules_menu,
                        ALL->texture.texture_rules_menu, sfTrue);
    sfSprite_setTexture(BG_BLUR, TEXTURE_BG_BLUR, sfTrue);
    sfSprite_setTexture(START_BTN, TEXTURE_START_BTN, sfTrue);
    sfSprite_setTexture(ECHAP_MENU, TEXTURE_ECHAP_MENU, sfTrue);
    sfSprite_setTexture(BG, TEXTURE_BG, sfTrue);
    sfSprite_setTexture(METEOR, TEXTURE_METEOR, sfTrue);
    sfSprite_setTexture(BG_REMOVED, TEXTURE_BG_REMOVED, sfTrue);
    sfSprite_setTexture(ALL->texture.game_over_menu,
                        ALL->texture.texture_game_over_menu, sfTrue);
    sfSprite_setTexture(LIFE_POINT_1, TEXTURE_LIFE_POINT_1, sfTrue);
    sfSprite_setTexture(LIFE_POINT_2, TEXTURE_LIFE_POINT_2, sfTrue);
    sfSprite_setTexture(LIFE_POINT_3, TEXTURE_LIFE_POINT_3, sfTrue);
    sfSprite_setPosition(LIFE_POINT_1, LIFE_POINT_POSITION_1);
    sfSprite_setPosition(LIFE_POINT_2, LIFE_POINT_POSITION_2);
    sfSprite_setPosition(LIFE_POINT_3, LIFE_POINT_POSITION_3);
}

int init_hitbox(HUNTER_T *ALL)
{
    ALL->hitbox.rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(ALL->hitbox.rectangle, (sfVector2f){60, 60});
    sfRectangleShape_setOutlineColor(ALL->hitbox.rectangle,
                                     sfColor_fromRGBA(218, 66, 66, 0.5));
    sfRectangleShape_setOutlineThickness(ALL->hitbox.rectangle, 5);
    sfRectangleShape_setFillColor(ALL->hitbox.rectangle,
                                  sfColor_fromRGBA(0, 0, 0, 0));
    sfSprite_setPosition(ALL->hitbox.rectangle, ALL->hitbox.rectangle_position);
    ALL->hitbox.rectangle_position.x = 0;
    ALL->hitbox.rectangle_position.y = 0;
}

void init(HUNTER_T *ALL)
{
    init_window(ALL);
    init_sprite(ALL);
    init_sprite_action(ALL);
    init_rect(ALL);
    init_struct(ALL);
    init_hitbox(ALL);
}

