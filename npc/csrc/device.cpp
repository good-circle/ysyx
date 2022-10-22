#include "common.h"
#include <SDL2/SDL.h>

#define SCREEN_W 400
#define SCREEN_H 300

static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;

void *vmem = NULL;
uint32_t vgactl_port_base[2];

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

    vgactl_port_base[0] = (screen_width() << 16) | screen_height();
    vgactl_port_base[1] = 0;
}

void init_device()
{
    init_screen();
}

int vga_size()
{
    return (screen_width() << 16) | screen_height();
}

static inline void update_screen()
{ // this
    SDL_UpdateTexture(texture, NULL, vmem, screen_width() * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void vga_update_screen()
{
    // TODO: call `update_screen()` when the sync register is non-zero,
    // then zero out the sync register
    if (vgactl_port_base[1])
    {
        update_screen();
        vgactl_port_base[1] = 0;
    }
}

void device_update()
{
    static uint64_t last = 0;
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC_COARSE, &now);
    uint64_t cur = now.tv_sec * 1000000 + now.tv_nsec / 1000;
    if (cur - last < 1000000)
    {
        return;
    }
    printf("update screen\n");
    last = cur;
    vga_update_screen();
}
