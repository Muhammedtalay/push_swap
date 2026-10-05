/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 18:10:04 by mutalay           #+#    #+#             */
/*   Updated: 2026/08/16 12:55:37 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ch;
	int		flag;

	i = 0;
	flag = 0;
	ch = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			ch = (char *)&s[i];
			flag++;
		}
		i++;
	}
	if (flag > 0 && *ch == (char)c)
	{
		return (ch);
	}
	else if ((char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
