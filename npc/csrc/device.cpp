#include "common.h"
#include <SDL2/SDL.h>

#define SCREEN_W 400
#define SCREEN_H 300

static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;

static void *vmem = NULL;
static uint32_t *vgactl_port_base = NULL;

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

    SDL_UpdateTexture(texture, NULL, vmem, SCREEN_W * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void init_device()
{
    init_screen;
}