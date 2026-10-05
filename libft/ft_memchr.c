/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:50:57 by mutalay           #+#    #+#             */
/*   Updated: 2026/08/16 12:55:18 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		ch;
	size_t				i;

	i = 0;
	ch = (unsigned char)c;
	str = (const unsigned char *)s;
	while (n > 0)
	{
		if (ch == str[i])
		{
			return ((void *)&str[i]);
		}
		i++;
		n--;
	}
	return (NULL);
}
