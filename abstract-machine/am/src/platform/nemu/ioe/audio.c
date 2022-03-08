#include <am.h>
#include <nemu.h>
#include <stdio.h>
#include <string.h>

#define AUDIO_FREQ_ADDR (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR (AUDIO_ADDR + 0x14)

static int pos = 0;

void __am_audio_init()
{
}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg)
{
  cfg->present = true;
  cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl)
{
  outl(AUDIO_FREQ_ADDR, ctrl->freq);
  outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
  outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
  outl(AUDIO_INIT_ADDR, true);
  pos = 0;
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat)
{
  stat->count = inl(AUDIO_COUNT_ADDR);
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl)
{
  int sbuf_size = inl(AUDIO_SBUF_SIZE_ADDR);
  int count = inl(AUDIO_COUNT_ADDR);
  int len = ctl->buf.end - ctl->buf.start;
  int free = sbuf_size - count;
  printf("am1: %d %d %d %d\n",free ,count, len, pos);

  while (free < len)
  {
    ;
  }

  int *sbuf = (int *)AUDIO_SBUF_ADDR;
  if (pos + len <= sbuf_size)
  {
    //printf("\npos: %d %d %d\n", pos, len, sbuf_size);
    printf("\n\n%p\n\n", sbuf+pos);
    memcpy(sbuf + pos, ctl->buf.start, len);
    pos += len;
  }
  else
  {
    int first = sbuf_size - pos;
    memcpy(sbuf + pos, ctl->buf.start, first);

    int second = len - first;
    memcpy(sbuf, ctl->buf.start + first, second);
    pos = second;
  }

  count += len;
  outl(AUDIO_COUNT_ADDR, count);
  printf("am2: %d %d %d\n", inl(AUDIO_COUNT_ADDR), len, count);
}
