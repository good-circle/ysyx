#include <fs.h>

typedef size_t (*ReadFn)(void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn)(const void *buf, size_t offset, size_t len);

size_t ramdisk_read(void *buf, size_t offset, size_t len);
size_t ramdisk_write(const void *buf, size_t offset, size_t len);

size_t serial_write(const void *buf, size_t offset, size_t len);

//#define STRACE

typedef struct
{
    char *name;
    size_t size;
    size_t disk_offset;
    size_t open_offset;

    // do not need to use in simple file system
    ReadFn read;
    WriteFn write;
} Finfo;

enum
{
    FD_STDIN,
    FD_STDOUT,
    FD_STDERR,
    FD_FB
};

size_t invalid_read(void *buf, size_t offset, size_t len)
{
    panic("should not reach here");
    return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len)
{
    panic("should not reach here");
    return 0;
}

/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
    [FD_STDIN] = {"stdin", 0, 0, 0, invalid_read, invalid_write},
    [FD_STDOUT] = {"stdout", 0, 0, 0, invalid_read, serial_write},
    [FD_STDERR] = {"stderr", 0, 0, 0, invalid_read, serial_write},
#include "files.h"
};

void init_fs()
{
    // TODO: initialize the size of /dev/fb
}

int fs_open(const char *pathname, int flags, int mode)
{
    for (int i = 0; i < sizeof(file_table) / sizeof(Finfo); i++)
    {
        if (strcmp(pathname, file_table[i].name) == 0)
        {
#ifdef STRACE
            printf("FS: open file %s\n", file_table[i].name);
#endif
            return i;
        }
    }

    assert(0);
}

size_t fs_read(int fd, void *buf, size_t len)
{
    /* pay attention: man 2 read: attempts to read "up to" count bytes */
    len = file_table[fd].open_offset + len > file_table[fd].size ? file_table[fd].size - file_table[fd].open_offset : len;

#ifdef STRACE
    printf("FS: read file %s at %d for length %d\n", file_table[fd].name, file_table[fd].open_offset, len);
#endif

    ramdisk_read(buf, file_table[fd].disk_offset + file_table[fd].open_offset, len);
    file_table[fd].open_offset += len;

    return len;
}

size_t fs_write(int fd, const void *buf, size_t len)
{
    if(fd == 1 || fd == 2)
    {
        file_table[fd].write(buf, 0, len);
        return len;
    }
    
    /* pay attention: man 2 write: writes "up to" count bytes */
    len = file_table[fd].open_offset + len > file_table[fd].size ? file_table[fd].size - file_table[fd].open_offset : len;

#ifdef STRACE
    printf("FS: write file %s at %d for length %d\n", file_table[fd].name, file_table[fd].open_offset, len);
#endif

    ramdisk_write(buf, file_table[fd].disk_offset + file_table[fd].open_offset, len);
    file_table[fd].open_offset += len;

    return len;
}

size_t fs_lseek(int fd, size_t offset, int whence)
{
    switch (whence)
    {
    case SEEK_SET:
        assert(offset >= 0 && offset <= file_table[fd].size);
        file_table[fd].open_offset = offset;
        break;

    case SEEK_CUR:
        assert(file_table[fd].open_offset + offset >= 0 && file_table[fd].open_offset + offset <= file_table[fd].size);
        file_table[fd].open_offset += offset;
        break;

    case SEEK_END:
        /* offset is unsigned, so we cannot do sub operation */
        assert(offset == 0);
        file_table[fd].open_offset = file_table[fd].size;
        break;
    }

#ifdef STRACE
    printf("FS: lseek file %s to %d\n", file_table[fd].name, file_table[fd].open_offset);
#endif

    /* pay attention: ftell will call lseek */
    return file_table[fd].open_offset;
}

int fs_close(int fd)
{
    return 0;
}
