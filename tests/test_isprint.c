#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("Test : 'a' | Output of isprint:    %d\n", isprint(97));
	printf("Test : 'a' | Output of ft_isprint: %d\n", ft_isprint(97));

	printf("Test : 'Z' | Output of isprint:    %d\n", isprint(90));
	printf("Test : 'Z' | Output of ft_isprint: %d\n", ft_isprint(90));

	printf("Test : 'DEL' | Output of isprint:    %d\n", isprint(127));
	printf("Test : 'DEL' | Output of ft_isprint: %d\n", ft_isprint(127));

	printf("Test : '9' | Output of isprint:    %d\n", isprint(57));
	printf("Test : '9' | Output of ft_isprint: %d\n", ft_isprint(57));
	return (0);
}
