/*
** MY_HUNTER PROJECT, 2022
** bscsfml
** File description:
** graphical programming
*/

#include "includes/include.h"
#include "includes/struct.h"
#include <SFML/Audio.h>

int flag_h(int ac, char **av)
{
    const char *flag_h_info = "\n Hi\n this is my game,\n you can find as a menu: play menu, escape menu (in game), game over menu(after losing the game).\n Good game and good luck\n\n";

    if (ac == 2 && ( av[1][0] == '-' || av[1][1] == 'h')) {
        my_putstr(flag_h_info);
        return (0);
    }
}

void move_rect(sfIntRect *rect, sfClock *clock)
{
    sfTime time;
    float seconds;
    int max_value = 300;
    int offset = 150;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.2) {
        rect->left = rect->left + offset;
        sfClock_restart(clock);
    }
    if (rect->left == max_value)
        rect->left = 0;
}

void game_loop(HUNTER_T *ALL, sfMusic* music)
{
    int game_state = 0;
    int life_state = 4;
    sfClock *clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(WINDOW, 120);

    sfSprite_setTextureRect(METEOR, RECT);
    sfSprite_setPosition(METEOR, SPAWN_SPRITE);
    sfSprite_setPosition(RECTANGLE,
                      (sfVector2f) {SPAWN_SPRITE.x + 30, SPAWN_SPRITE.y + 135});
    while (sfRenderWindow_isOpen(WINDOW)) {
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT)) {
            analyse_events(WINDOW, EVENT);
            close_window(WINDOW, EVENT);
            if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyEscape
                && game_state == 1) {
                game_state = 5;
            }
        }
        if (game_state == 0) {
                sfRenderWindow_clear(WINDOW, sfColor_fromRGB(0, 0, 0));
                sfRenderWindow_drawSprite(WINDOW, ALL->texture.play_menu, NULL);
            if (EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > 302
               && manage_mouse_click(WINDOW).y < 371
               && manage_mouse_click(WINDOW).x > 124
               && manage_mouse_click(WINDOW).x < 427) {
                game_state = 1;
            }
            if (EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > 394
               && manage_mouse_click(WINDOW).y < 464
               && manage_mouse_click(WINDOW).x > 124
               && manage_mouse_click(WINDOW).x < 427) {
                game_state = 2;
            }
            if (EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > 490
               && manage_mouse_click(WINDOW).y < 558
               && manage_mouse_click(WINDOW).x > 124
               && manage_mouse_click(WINDOW).x < 427) {
                game_state = 3;
            }
            if (EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > 582
               && manage_mouse_click(WINDOW).y < 651
               && manage_mouse_click(WINDOW).x > 124
               && manage_mouse_click(WINDOW).x < 427) {
                game_state = 4;
            }
        }
        if (game_state == 1) {
            sfVector2f pos = sfShape_getPosition(RECTANGLE);
            sfVector2f pos_after;

            if(EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > pos.y
               && manage_mouse_click(WINDOW).y < pos.y + 60
               && manage_mouse_click(WINDOW).x > pos.x
               && manage_mouse_click(WINDOW).x < pos.x + 60) {
                    pos_after = (sfVector2f){rand() % 800, -250};
                    sfSprite_setPosition(METEOR, pos_after);
                    sfSprite_setPosition(RECTANGLE,
                              (sfVector2f){pos_after.x +30, pos_after.y + 130});
                    SPRITE_MOVE.x = SPRITE_MOVE.x + 0.5;
                SPRITE_MOVE.y = SPRITE_MOVE.y + 0.5;
            }
            // move_rect(&RECT, clock);
            sfSprite_setTextureRect(METEOR, RECT);
            sfSprite_move(METEOR, SPRITE_MOVE);
            sfSprite_move(RECTANGLE, SPRITE_MOVE);
            METEOR_POSITION = sfSprite_getPosition(METEOR);
            if (METEOR_POSITION.y >= 860 || METEOR_POSITION.x < -85
                || METEOR_POSITION.x > 1583) {
                METEOR_POSITION.y = -250;
                SPAWN_SPRITE_AFTER.x = rand() % 800;
                sfSprite_setPosition(METEOR, SPAWN_SPRITE_AFTER);
                sfSprite_setPosition(RECTANGLE, (sfVector2f)
                       {SPAWN_SPRITE_AFTER.x + 30, SPAWN_SPRITE_AFTER.y + 130});

                sfVector2f pos_life_1 = {1800, 1800};
                sfVector2f pos_life_2;
                sfVector2f pos_life_3;
                pos_life_2 = (sfVector2f){1810, 1800};
                pos_life_3 = (sfVector2f){1820, 1800};
                if ((METEOR_POSITION.y >= 860)
                    || (METEOR_POSITION.x > -85 && METEOR_POSITION.x < 2000)
                    || (METEOR_POSITION.x > 1583)) {
                        life_state--;
                }
                if (life_state == 3)
                    sfSprite_setPosition(ALL->texture.life_point_1, pos_life_1);
                if (life_state == 2)
                    sfSprite_setPosition(ALL->texture.life_point_2, pos_life_2);
                if (life_state == 1) {
                    sfSprite_setPosition(ALL->texture.life_point_3, pos_life_3);
                }
                if (life_state == 0) {
                    game_state = 6;
                }
            }
            sfRenderWindow_clear(WINDOW, sfColor_fromRGB(0, 0, 0));
            sfRenderWindow_drawSprite(WINDOW, BG, NULL);
            sfRenderWindow_drawSprite(WINDOW, METEOR, NULL);
            sfRenderWindow_drawRectangleShape(WINDOW, RECTANGLE, NULL);
            sfRenderWindow_drawSprite(WINDOW, BG_REMOVED, NULL);
            sfRenderWindow_drawSprite(WINDOW, ALL->texture.life_point_1, NULL);
            sfRenderWindow_drawSprite(WINDOW, ALL->texture.life_point_2, NULL);
            sfRenderWindow_drawSprite(WINDOW, ALL->texture.life_point_3, NULL);
        }
        if (game_state == 2) {
            exit(1);
        }
        write(manage_mouse_click(WINDOW).x);
        write(manage_mouse_click(WINDOW).y);
        if (game_state == 3) {
            sfRenderWindow_clear(WINDOW, sfColor_fromRGB(0, 0, 0));
            sfRenderWindow_drawSprite(WINDOW, ALL->texture.rules_menu, NULL);
            if (EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > 718
               && manage_mouse_click(WINDOW).y < 789
               && manage_mouse_click(WINDOW).x > 125
               && manage_mouse_click(WINDOW).x < 426) {
                game_state = 0;
            }
        }
        if (game_state == 4) {
            sfRenderWindow_clear(WINDOW, sfColor_fromRGB(0, 0, 0));
            sfRenderWindow_drawSprite(WINDOW, ALL->texture.credit_menu, NULL);
        if (EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > 718
               && manage_mouse_click(WINDOW).y < 789
               && manage_mouse_click(WINDOW).x > 125
               && manage_mouse_click(WINDOW).x < 426) {
                game_state = 0;
            }
        }
        if (game_state == 5) {
            sfRenderWindow_clear(WINDOW, sfColor_fromRGB(0, 0, 0));
            sfRenderWindow_drawSprite(WINDOW, ECHAP_MENU, NULL);
            if (EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > 214
               && manage_mouse_click(WINDOW).y < 279
               && manage_mouse_click(WINDOW).x > 625
               && manage_mouse_click(WINDOW).x < 945) {
                game_state = 1;
            }
            if (EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > 388
               && manage_mouse_click(WINDOW).y < 454
               && manage_mouse_click(WINDOW).x > 625
               && manage_mouse_click(WINDOW).x < 945) {
                game_state = 0;
            }
            if (EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > 555
               && manage_mouse_click(WINDOW).y < 630
               && manage_mouse_click(WINDOW).x > 625
               && manage_mouse_click(WINDOW).x < 945) {
                exit(1);
            }
            if (EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > 716
               && manage_mouse_click(WINDOW).y < 762
               && manage_mouse_click(WINDOW).x > 42
               && manage_mouse_click(WINDOW).x < 295) {
                    sfRectangleShape_setOutlineColor(ALL->hitbox.rectangle,
                                                 sfColor_fromRGB(218, 66, 66));
                    game_state = 1;
            }
            if (EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > 810
               && manage_mouse_click(WINDOW).y < 856
               && manage_mouse_click(WINDOW).x > 42
               && manage_mouse_click(WINDOW).x < 295) {
                    sfRectangleShape_setOutlineColor(ALL->hitbox.rectangle,
                                           sfColor_fromRGBA(218, 66, 66, 0.5));
                    game_state = 1;
            }
        }
        if (game_state == 6) {
            sfRenderWindow_clear(WINDOW, sfColor_fromRGB(0, 0, 0));
            sfMusic_stop(music);
            sfRenderWindow_drawSprite(WINDOW, ALL->texture.game_over_menu, NULL);
            if (EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > 609
               && manage_mouse_click(WINDOW).y < 681
               && manage_mouse_click(WINDOW).x > 82
               && manage_mouse_click(WINDOW).x < 387) {
                game_state = 0;
            }
            if (EVENT.type == sfEvtMouseButtonPressed
               && manage_mouse_click(WINDOW).y > 723
               && manage_mouse_click(WINDOW).y < 790
               && manage_mouse_click(WINDOW).x > 82
               && manage_mouse_click(WINDOW).x < 387) {
                exit(1);
            }
        }
        sfRenderWindow_display(WINDOW);
    }
    sfTexture_destroy(TEXTURE_METEOR);
    sfTexture_destroy(TEXTURE_BG);
    sfTexture_destroy(TEXTURE_BG_REMOVED);
    sfRenderWindow_destroy(WINDOW);
}

int main(int ac, char **av, int game_state)
{
    flag_h(ac, av);
    sfMusic* music;
    music = sfMusic_createFromFile("src/ressources/The-suspense-_1_.ogg");
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    if (ac == 1) {
        HUNTER_T ALL;
        init(&ALL);
        game_loop(&ALL, music);
    }
}
