/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 14:00:17 by mutalay           #+#    #+#             */
/*   Updated: 2026/08/16 19:42:52 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ch;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			ch = (char *)&s[i];
			return (ch);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		ch = (char *)&s[i];
		return (ch);
	}
	return (NULL);
}
