/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 08:31:55 by rykawamu          #+#    #+#             */
/*   Updated: 2022/06/13 08:41:09 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*change_base(unsigned long long num, \
		int base, char *data, int count)
{
	while (num != 0)
	{
		if ((num % base) < 10)
			data[count - 1] = (num % base) + '0';
		else
			data[count - 1] = (num % base) + '7';
		num /= base;
		count--;
	}
	return (data);
}

char	*point_base(unsigned long long p, int base)
{
	char				*data;
	unsigned long long	i;
	int					count;

	count = 0;
	i = p;
	if (p == 0)
		return (ft_strdup("0"));
	while (p != 0)
	{
		p /= base;
		count++;
	}
	data = ft_calloc(count + 1, sizeof(char));
	if (!data)
		return (0);
	data = change_base(i, base, data, count);
	return (data);
}
