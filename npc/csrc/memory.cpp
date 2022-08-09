#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/time.h>
#include <time.h>

#define CONFIG_MBASE 0x80000000
#define CONFIG_MSIZE 0x8000000
extern u_int8_t pmem[CONFIG_MSIZE];
extern const char *img_file;
extern int inst_num;

long init_pmem()
{
    memset(pmem, 0, CONFIG_MSIZE);
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
    int ret = fread(pmem, size, 1, fp);
    assert(ret == 1);

    fclose(fp);

    return size;
}

u_int32_t inst_fetch(unsigned long long pc)
{
    assert(pc >= CONFIG_MBASE);
    return *(u_int32_t *)(pmem + pc - CONFIG_MBASE);
}

u_int32_t memory_read(unsigned long long addr)
{
    return *(u_int32_t *)(pmem + addr - CONFIG_MBASE);
}

static inline bool in_pmem(uint64_t addr)
{
    return (addr >= CONFIG_MBASE) && (addr < (uint64_t)CONFIG_MBASE + CONFIG_MSIZE);
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
extern "C" uint64_t pmem_read(long long mem_raddr, bool mem_read)
{
    if (mem_read)
    {
        //printf("mem_raddr: %llx\n", mem_raddr);
    }

    // assert(mem_raddr >= CONFIG_MBASE || !mem_read);
    if (mem_read)
    {
        if (in_pmem(mem_raddr))
        {
            long long pmem_data = *(long long *)(pmem + (mem_raddr & ~0x7ull) - CONFIG_MBASE);
            // printf("%llx\n", pmem_data);
            return pmem_data;
        }

        if (mem_raddr = 0xa0000048)
        {
            uint64_t us = get_time();
            lo = (uint32_t)us;
            hi = us >> 32;
            return lo;
        }
        if (mem_raddr = 0xa0000052)
        {
            return hi;
        }
    }
    return 0;
}

extern "C" void pmem_write(long long mem_waddr, long long mem_wdata, char mem_wmask, bool mem_write)
{
    if (mem_write)
    {
        printf("mem_waddr: %llx mem_wdata: %llx mem_wmask: %llx\n", mem_waddr, mem_wdata, mem_wmask);
    }

    // assert(mem_waddr >= CONFIG_MBASE || !mem_write);
    if (mem_write)
    {
        if (in_pmem(mem_waddr))
        {
            unsigned long long real_mask = 0;
            u_int8_t mask_mask = 0b10000000;

            for (int i = 0; i < 7; i++)
            {
                if (mem_wmask & mask_mask)
                {
                    real_mask |= 0b11111111;
                }
                real_mask <<= 8;
                mask_mask >>= 1;
            }
            if (mem_wmask & mask_mask)
            {
                real_mask |= 0b11111111;
            }
            long long clear_wdata = ~real_mask;
            long long real_wdata = mem_wdata & real_mask;
            *(long long *)(pmem + (mem_waddr & ~0x7ull) - CONFIG_MBASE) = (*(long long *)(pmem + (mem_waddr & ~0x7ull) - CONFIG_MBASE) & clear_wdata) | real_wdata;
            // printf("after: %llx\n", *(long long *)(pmem + (mem_waddr & ~0x7ull) - CONFIG_MBASE));
            return;
        }

        if (mem_waddr == 0xa00003F8)
        {
            putchar((char)mem_wdata);
        }

        if (mem_waddr >= 0xa1000000 && mem_waddr <= 0xa1000000 + 300*400*32)
        {
            printf("vga = %lx\n", mem_waddr);
        }
    }
}
