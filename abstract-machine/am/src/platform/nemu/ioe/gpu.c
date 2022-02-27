#include <am.h>
#include <nemu.h>
#include <string.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

static int Width = 0;
static int Height = 0;

void __am_gpu_init()
{
    int i = 0;
    int width_height = inl(VGACTL_ADDR);
    Width = width_height >> 16;
    Height = width_height & 0xffff;
    int w = Width;
    int h = Height;
    uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
    for (i = 0; i < w * h; i++)
    {
        fb[i] = i;
    }
    outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg)
{
    *cfg = (AM_GPU_CONFIG_T){
        .present = true,
        .has_accel = false,
        .width = Width,
        .height = Height,
        .vmemsz = 0};
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl)
{
    int x = ctl->x;
    int y = ctl->y;
    uint32_t *pixels = ctl->pixels;
    int w = ctl->w;
    int h = ctl->h;

    uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
    for (int i = 0; i < h; i++)
    {
        memcpy(&fb[(y + i) * Width + x], pixels, 4 * w);
        pixels += w;
    }

    if (ctl->sync)
    {
        outl(SYNC_ADDR, 1);
    }
}

void __am_gpu_status(AM_GPU_STATUS_T *status)
{
    status->ready = true;
}
