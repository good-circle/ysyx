#include <am.h>
#include <nemu.h>
#include <stdio.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd)
{
    uint32_t key = inw(KBD_ADDR);
    kbd->keydown = key ? 1 : 0;
    kbd->keycode = key;
}
