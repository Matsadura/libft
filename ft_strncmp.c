/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:44:15 by zzaoui            #+#    #+#             */
/*   Updated: 2024/10/18 19:32:20 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strncmp - Compares only the first at most n bytes
 *	of s1 and s2
 * @s1: First string
 * @s2: Second string
 * @n: The number of bytes to compare
 * Return: An integer less than, equal to, or greater than
 *	zero if s1 (or the first n bytes thereof) is found,
 *	respectively, to be less than, to match, or be greater
 *	than s2
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] && s2[i]) || i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
