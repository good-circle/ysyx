#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

extern u_int8_t pmem[0x8000000];
extern const char *img_file;
extern int inst_num;

long init_pmem()
{
    memset(pmem, 0, 0x8000000);
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
    assert(pc >= 0x80000000);
    inst_num++;
    return *(u_int32_t *)(pmem + pc - 0x80000000);
}

u_int32_t memory_read(unsigned long long addr)
{
    return *(u_int32_t *)(pmem + addr - 0x80000000);
}

extern "C" void pmem_read(long long mem_raddr, long long *mem_rdata, bool mem_read)
{
    if (mem_read)
    {
        *mem_rdata = *(long long *)(pmem + (mem_raddr & ~0x7ull) - 0x80000000);
    }
}

extern "C" void pmem_write(long long mem_waddr, long long mem_wdata, char mem_wmask, bool mem_write)
{
    if (mem_write)
    {
        long long real_mask;
        if (mem_wmask | 0b10000000)
        {
            real_mask |= 0b11111111;
        }
        real_mask << 8;
        if (mem_wmask | 0b01000000)
        {
            real_mask |= 0b11111111;
        }
        real_mask << 8;
        if (mem_wmask | 0b00100000)
        {
            real_mask |= 0b11111111;
        }
        real_mask << 8;
        if (mem_wmask | 0b00010000)
        {
            real_mask |= 0b11111111;
        }
        real_mask << 8;
        if (mem_wmask | 0b00001000)
        {
            real_mask |= 0b11111111;
        }
        real_mask << 8;
        if (mem_wmask | 0b00000100)
        {
            real_mask |= 0b11111111;
        }
        real_mask << 8;
        if (mem_wmask | 0b00000010)
        {
            real_mask |= 0b11111111;
        }
        real_mask << 8;
        if (mem_wmask | 0b00000001)
        {
            real_mask |= 0b11111111;
        }

        *(long long *)(pmem + (mem_waddr & ~0x7ull) - 0x80000000) |= (mem_wdata & real_mask);
        printf("%x %x %x %x", pmem[0x1000], pmem[0x1001], pmem[0x1002], pmem[0x1003]);
        //printf("%lx %llx\n", mem_waddr, *(unsigned long long *)(pmem + (mem_waddr & ~0x7ull) - 0x80000000));
    }
}
