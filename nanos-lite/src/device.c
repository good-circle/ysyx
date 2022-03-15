#include <common.h>

#if defined(MULTIPROGRAM) && !defined(TIME_SHARING)
#define MULTIPROGRAM_YIELD() yield()
#else
#define MULTIPROGRAM_YIELD()
#endif

#define NAME(key) \
    [AM_KEY_##key] = #key,

static const char *keyname[256] __attribute__((used)) = {
    [AM_KEY_NONE] = "NONE",
    AM_KEYS(NAME)};

size_t serial_write(const void *buf, size_t offset, size_t len)
{
    for (int i = 0; i < len; i++)
    {
        putch(*((char *)buf + i));
    }

    return len;
}

size_t events_read(void *buf, size_t offset, size_t len)
{
    AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);

    /* kd/ku (2) + ' ' (1) + strlen(keyname[ev.keycode]) + '\n' (1) + '\0' */
    assert(len >= 5 + strlen(keyname[ev.keycode]));
    memset(buf, 0, len);

    if (ev.keycode == AM_KEY_NONE)
    {
        return 0;
    }

    return snprintf(buf, len, "%s %s\n", ev.keydown ? "kd" : "ku", keyname[ev.keycode]);
}

size_t dispinfo_read(void *buf, size_t offset, size_t len)
{
    int width = io_read(AM_GPU_CONFIG).width;
    int height = io_read(AM_GPU_CONFIG).height;

    /* WIDTH: ???\nHEIGHT: ???\n\0 (23) */
    assert(len >= 23);

    return snprintf(buf, len, "WIDTH: %d\nHEIGHT: %d\n", width, height);
}

size_t fb_write(const void *buf, size_t offset, size_t len)
{
    int width = io_read(AM_GPU_CONFIG).width;

    offset /= sizeof(int);

    int x = offset % width;
    int y = offset / width;

    io_write(AM_GPU_FBDRAW, x, y, (void*)buf, len / sizeof(int), 1, true);

    return 0;
}

void init_device()
{
    Log("Initializing devices...");
    ioe_init();
}
