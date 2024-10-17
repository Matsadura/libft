#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("Test: '2' | Output of    isdigit: %d\n", isdigit((int)'2'));
	printf("Test: '2' | Output of ft_isdigit: %d\n\n", ft_isdigit((int)'2'));
	printf("Test: 'a' | Output of    isdigit: %d\n", isdigit((int)'a'));
	printf("Test: 'a' | Output of ft_isdigit: %d\n\n", ft_isdigit((int)'a'));
	printf("Test: 'Z' | Output of    isdigit: %d\n", isdigit((int)'Z'));
	printf("Test: 'Z' | Output of ft_isdigit: %d\n\n", ft_isdigit((int)'Z'));
	return (0);
}
