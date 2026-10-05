/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:38:24 by mutalay           #+#    #+#             */
/*   Updated: 2026/08/17 18:03:09 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*storage;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (__SIZE_MAX__ / size))
		return (NULL);
	storage = malloc(nmemb * size);
	if (storage == NULL)
		return (NULL);
	ft_bzero(storage, nmemb * size);
	return (storage);
}
