/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 08:43:07 by rykawamu          #+#    #+#             */
/*   Updated: 2022/06/13 08:49:05 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	find_argument(const char *fmt, int i, va_list ap)
{
	if (fmt[i + 1] == '%')
		return (ft_putchar(fmt[i + 1]));
	else if (fmt[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (fmt[i + 1] == 's')
		return (put_s(va_arg(ap, char *)));
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

static int count_put(va_list ap, const char *format)
{
    size_t 	i;
    size_t	ret;

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
    return (ret);
}

int	ft_printf(const char	*format, ...)
{
	const char	*storage;
	va_list		ap;
	int num;

	storage = ft_strdup(format);
	if (!storage)
		return (0);
	va_start(ap, format);
	num = count_put(ap, format);
	va_end(ap);
	free((char *)storage);
	return (num);
}

__attribute__((destructor))
static void destructor() {
system("leaks -q a.out");
}