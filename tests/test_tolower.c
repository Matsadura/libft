#include "../libft.h"
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	printf("Test: 'a' | Output of    tolower: %c\n", tolower((int)'a'));
	printf("Test: 'a' | Output of ft_tolower: %c\n\n", ft_tolower((int)'a'));

	printf("Test: 'Z' | Output of    tolower: %c\n", tolower((int)'Z'));
	printf("Test: 'Z' | Output of ft_tolower: %c\n\n", ft_tolower((int)'Z'));
	return (0);
}
