/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:25:54 by mutalay           #+#    #+#             */
/*   Updated: 2026/08/17 19:12:47 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	j;

	size_dst = 0;
	size_src = 0;
	j = 0;
	while (size_dst < size && dst[size_dst])
		size_dst++;
	while (src[size_src])
		size_src++;
	if (size == 0)
		return (size_src);
	if (size <= size_dst)
		return (size + size_src);
	while (src[j] && (size_dst + j) < (size - 1))
	{
		dst[size_dst + j] = src[j];
		j++;
	}
	dst[size_dst + j] = '\0';
	return (size_dst + size_src);
}
