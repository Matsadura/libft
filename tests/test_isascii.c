#include "../libft.h"
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	printf("Test ' '    | Output for    isascii %d\n", isascii((int)' '));
	printf("Test ' '    | Output for ft_isascii %d\n\n", ft_isascii((int)' '));
	printf("Test '-1'   | Output for    isascii %d\n", isascii(-1));
	printf("Test '-1'   | Output for ft_isascii %d\n\n", ft_isascii(-1));
	printf("Test '256'  | Output for    isascii %d\n", isascii(256));
	printf("Test '256'  | Output for ft_isascii %d\n\n", ft_isascii(256));
	return (0);
}
