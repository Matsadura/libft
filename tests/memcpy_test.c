#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	int c = 1337;
	int	*n1 = malloc(sizeof(int));
	char *n2 = malloc(sizeof(int));

	n1 = &c;
	ft_memcpy(n2, n1, 2);
	printf("%d\n", (unsigned char)*(n2 + 1));
	return (0);
}
