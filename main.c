/*
** MY_HUNTER PROJECT, 2022
** bscsfml
** File description:
** graphical programming
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RectangleShape.h>
#include <stdio.h>


void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
}

sfVector2i manage_mouse_click(sfRenderWindow *window)
{
        sfVector2i mouse;
        sfRenderWindow_display(window);
        mouse = sfMouse_getPositionRenderWindow(window);
        // printf(" x : %d, y : %d\n", mouse.x, mouse.y);
        return mouse;
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased) {
        manage_mouse_click(window);
    }
}

void move_rect(sfIntRect *rect, sfClock *clock)
{
    sfTime time;
    float seconds;
    int max_value = 330;
    int offset = 110;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds/1000000.0;
    //printf("seconds : %f\n", seconds);
    if (seconds > 0.2) {
        rect->left = rect->left + offset;
        sfClock_restart(clock);
    }
    if (rect->left == max_value)
        rect->left = 0;
    //printf("One more second elapsed ...\n");
}

int main(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1536, 865, 32};
    char window_title[] = "My_Hunter";
    sfEvent event;
    sfTexture *texture_bg = sfTexture_createFromFile("src/defaultbg.png", NULL);
    sfTexture *texture_bird = sfTexture_createFromFile("src/bird.png", NULL);
    sfSprite *bg = sfSprite_create();
    sfSprite *bird = sfSprite_create();
    sfVector2f sprite_move = {1, 0};
    sfVector2f size_bg = {2, 2};
    sfVector2f bird_position;
    sfVector2f spawn_sprite = {-250, 0};
    sfClock *clock = sfClock_create();


    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;

    //sfWindow_setFramerateLimit(window, 10); //LIMITE FPS    
    sfSprite_scale(bg, size_bg);
    window = sfRenderWindow_create(video_mode, window_title, sfResize | sfClose, NULL);
    if (!window)
        return (84);
    sfSprite_setTexture(bg, texture_bg, sfTrue);
    sfSprite_setTexture(bird, texture_bird, sfTrue);
    sfSprite_setTextureRect(bird, rect);
    sfSprite_setPosition(bird, spawn_sprite);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event);
            close_window(window, event);
        }
        // sfRenderWindow_clear(window, sfColor_fromRGB(0, 0, 0));
        move_rect(&rect, clock);
        sfSprite_setTextureRect(bird, rect);
        sfSprite_move(bird, sprite_move);
        bird_position = sfSprite_getPosition(bird);
        if (bird_position.x >= 1500) {
            sfSprite_setPosition(bird, spawn_sprite);
        }
        if(manage_mouse_click(window).y > bird_position.y -30 && manage_mouse_click(window).y < bird_position.y + rect.width -30
        && manage_mouse_click(window).x > bird_position.x -30 && manage_mouse_click(window).x < bird_position.x + rect.height -30) {
            sfSprite_setPosition(bird, spawn_sprite);
        }
        sfRenderWindow_drawSprite(window, bg, NULL);
        sfRenderWindow_drawSprite(window, bird, NULL);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(texture_bird);
    sfTexture_destroy(texture_bg);
    sfRenderWindow_destroy(window);
    return 0;
}
