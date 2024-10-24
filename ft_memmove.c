#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (dst == NULL || src == NULL)
		return (dst);
	tmp1 = (unsigned char *) dst;
	tmp2 = (unsigned char *) src;
	if (tmp1 > tmp2)
	{
		while (len-- > 0)
		{
			tmp1[len] = tmp2[len];
		}
	}
	else
	{
		i = 0;
		while (i++ < len)
		{
			tmp1[i] = tmp2[i];
		}
	}
	return (dst);
}
