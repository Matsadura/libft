#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	int	*n = malloc(sizeof(int));

	n = (int *) ft_memset(n, 0b00000101, 2);
	n = (int *) ft_memset(n, 0b00111001, 1);
	printf("%d\n", *n);
	return (0);
}
