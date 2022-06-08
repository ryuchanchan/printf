#include "ft_printf.h"
#include "libft.h"

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

int put_nbr_u(unsigned long long n)
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
        if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
        {
            ret += find_argument(format, i, ap);
            i++;
        }
        else
            ret += ft_putchar(format[i]);
        if (ret >= INT_MAX)
                return (-1);
        i++;
    }
    va_end(ap);
    free((char *)storage);
    return (ret);
}

// __attribute__((destructor))
// static void destructor() {
// system("leaks -q a.out");
// }