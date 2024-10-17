#include "../libft.h"
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	printf("Test: 'a' | Output of    toupper: %c\n", toupper((int)'a'));
	printf("Test: 'a' | Output of ft_toupper: %c\n\n", ft_toupper((int)'a'));

	printf("Test: 'Z' | Output of    toupper: %c\n", toupper((int)'Z'));
	printf("Test: 'Z' | Output of ft_toupper: %c\n\n", ft_toupper((int)'Z'));
	return (0);
}
