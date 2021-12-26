#include "control.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>

int updatePoints(int *points, float period, float amp)
{
    for (int i = 0; i < WINDOW_WIDTH; ++i)
    {
        points[i] = WINDOW_HIGHT - (sin(i / period) * amp + amp);
        // printf("pre round:%f \n", (sin(i / 10) * 50 + 50));
        // printf("post round:%d \n", (int)((sin(i / 10) * 50 + 50)));
    }
}

int doInput(SDL_Event event, int *keyDown, float *period, float *amp)
{
    switch (event.type)
    {
    case SDL_KEYDOWN:
        if (!*keyDown)
        {
            printf("key = %d\n", event.key.keysym.sym);
            switch (event.key.keysym.sym)
            {
            case SDLK_w:
                *amp += 5;
                break;
            case SDLK_s:
                *amp -= 5;
                break;
            case SDLK_d:
                *period += 5;
                break;
            case SDLK_a:
                *period -= 5;
                break;
            default:
                break;
            }
        }

        *keyDown = 1;
        break;

    case SDL_KEYUP:
        // printf("Key release detected\n");
        *keyDown = 0;
        break;

    default:
        break;
    }
}