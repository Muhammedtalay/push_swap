/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:08:28 by mutalay           #+#    #+#             */
/*   Updated: 2026/08/24 20:41:39 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	size_t	len1;
	size_t	len2;
	size_t	size;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	size = len1 + len2 + 1;
	news = (char *)malloc(size);
	if (!news)
		return (NULL);
	ft_strlcpy(news, s1, len1 + len2 + 1);
	ft_strlcat(news, s2, len1 + len2 + 1);
	return (news);
}
