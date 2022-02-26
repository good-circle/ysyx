#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...)
{
    panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap)
{
    int pos = 0;
    for (; *fmt != '\0'; fmt++)
    {
        while (*fmt != '%' && *fmt != '\0')
        {
            out[pos++] = *fmt++;
        }

        if (*fmt == '%')
        {
            fmt++;
        }
        else if (*fmt == '\0')
        {
            break;
        }

        switch (*fmt)
        {
        case 's':
        {
            char *s = va_arg(ap, char *);
            while (*s != '\0')
            {
                out[pos++] = *s++;
            }
            break;
        }

        case 'd':
        {
            int d = va_arg(ap, int);
            if (d < 0)
            {
                d = -d;
                out[pos++] = '-';
            }
            char num[20] = {0};
            int rem = 0;
            int length = 0;
            while (d > 0)
            {
                rem = d % 10;
                d = d / 10;
                num[length++] = rem + '0';
            }
            if (length == 0)
            {
                out[pos++] = '0';
            }
            else
            {
                length--;
                for (; length >= 0; length--)
                {
                    out[pos++] = num[length];
                }
            }
            break;
        }
        }
    }
    out[pos] = '\0';
    return pos;
}

int sprintf(char *out, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int length = vsprintf(out, fmt, ap);
    va_end(ap);
    return length;
}

int snprintf(char *out, size_t n, const char *fmt, ...)
{
    panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap)
{
    panic("Not implemented");
}

#endif

