#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("Test: ' ' | Output of    isalnum: %d\n", isalnum((int)' '));
	printf("Test: ' ' | Output of ft_isalnum: %d\n\n", ft_isalnum((int)' '));
	printf("Test: '0' | Output of    isalnum: %d\n", isalnum((int)'0'));
	printf("Test: '0' | Output of ft_isalnum: %d\n\n", ft_isalnum((int)'0'));
	printf("Test: 'z' | Output of    isalnum: %d\n", isalnum((int)'z'));
	printf("Test: 'z' | Output of ft_isalnum: %d\n\n", ft_isalnum((int)'z'));
	return (0);
}
