/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 08:50:17 by rykawamu          #+#    #+#             */
/*   Updated: 2022/06/13 08:54:22 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	put_s(char	*s)
{
	int	size;

	if (s == NULL)
		s = "(null)";
	size = ft_strlen(s);
	if (size >= INT_MAX)
		return (-1);
	ft_putstr(s);
	return (size);
}

int	put_d_i(int	i)
{
	char	*s;
	int		n;

	s = ft_itoa(i);
	if (!s)
		return (0);
	n = str_counter(s);
	free(s);
	return (n);
}

int	put_p(unsigned long long	p)
{
	char	*point;
	int		n;

	point = lower_case(point_base(p, 16));
	if (!point)
		return (0);
	n = ft_putstr("0x");
	n += str_counter(point);
	free(point);
	return (n);
}

int	put_u(unsigned long long	u)
{
	int	n;

	n = 0;
	n = put_nbr_u(u);
	return (n);
}

int	put_xX(unsigned int	i, int	f)
{
	char	*hex;
	int		n;

	if (!i)
		i = 0;
	hex = point_base((unsigned long long)i, 16);
	if (!hex)
		return (0);	
	if (f == 1)
		hex = lower_case(hex);
	n = str_counter(hex);
	free(hex);
	return (n);
}
