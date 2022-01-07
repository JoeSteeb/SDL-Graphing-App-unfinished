#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_ttf.h>

#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT (WINDOW_WIDTH)

typedef struct
{
    SDL_Keycode currentKey;
    char text[256];
    int keyDown;
    int length;
    int index;
    int cursorState;
} writer;

writer *walloc()
{
    writer *new = malloc(sizeof(writer));
    bzero(new->text, 256);
    strcpy(new->text, "");
    new->keyDown = 0;
    new->index = 0;
    new->length = 0;
    new->cursorState = 0;
    return new;
}

int wdalloc(writer *w)
{
    free(w);
    return 0;
}

/*
- x, y: upper left corner.
- texture, rect: outputs.
*/
void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
                       TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect)
{
    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {255, 255, 255, 0};

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
}

int textUI(writer *cWriter, SDL_Event event, int *shiftMask)
{
    int increment = 0;
    switch (event.type)
    {
    case SDL_KEYDOWN:
        if (!cWriter->keyDown || event.key.keysym.sym != cWriter->currentKey)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_BACKSPACE:
                if (cWriter->index > 0)
                {
                    if (cWriter->index < cWriter->length)
                    {
                        memmove(&(cWriter->text[cWriter->index - 1]), &(cWriter->text[cWriter->index]), cWriter->length + 1 - (cWriter->index));
                    }
                    cWriter->length--;
                    cWriter->index--;
                    cWriter->text[cWriter->length + 1] = 0;
                }
                break;

            case SDLK_DELETE:
                if (cWriter->index < cWriter->length)
                {
                    memmove(&(cWriter->text[cWriter->index]), &(cWriter->text[cWriter->index + 1]), cWriter->length + 1 - (cWriter->index));
                }
                cWriter->length--;
                cWriter->text[cWriter->length + 1] = 0;
                break;

            case SDLK_LEFT:
                if (cWriter->index > 0)
                {
                    cWriter->index--;
                    cWriter->text[cWriter->index + 1] = cWriter->text[cWriter->index];
                }
                break;

            case SDLK_RIGHT:
                if (cWriter->index < cWriter->length)
                {
                    cWriter->index++;
                    cWriter->text[cWriter->index - 1] = cWriter->text[cWriter->index];
                }
                break;

            case SDLK_LSHIFT:
                *shiftMask = 1;
                break;

            default:
                // printf("key = %d\n", event.key.keysym.sym);
                // printf("keyDown = %d\n", cWriter->keyDown);
                if (event.key.keysym.sym >= 'a' && event.key.keysym.sym <= 'z' || event.key.keysym.sym == ' ')
                {
                    if (!(cWriter->index == cWriter->length))
                    {

                        // copied extra char to leave in null terminator
                        memmove(&(cWriter->text[cWriter->index + 2]), &(cWriter->text[cWriter->index + 1]), cWriter->length - (cWriter->index));
                    }
                    if (*shiftMask && event.key.keysym.sym != ' ')
                    {
                        cWriter->text[cWriter->index] = event.key.keysym.sym - 32;
                    }
                    else
                    {
                        cWriter->text[cWriter->index] = event.key.keysym.sym;
                    }
                    increment = 1;
                }

                else if (event.key.keysym.sym >= '-' && event.key.keysym.sym <= '9' || event.key.keysym.sym == '=')
                {
                    if (!(cWriter->index == cWriter->length))
                    {
                        // copied extra char to leave in null terminator
                        memmove(&(cWriter->text[cWriter->index + 2]), &(cWriter->text[cWriter->index + 1]), cWriter->length - (cWriter->index));
                    }
                    if (!*shiftMask)
                    {
                        cWriter->text[cWriter->index] = event.key.keysym.sym;
                        increment = 1;
                    }
                    else
                    {
                        switch (event.key.keysym.sym)
                        {
                        case '9':
                            cWriter->text[cWriter->index] = '(';
                            increment = 1;
                            break;
                        case '0':
                            cWriter->text[cWriter->index] = ')';
                            increment = 1;
                            break;
                        case '8':
                            cWriter->text[cWriter->index] = '*';
                            increment = 1;
                            break;
                        case '5':
                            cWriter->text[cWriter->index] = '%';
                            increment = 1;
                            break;
                        case '=':
                            cWriter->text[cWriter->index] = '+';
                            increment = 1;
                        }
                    }
                }

                break;
            }

            cWriter->currentKey = event.key.keysym.sym;
            cWriter->keyDown = 1;
            if (increment)
            {
                cWriter->text[cWriter->length + 2] = 0;
                cWriter->index++;
                cWriter->length++;
            }
        }
        break;

    case SDL_KEYUP:
        if (event.key.keysym.sym == cWriter->currentKey)
        {
            cWriter->keyDown = 0;
        }
        if (event.key.keysym.sym == SDLK_LSHIFT)
        {
            *shiftMask = 0;
        }
        break;

    default:
        break;
    }
    if (cWriter->cursorState)
    {
        cWriter->text[cWriter->index] = ' ';
        cWriter->cursorState = 0;
    }
    else
    {
        cWriter->text[cWriter->index] = '|';
        cWriter->cursorState = 1;
    }
    // printf("index = %d\n", cWriter->index);
}

int main()
{
    SDL_Event event;
    SDL_Rect rect1, rect2;
    SDL_Renderer *renderer;
    SDL_Texture *texture1;
    SDL_Window *window;
    writer *writer1 = walloc();
    char *font_path;
    int *shiftMask = malloc(sizeof(int));
    int quit;
    *shiftMask = 0;

    font_path = "/usr/share/fonts/truetype/freefont/FreeMonoOblique.ttf";

    /* Inint TTF. */
    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
    TTF_Init();
    TTF_Font *font = TTF_OpenFont(font_path, 24);
    if (font == NULL)
    {
        fprintf(stderr, "error: font not found\n");
        exit(EXIT_FAILURE);
    }

    quit = 0;
    while (!quit)
    {
        if (SDL_PollEvent(&event) == 1)
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
        }
        textUI(writer1, event, shiftMask);
        // printf("index = %d\n", writer1->index);
        get_text_and_rect(renderer, 0, 0, writer1->text, font, &texture1, &rect1);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        /* Use TTF textures. */
        SDL_RenderCopy(renderer, texture1, NULL, &rect1);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(texture1);
    }

    /* Deinit TTF. */
    TTF_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    wdalloc(writer1);
    SDL_Quit();
    return EXIT_SUCCESS;
}