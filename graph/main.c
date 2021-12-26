#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>
#include <math.h>
#include "draw.h"
#include "control.h"

int main(void)
{
    int i;
    int keyDown = 0;
    int *points = malloc(WINDOW_WIDTH * sizeof(char *));
    int connect = 1;
    float amp = 50.0;
    float period = 10.0;

    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HIGHT, 0, &window, &renderer);

    while (1)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        updatePoints(points, period, amp);
        drawFunct(renderer, event, points, connect);

        SDL_RenderPresent(renderer);

        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
        doInput(event, &keyDown, &period, &amp);
    }

    free(points);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}