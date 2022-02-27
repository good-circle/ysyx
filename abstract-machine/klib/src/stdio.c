#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    char out[128];
    int length = vsprintf(out, fmt, ap);
    for (int i = 0; i < length; i++)
    {
        putch(out[i]);
    }
    va_end(ap);
    return length;
}

int vsprintf(char *out, const char *fmt, va_list ap)
{
    int pos = 0;
    for (; *fmt != '\0'; fmt++)
    {
        // add to out[] directly until see %
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

        // padding: if 0 then padding '0'; else ' '
        char padding = ' ';
        if (*fmt == '0')
        {
            padding = '0';
            fmt++;
        }

        // width
        int width = 0;
        while (*fmt >= '0' && *fmt <= '9')
        {
            width = width * 10 + *fmt++ - '0';
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

            // padding
            width = length == 0 ? width : width - 1;
            while (length < width)
            {
                out[pos++] = padding;
                width--;
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

    /* debug
    for(int i = 0; i < pos; i++)
    {
        putch(out[i]);
    }
    */

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
