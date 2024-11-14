#include "../libft.h"
#include <stdio.h>

void	fun(unsigned int i, char *c)
{
	(void)i;

	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

int	main(void)
{
	char arr[] = "hello";

	ft_striteri(arr, &fun);
	printf("%s\n", arr);
	return (0);
}
