#include "ft_printf.h"
#include "libft.h"
#define PATTERN "cspdiuxX%"

int	ft_putchar(char c)
{
    return (write (1, &c, 1));
}

int ft_putstr(char *str)
{
    char    str_count = '\0';
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        str_count += ft_putchar(str[i]);
        i++;
    }
    return (str_count);
}

int str_counter(char *c)
{
    int i;

    if (!c)
        return (0);
    i = ft_strlen(c);
    ft_putstr(c);
    return (i);
}

int put_s(char *s)
{
    int size;

    if (s == NULL)
        s = "(null)";
     size = ft_strlen(s);
     ft_putstr(s);
     return (size);
}

int put_d_i(int i)
{
    char    *s;
    int     n;

    s = ft_itoa(i);
    n = str_counter(s);
    free(s);
    return (n);
}

static char *change_base(unsigned long long us, int b, char *r, int c)
{
    while (us != 0)
    {
        if ((us % b) < 10)
            r[c -1] = (us % b) + 48;
        else
            r[c -1] = (us % b) + 55;
        us /= b;
        c--;
    }
    return (r);
}

char    *point_base(unsigned long long p, int base)
{
    char *rtn;
    unsigned long long us;
    int count;

    count = 0;
    us = p;
    if (p == 0)
        return (ft_strdup("0"));
    while (p != 0)
    {
        p = p /base;
        count++;
    }
    rtn = ft_calloc(count + 1, sizeof(char));
    if (!rtn)
        return (0);
    rtn = change_base(us, base, rtn, count);
    return (rtn);
}

int put_p(unsigned long long p)
{
    char    *point;
    int     n;

    point = lower_case(point_base(p, 16));
    n = str_counter("0x");
    n += str_counter(point);
    free(point);
    return (n);
}

static int put_nbr_u(unsigned long long n)
{
    char str;
    unsigned long long tmp;
    size_t t;

    tmp = n;
    t = 0;
    while (9 < tmp)
    {
        tmp /= 10;
        t++;
    }
    if (9 < n)
        put_nbr_u(n / 10);
    str = '0' + n % 10;
    ft_putchar(str);
    return (t + 1);
}

int put_u(unsigned long long u)
{
    int n;

    n = 0;
    n = put_nbr_u(u);
    return (n);
}

int put_xX(unsigned int i, int f)
{
    char *hex;
    int n;

    if (!i)
        i = 0;
    hex = point_base((unsigned long long)i, 16);
    if (f == 1)
        hex = lower_case(hex);
    n = str_counter(hex);
    free(hex);
    return (n);
}

int	find_argument(const char *fmt, int i, va_list ap)
{
    if (fmt[i + 1] == '%')
        return (ft_putchar(fmt[i + 1]));
    else if (fmt[i + 1] == 'c')
        return (ft_putchar(va_arg(ap, int)));
    else if (fmt[i + 1] == 's')
        return put_s(va_arg(ap, char *));
    else if (fmt[i + 1] == 'd' || fmt[i + 1] == 'i')
        return (put_d_i(va_arg(ap, int)));
    else if (fmt[i + 1] == 'p')
        return (put_p((unsigned long long)va_arg(ap, void *)));
    else if (fmt[i + 1] == 'u')
        return (put_u((unsigned long long)va_arg(ap, unsigned int)));
    else if (fmt[i + 1] == 'x')
        return (put_xX(va_arg(ap, unsigned int), 1));
    else if (fmt[i + 1] == 'X')
        return (put_xX(va_arg(ap, unsigned int), 2));
    return (0);
}

int	ft_printf(const char *format, ...)
{
    const char  *storage;
    va_list     ap;
    int         i;
    int         ret;

    storage = ft_strdup(format);
    if (!storage)
        return (0);
    va_start(ap, format);
    i = 0;
    ret = 0;
    while (format[i])
    {
        if (format[i] == '%' && ft_strchr(PATTERN, format[i + 1]))
        {
            ret += find_argument(format, i, ap);
            i++;
        }
        else
            ret += ft_putchar(format[i]);
        i++;
    }
    va_end(ap);
    free((char *)storage);
    return (ret);
}