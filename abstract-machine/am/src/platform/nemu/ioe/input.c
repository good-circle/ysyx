#include <am.h>
#include <nemu.h>
#include <stdio.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd)
{
    uint32_t key = inl(KBD_ADDR);
    kbd->keydown = (key & KEYDOWN_MASK) ? 1 : 0;

    /* fixed in pa3.3, as AM_KEY_NONE is not defined by kbd->keydown */
    kbd->keycode = key & ~KEYDOWN_MASK;
}
