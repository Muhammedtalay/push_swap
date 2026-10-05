/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 20:01:36 by mutalay           #+#    #+#             */
/*   Updated: 2026/08/25 12:45:25 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		return (ft_calloc(1, 1));
	}
	size = ft_strlen(s) - start;
	if (len < size)
	{
		size = len;
	}
	news = (char *)malloc(size + 1);
	if (!news)
		return (NULL);
	ft_strlcpy(news, &s[start], size + 1);
	return (news);
}
