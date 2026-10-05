/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 15:47:37 by mutalay           #+#    #+#             */
/*   Updated: 2026/08/21 19:22:50 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*news;

	i = 0;
	if (!f || !s)
		return (NULL);
	len = ft_strlen(s);
	news = ft_calloc(len + 1, sizeof(char));
	if (!news)
		return (NULL);
	while (s[i])
	{
		news[i] = (*f)(i, s[i]);
		i++;
	}
	return (news);
}
