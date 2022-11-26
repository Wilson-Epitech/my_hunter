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
{e
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
}

void manage_mouse_click(sfRenderWindow *window)
{
        sfVector2i mouse;
        sfRenderWindow_display(window);
        mouse = sfMouse_getPositionRenderWindow(window);
        printf(" x : %d, y : %d\n", mouse.x, mouse.y);
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased) {
        manage_mouse_click(window);
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value, sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds/1000000.0;
    //printf("seconds : %f\n", seconds);
    if (seconds > 1.0) {
    rect->left = rect->left + offset;
    sfClock_restart(clock);
    }
    if (rect->left == max_value)
        rect->left = 0;
    //printf("One more second elapsed ...\n");
}

int main(void)
{
    int i = 0;
    sfRenderWindow *window;
    sfVideoMode video_mode = {1536, 865, 32};
    char window_title[] = "My_Hunter";
    sfEvent event;
    sfTexture *texture_bg = sfTexture_createFromFile("src/defaultbg.png", NULL);
    sfTexture *texture_bird = sfTexture_createFromFile("src/bird.png", NULL);
    sfSprite *bg = sfSprite_create();
    sfSprite *bird = sfSprite_create();
    sfVector2f size_bg = {2, 2};
    sfVector2f bird_position = sfSprite_getPosition(bird);
    sfClock *clock = sfClock_create();
    int max_value = 330;
    int offset = 110;

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
    while (sfRenderWindow_isOpen(window)) {
        sfSprite_setTextureRect(bird, rect); 
        //sfRenderWindow_clear(window, sfColor_fromRGB(0, 0, 0));
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, bg, NULL);
        sfRenderWindow_drawSprite(window, bird, NULL);
        move_rect(&rect, offset, max_value, clock);
        bird_position.x = i++; 
        sfSprite_setPosition(bird, bird_position);
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event);
            close_window(window, event);
        }
    }
    sfRenderWindow_destroy(window);
    return 0;
}
