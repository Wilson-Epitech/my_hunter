/*
** MY_HUNTER PROJECT, 2022
** bscsfml
** File description:
** graphical programming
*/

#include "includes/include.h"
#include "includes/struct.h"

void move_rect(sfIntRect *rect, sfClock *clock)
{
    sfTime time;
    float seconds;
    int max_value = 300;
    int offset = 150;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    //printf("seconds : %f\n", seconds);
    if (seconds > 0.2) {
        rect->left = rect->left + offset;
        sfClock_restart(clock);
    }
    if (rect->left == max_value)
        rect->left = 0;
    printf("One more second elapsed ...\n");
}

void game_loop(HUNTER_T *ALL)
{
    int state = 0;
    sfClock *clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(WINDOW, 120);
    sfSprite_setTexture(BG_BLUR, TEXTURE_BG_BLUR, sfTrue);
    sfSprite_setTexture(START_BTN, TEXTURE_START_BTN, sfTrue);
    sfSprite_setTexture(ECHAP_MENU, TEXTURE_ECHAP_MENU, sfTrue);
    sfSprite_setTexture(BG, TEXTURE_BG, sfTrue);
    sfSprite_setTexture(METEOR, TEXTURE_METEOR, sfTrue);
    sfSprite_setTexture(BG_REMOVED, TEXTURE_BG_REMOVED, sfTrue);
    sfSprite_setTexture(LIFE_POINT_1, TEXTURE_LIFE_POINT_1, sfTrue);
    sfSprite_setTexture(LIFE_POINT_2, TEXTURE_LIFE_POINT_2, sfTrue);
    sfSprite_setTexture(LIFE_POINT_3, TEXTURE_LIFE_POINT_3, sfTrue);
    sfSprite_setPosition(LIFE_POINT_1, LIFE_POINT_POSITION_1);
    sfSprite_setPosition(LIFE_POINT_2, LIFE_POINT_POSITION_2);
    sfSprite_setPosition(LIFE_POINT_3, LIFE_POINT_POSITION_3);
    // sfSprite_setTexture(ALL->texture.no_life_point, ALL->texture.texture_no_life_point, sfTrue);
    sfSprite_setTexture(ALL->texture.play_menu, ALL->texture.texture_play_menu, sfTrue);
    sfSprite_setTexture(ALL->texture.rules_menu, ALL->texture.texture_rules_menu, sfTrue);
    sfSprite_setTextureRect(METEOR, RECT);
    sfSprite_setPosition(METEOR, SPAWN_SPRITE);
    sfSprite_setPosition(RECTANGLE, (sfVector2f) {SPAWN_SPRITE.x + 30, SPAWN_SPRITE.y + 135});
     // sfSprite_setPosition(RECTANGLE, (sfVector2f) {SPAWN_SPRITE_AFTER.x + 15, SPAWN_SPRITE_AFTER.y + 135}); FOR SPRITE "METEOR SPRITE 1"
    while (sfRenderWindow_isOpen(WINDOW)) {
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT)) {
            analyse_events(WINDOW, EVENT);
            close_window(WINDOW, EVENT);
            if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyEscape && state == 1) {
                state = 5;
            }
        }
        if (state == 0) {
                sfRenderWindow_clear(WINDOW, sfColor_fromRGB(0, 0, 0));
                sfRenderWindow_drawSprite(WINDOW, ALL->texture.play_menu, NULL);
            if(EVENT.type == sfEvtMouseButtonPressed && manage_mouse_click(WINDOW).y > 302  && manage_mouse_click(WINDOW).y < 371
            && manage_mouse_click(WINDOW).x > 124 && manage_mouse_click(WINDOW).x < 427) {
                state = 1;
            }
            if(EVENT.type == sfEvtMouseButtonPressed && manage_mouse_click(WINDOW).y > 394  && manage_mouse_click(WINDOW).y < 464
            && manage_mouse_click(WINDOW).x > 124 && manage_mouse_click(WINDOW).x < 427) {
                state = 2;
            }
            if(EVENT.type == sfEvtMouseButtonPressed && manage_mouse_click(WINDOW).y > 490  && manage_mouse_click(WINDOW).y < 558
            && manage_mouse_click(WINDOW).x > 124 && manage_mouse_click(WINDOW).x < 427) {
                state = 3;
            }
            if(EVENT.type == sfEvtMouseButtonPressed && manage_mouse_click(WINDOW).y > 582  && manage_mouse_click(WINDOW).y < 651
            && manage_mouse_click(WINDOW).x > 124 && manage_mouse_click(WINDOW).x < 427) {
                state = 4;
            }
        }
        if (state == 1) {
            sfVector2f pos = sfShape_getPosition(RECTANGLE);
            sfVector2f pos_after;
            printf("x : %d y : %d\n", manage_mouse_click(WINDOW).x, manage_mouse_click(WINDOW).y);
        
            if(EVENT.type == sfEvtMouseButtonPressed && manage_mouse_click(WINDOW).y > pos.y  && manage_mouse_click(WINDOW).y < pos.y + 60
            && manage_mouse_click(WINDOW).x > pos.x  && manage_mouse_click(WINDOW).x < pos.x + 60) {
                    // spawn_sprite_after.x = rand() % 1500;
                    pos_after = (sfVector2f){rand() % 800, -250};
                    sfSprite_setPosition(METEOR, pos_after);
                    sfSprite_setPosition(RECTANGLE, (sfVector2f){pos_after.x +30, pos_after.y + 130});
                    printf("x : %f y : %f\n", SPAWN_SPRITE_AFTER.x, SPAWN_SPRITE_AFTER.y);
            }
            // move_rect(&RECT, clock);
            sfSprite_setTextureRect(METEOR, RECT);
            sfSprite_move(METEOR, SPRITE_MOVE);
            sfSprite_move(RECTANGLE, SPRITE_MOVE);
            METEOR_POSITION = sfSprite_getPosition(METEOR);
            if (METEOR_POSITION.y >= 860) {
                METEOR_POSITION.y = -250;
                SPAWN_SPRITE_AFTER.x = rand() % 1500;
                SPRITE_MOVE.x = -1;
                SPRITE_MOVE.y = 2;
                sfSprite_setPosition(METEOR, SPAWN_SPRITE_AFTER);
                sfSprite_setPosition(RECTANGLE, (sfVector2f) {SPAWN_SPRITE_AFTER.x + 30, SPAWN_SPRITE_AFTER.y + 130});
                sfSprite_setPosition(ALL->texture.life_point_1, (sfVector2f) {1800, 1800});
            }
            sfRenderWindow_clear(WINDOW, sfColor_fromRGB(0, 0, 0));
            sfRenderWindow_drawSprite(WINDOW, BG, NULL);
            sfRenderWindow_drawSprite(WINDOW, METEOR, NULL);
            sfRenderWindow_drawRectangleShape(WINDOW, RECTANGLE, NULL);
            sfRenderWindow_drawSprite(WINDOW, BG_REMOVED, NULL);
            // sfRenderWindow_drawSprite(WINDOW, START_BTN, NULL);
            sfRenderWindow_drawSprite(WINDOW, ALL->texture.life_point_1, NULL);
            sfRenderWindow_drawSprite(WINDOW, ALL->texture.life_point_2, NULL);
            sfRenderWindow_drawSprite(WINDOW, ALL->texture.life_point_3, NULL);
        }
        if (state == 2) {
            exit(1);
        }
        printf("x : %d y : %d\n", manage_mouse_click(WINDOW).x, manage_mouse_click(WINDOW).y);
        if (state == 3) {
            sfRenderWindow_clear(WINDOW, sfColor_fromRGB(0, 0, 0));
            sfRenderWindow_drawSprite(WINDOW, ALL->texture.rules_menu, NULL);
            if(EVENT.type == sfEvtMouseButtonPressed && manage_mouse_click(WINDOW).y > 718  && manage_mouse_click(WINDOW).y < 789
            && manage_mouse_click(WINDOW).x > 125 && manage_mouse_click(WINDOW).x < 426) {
                state = 0;
                printf("OK\n");
            }
        }
        if (state == 4) {
            exit(1);
        }
        if (state == 5) {
            sfRenderWindow_clear(WINDOW, sfColor_fromRGB(0, 0, 0));
            sfRenderWindow_drawSprite(WINDOW, ECHAP_MENU, NULL);
            if(EVENT.type == sfEvtMouseButtonPressed && manage_mouse_click(WINDOW).y > 214  && manage_mouse_click(WINDOW).y < 279
            && manage_mouse_click(WINDOW).x > 625 && manage_mouse_click(WINDOW).x < 945) {
                state = 1;
            }
            if(EVENT.type == sfEvtMouseButtonPressed && manage_mouse_click(WINDOW).y > 388  && manage_mouse_click(WINDOW).y < 454
            && manage_mouse_click(WINDOW).x > 625 && manage_mouse_click(WINDOW).x < 945) {
                state = 0;
            }
                if(EVENT.type == sfEvtMouseButtonPressed && manage_mouse_click(WINDOW).y > 555  && manage_mouse_click(WINDOW).y < 630
            && manage_mouse_click(WINDOW).x > 625 && manage_mouse_click(WINDOW).x < 945) {
                exit(1);
            }
            if(EVENT.type == sfEvtMouseButtonPressed && manage_mouse_click(WINDOW).y > 716  && manage_mouse_click(WINDOW).y < 762
            && manage_mouse_click(WINDOW).x > 42 && manage_mouse_click(WINDOW).x < 295) {
                    sfRectangleShape_setOutlineColor(ALL->hitbox.rectangle, sfColor_fromRGB(218, 66, 66));
                    state = 1;
            }
            if(EVENT.type == sfEvtMouseButtonPressed && manage_mouse_click(WINDOW).y > 810  && manage_mouse_click(WINDOW).y < 856
            && manage_mouse_click(WINDOW).x > 42 && manage_mouse_click(WINDOW).x < 295) {
                    sfRectangleShape_setOutlineColor(ALL->hitbox.rectangle, sfColor_fromRGBA(218, 66, 66, 0.5));
                    state = 1;
            }
        }
        sfRenderWindow_display(WINDOW);
    }
    sfTexture_destroy(TEXTURE_METEOR);
    sfTexture_destroy(TEXTURE_BG);
    sfTexture_destroy(TEXTURE_BG_REMOVED);
    sfRenderWindow_destroy(WINDOW);
}

int main(void)
{
    HUNTER_T ALL;
    init(&ALL);
    game_loop(&ALL);
}