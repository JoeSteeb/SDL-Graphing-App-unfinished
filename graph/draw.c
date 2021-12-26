#include <SDL2/SDL.h>
#include "draw.h"

int drawFunct(SDL_Renderer *renderer, SDL_Event event, int *points, int connect)
{
    int i;
    if (!connect)
    {
        for (i = 0; i < WINDOW_WIDTH; ++i)
            if (points[i] < WINDOW_HIGHT)
                SDL_RenderDrawPoint(renderer, i, points[i]);
    }
    else
    {
        int reserve[2];
        reserve[0] = 0;
        reserve[1] = points[0];
        for (i = 1; i < WINDOW_WIDTH; ++i)
        {
            if (points[i] < WINDOW_HIGHT)
            {
                SDL_RenderDrawLine(renderer, reserve[0], reserve[1], i, points[i]);
                reserve[0] = i;
                reserve[1] = points[i];
            }
        }
    }
}