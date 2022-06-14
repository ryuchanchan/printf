/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 08:29:05 by rykawamu          #+#    #+#             */
/*   Updated: 2022/06/13 09:45:42 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <limits.h>
# include <stdarg.h> 
# include <stdlib.h>
int		str_counter(char							*c);
int		ft_putchar(char								c);
int		ft_putstr(char								*str);
int		put_s(char									*s);
int		put_d_i(int									i);
int		put_p(unsigned long long					p);
int		put_u(unsigned long long					u);
int		put_xX(unsigned int	i, int					f);
int		ft_printf(const char						*format, ...);
char	*point_base(unsigned long long	p, int	base);
char	*lower_case(char						*c);
#endif
