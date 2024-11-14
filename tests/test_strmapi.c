#include "../libft.h"
#include <stdio.h>


char to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}
int	main(void)
{
	char *str;

	str = ft_strmapi("abcde", &to_upper);
	printf("%s\n", str);
	return (0);
}
