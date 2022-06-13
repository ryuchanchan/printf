/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 08:54:52 by rykawamu          #+#    #+#             */
/*   Updated: 2022/06/13 08:59:06 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putchar(char	c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char	*str)
{
	char	str_count;
	int		i;

	str_count = '\0';
	i = 0;
	while (str[i] != '\0')
	{
		str_count += ft_putchar(str[i]);
		i++;
	}
	return (str_count);
}

int	str_counter(char	*c)
{
	int	i;

	if (!c)
		return (0);
	i = ft_strlen(c);
	ft_putstr(c);
	return (i);
}

char	*lower_case(char	*c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		c[i] = ft_tolower(c[i]);
		i++;
	}
	return (c);
}
