#include "ft_printf.h"
#include "libft.h"

// static int	ft_tolower(int	c)
// {
// 	if ('A' <= c && c <= 'Z')
// 		return (c - (-32));
// 	return (c);
// }

char	*lower_case(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		c[i] = ft_tolower(c[i]);
		i++;
	}
	return (c);
}