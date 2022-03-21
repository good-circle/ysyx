#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

extern u_int8_t pmem[0x8000000]; 
extern const char *img_file;
extern int inst_num;

void init_pmem()
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
}

u_int32_t inst_fetch(unsigned long long pc)
{
    inst_num++;
    return *(u_int32_t *)(pmem + pc - 0x80000000);
}

u_int32_t memory_read(unsigned long long addr)
{
    return *(u_int32_t *)(pmem + addr - 0x80000000);
}

