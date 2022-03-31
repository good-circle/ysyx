#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s)
{
    size_t length = 0;
    for (; *s != '\0'; s++)
    {
        length++;
    }
    return length;
}

char *strcpy(char *dst, const char *src)
{
    char *start = dst;
    while (*src != '\0')
    {
        *dst++ = *src++;
    }
    *dst = '\0';
    return start;
}

char *strncpy(char *dst, const char *src, size_t n)
{
    char *start = dst;
    while (n > 0)
    {
        *dst++ = *src++;
        n--;
    }
    return start;
}

char *strcat(char *dst, const char *src)
{
    char *start = dst;
    while (*dst != '\0')
    {
        dst++;
    }
    while (*src != '\0')
    {
        *dst++ = *src++;
    }
    *dst = '\0';
    return start;
}

int strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (int)(*s1 - *s2);
}

int strncmp(const char *s1, const char *s2, size_t n)
{
    while (n > 1 && *s1 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
        n--;
    }
    return (int)(*s1 - *s2);
}

void *memset(void *s, int c, size_t n)
{
    char *dst = s;
    while (n > 0)
    {
        *dst++ = c;
        n--;
    }
    return s;
}

// src ----------------
// dst          ----------------
// so copy from end to start
void *memmove(void *dst, const void *src, size_t n)
{
    char *out = dst;
    const char *in = src;
    if (in < out && in + n > out)
    {
        in += n - 1;
        out += n - 1;
        while (n > 0)
        {
            *out-- = *in--;
            n--;
        }
    }
    else
    {
        while (n > 0)
        {
            *out++ = *in++;
            n--;
        }
    }
    return dst;
}

void *memcpy(void *out, const void *in, size_t n)
{
    printf("out %p, in %p\n", out, in);
    char *dst = out;
    const char *src = in;
    while (n > 0)
    {
        *dst++ = *src++;
        n--;
    }
    return out;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
    const char *ss1 = s1;
    const char *ss2 = s2;
    while (n > 1 && *ss1 == *ss2)
    {
        ss1++;
        ss2++;
        n--;
    }
    return (int)(*ss1 - *ss2);
}

#endif

