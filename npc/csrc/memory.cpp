#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/time.h>
#include <time.h>
#include "common.h"

#define CONFIG_MBASE 0x80000000
#define CONFIG_MSIZE 0x8000000
#define DEVICE_BASE 0xa0000000
#define MMIO_BASE 0xa0000000

#define SERIAL_PORT (DEVICE_BASE + 0x00003f8)
#define KBD_ADDR (DEVICE_BASE + 0x0000060)
#define RTC_ADDR (DEVICE_BASE + 0x0000048)
#define VGACTL_ADDR (DEVICE_BASE + 0x0000100)
#define AUDIO_ADDR (DEVICE_BASE + 0x0000200)
#define DISK_ADDR (DEVICE_BASE + 0x0000300)
#define FB_ADDR (MMIO_BASE + 0x1000000)
#define AUDIO_SBUF_ADDR (MMIO_BASE + 0x1200000)

extern const char *img_file;
extern int inst_num;
extern int vga_size();
extern void *vmem;
extern uint32_t vgactl_port_base[2];

extern axi4_mem<32, 64, 4> mem;
extern u_int8_t pmem[CONFIG_MSIZE];
long init_pmem()
{
    if (img_file == NULL)
    {
        printf("No image is given. Use the default build-in image.");
        assert(0);
    }

    FILE *fp = fopen(img_file, "rb");
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    printf("The image is %s, size = %ld\n", img_file, size);

    fseek(fp, 0, SEEK_SET);

    // for simulator
    mem.load_binary(img_file, 0x80000000);

    // for difftest
    memset(pmem, 0, CONFIG_MSIZE);
    fseek(fp, 0, SEEK_SET);
    int ret = fread(pmem, size, 1, fp);
    assert(ret == 1);

    fclose(fp);

    return size;
}

u_int32_t inst_fetch(unsigned long long pc)
{
    assert(0);
}

u_int32_t memory_read(unsigned long long addr)
{
    assert(0);
}

static inline bool in_pmem(uint64_t addr)
{
    return (addr >= CONFIG_MBASE) && (addr < DEVICE_BASE);
}

static uint64_t boot_time = 0;

static uint64_t get_time_internal()
{
    struct timeval now;
    gettimeofday(&now, NULL);
    uint64_t us = now.tv_sec * 1000000 + now.tv_usec;
    return us;
}

uint64_t get_time()
{
    if (boot_time == 0)
    {
        boot_time = get_time_internal();
    }

    uint64_t now = get_time_internal();
    return now - boot_time;
}

uint32_t lo = 0;
uint32_t hi = 0;
uint32_t pmem_read(uint32_t mem_raddr, bool mem_read)
{
    if (mem_read)
    {
        if (in_pmem(mem_raddr))
        {
            assert(0);
        }

        // printf("in_pmem_read\n");

        if (mem_raddr == 0xa0000048)
        {
            uint64_t us = get_time();
            lo = (uint32_t)us;
            hi = us >> 32;
            // printf("lo = %lx\n", lo);
            return lo;
        }

        if (mem_raddr == 0xa000004c)
        {
            return hi;
        }

        if (mem_raddr == 0xa00003f8)
        {
            assert(0);
        }

        if (mem_raddr == 0xa0000100)
        {
            // printf("mem_raddr := %lx\n", mem_raddr);
            return vgactl_port_base[0];
        }

        if (mem_raddr == 0xa0000104)
        {
            // printf("mem_raddr := %lx\n", mem_raddr);
            return vgactl_port_base[1];
        }

        if (mem_raddr >= 0xa0000100)
        {
            assert(0);
        }
    }
    return 0;
}

void pmem_write(uint32_t mem_waddr, uint32_t mem_wdata, bool mem_write)
{
    // assert(mem_waddr >= CONFIG_MBASE || !mem_write);
    if (mem_write)
    {
        if (in_pmem(mem_waddr))
        {
            assert(0);
            // unsigned long long real_mask = 0;
            // u_int8_t mask_mask = 0b10000000;

            // for (int i = 0; i < 7; i++)
            // {
            //     if (mem_wmask & mask_mask)
            //     {
            //         real_mask |= 0b11111111;
            //     }
            //     real_mask <<= 8;
            //     mask_mask >>= 1;
            // }
            // if (mem_wmask & mask_mask)
            // {
            //     real_mask |= 0b11111111;
            // }
            // long long clear_wdata = ~real_mask;
            // long long real_wdata = mem_wdata & real_mask;
            // *(long long *)(pmem + (mem_waddr & ~0x7ull) - CONFIG_MBASE) = (*(long long *)(pmem + (mem_waddr & ~0x7ull) - CONFIG_MBASE) & clear_wdata) | real_wdata;
            // // printf("after: %llx\n", *(long long *)(pmem + (mem_waddr & ~0x7ull) - CONFIG_MBASE));
            // return;
        }
        // printf("in_pmem_write\n");

        if (mem_waddr == 0xa00003F8)
        {
            putchar((char)mem_wdata);
        }

        if (mem_waddr == 0xa0000104)
        {
            vgactl_port_base[1] = mem_wdata;
        }

        if (mem_waddr >= 0xa1000000 && mem_waddr <= 0xa1000000 + 300 * 400 * 32)
        {
            *(uint8_t *)((uint8_t *)vmem + mem_waddr - 0xa1000000) = mem_wdata;
            // assert(0);
            // if (mem_waddr >= 0xa1000000 && mem_waddr <= 0xa1000008)
            // printf("mem_waddr is %x, mem_wdata is %x\n", mem_waddr, mem_wdata);
        }
    }
}
