#include "common.h"
#include <SDL2/SDL.h>

#define SCREEN_W 800
#define SCREEN_H 600

static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;

static void *vmem = NULL;
static uint32_t *vgactl_port_base = NULL;

static uint32_t screen_width()
{
    return SCREEN_W;
}

static uint32_t screen_height()
{
    return SCREEN_H;
}

static uint32_t screen_size()
{
    return screen_width() * screen_height() * sizeof(uint32_t);
}

static void init_screen()
{
    vmem = malloc(screen_size());
    memset(vmem, 0, screen_size());
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
    init_screen();
}