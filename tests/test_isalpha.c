#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("Test : 'a' | Output of isalpha:    %d\n", isalpha(97));
	printf("Test : 'a' | Output of ft_isalpha: %d\n", ft_isalpha(97));

	printf("Test : 'Z' | Output of isalpha:    %d\n", isalpha(90));
	printf("Test : 'Z' | Output of ft_isalpha: %d\n", ft_isalpha(90));

	printf("Test : '9' | Output of isalpha:    %d\n", isalpha(57));
	printf("Test : '9' | Output of ft_isalpha: %d\n", ft_isalpha(57));
	return (0);
}
