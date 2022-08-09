#include "common.h"
#include <SDL2/SDL.h>

#define SCREEN_W 400
#define SCREEN_H 300

static void init_screen()
{
    SDL_Window *window = NULL;
    char title[128];
    sprintf(title, "riscv64-NPC");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(
        SCREEN_W,
        SCREEN_H,
        0, &window, &renderer);
    SDL_SetWindowTitle(window, title);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                                SDL_TEXTUREACCESS_STATIC, SCREEN_W, SCREEN_H);
}

void init_device()
{
    init_screen;
}