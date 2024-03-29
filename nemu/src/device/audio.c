#include <common.h>
#include <device/map.h>
#include <SDL2/SDL.h>

enum
{
  reg_freq,      // freq (from AM)
  reg_channels,  // channels (from AM)
  reg_samples,   // samples (from AM)
  reg_sbuf_size, // sbuf_size (from NEMU, CONFIG_SB_SIZE)
  reg_init,      // whether is initialized (from AM)
  reg_count,     // used size of sbuf (controled in NEMU)
  nr_reg
};

static uint8_t *sbuf = NULL;
static uint32_t *audio_base = NULL;
static int pos = 0;
static bool init = false;

void audio_callback(void *userdata, uint8_t *stream, int len)
{
  /* use real_len to record data length of callback function */
  int real_len = len;

  /* now len is length from am */
  if(audio_base[reg_count] < len)
  {
    len = audio_base[reg_count];
  }

  /* if pos reaches sbuf_size then turns to start */
  if(len + pos <= CONFIG_SB_SIZE)
  {
    memcpy(stream, sbuf + pos, len);
    pos += len;
  }
  else
  {
    int first = CONFIG_SB_SIZE - pos;
    memcpy(stream, sbuf + pos, first);

    int second = len - first;
    memcpy(stream + first, sbuf, second);
    pos = second;
  }

  /* reduce len from count */
  audio_base[reg_count] -= len;

  /* if count < len then padding 0 */
  memset(stream + len, 0, real_len - len);
}

static void audio_io_handler(uint32_t offset, int len, bool is_write)
{
  if (audio_base[reg_init] == true && init == false && is_write)
  {
    /* use init to make sure not to init again, maybe a better way? */
    init = true;

    /* read information from am */
    SDL_AudioSpec s = {};
    s.freq = audio_base[reg_freq];
    s.format = AUDIO_S16SYS;
    s.channels = audio_base[reg_channels];
    s.samples = audio_base[reg_samples];
    s.callback = audio_callback;
    s.userdata = NULL;

    /* clear count */
    audio_base[reg_count] = 0;

    /* init sbuf size */
    audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;

    SDL_InitSubSystem(SDL_INIT_AUDIO);
    SDL_OpenAudio(&s, NULL);
    SDL_PauseAudio(0);
  }
}

void init_audio()
{
  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size);
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif

  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);
}
