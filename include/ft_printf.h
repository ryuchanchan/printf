#ifndef FT_PRINTF_H

# define FT_PRINTF_H
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>

int put_nbr_u(unsigned long long n);
char    *point_base(unsigned long long p, int base);
int str_counter(char *c);
int	ft_putchar(char c);
int ft_putstr(char *str);
char	*lower_case(char *c);
int put_s(char *s);
int put_d_i(int i);
int put_p(unsigned long long p);
int put_u(unsigned long long u);
int put_xX(unsigned int i, int f);
int ft_printf(const char    *format, ...);
#endif