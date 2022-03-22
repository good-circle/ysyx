#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

extern u_int8_t pmem[0x8000000];
extern const char *img_file;
extern int inst_num;

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
        mem_rdata = (long long *)(pmem + mem_raddr);
        printf("%p\n", mem_rdata);
    }

    // 总是读取地址为`raddr & ~0x7ull`的8字节返回给`rdata`
}

extern "C" void pmem_write(long long mem_waddr, long long mem_wdata, char mem_wmask, bool mem_write)
{
    // 总是往地址为`waddr & ~0x7ull`的8字节按写掩码`wmask`写入`wdata`
    // `wmask`中每比特表示`wdata`中1个字节的掩码,
    // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
}
