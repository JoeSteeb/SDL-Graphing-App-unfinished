#ifndef INPUT_H_
#define INPUT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>
#include "draw.h"

int updatePoints(int *points, float period, float amp);
int doInput(SDL_Event event, int *keyDown, float *period, float *amp);

#endif // INPUT_H_