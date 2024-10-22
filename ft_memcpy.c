/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:30:09 by zzaoui            #+#    #+#             */
/*   Updated: 2024/10/22 17:26:10 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memcpy - copy memory area
 * @dst: the memory area to copy to
 * @src: the memory area to copy from
 * @n: the number of bytes to copy
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *) dst)[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}
