#ifndef FT_PRINTF_H

# define FT_PRINTF_H
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>

char	*lower_case(char *c);
int ft_put_c(char ap);
int ft_printf(const char    *format, ...);
#endif