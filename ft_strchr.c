/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:58:34 by zzaoui            #+#    #+#             */
/*   Updated: 2024/10/18 20:13:57 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strchr - Locates a charachter in a string
 * @s: The string to search in
 * @c: The character to locate
 * Return: A pointer to the first occurence of
 *	the character c in the string s
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i++;
	}
	if (c == 0)
		return ((char *) &s[i + 1]);
	return (NULL);
}
