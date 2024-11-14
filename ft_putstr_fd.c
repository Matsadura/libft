/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaoui <zzaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:36:20 by zzaoui            #+#    #+#             */
/*   Updated: 2024/11/01 12:45:03 by zzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putstr_fd - Outputs the string 's' to the given
 *		file descriptor
 * @s: the string to output
 * @fd: the fild descriptor on which to write
 */
void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
