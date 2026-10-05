/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:40:53 by mutalay           #+#    #+#             */
/*   Updated: 2026/09/14 14:41:51 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counter_s(char const *s, char c)
{
	size_t	i;
	size_t	flag;
	size_t	counter;

	i = 0;
	flag = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			counter++;
		}
		else if (s[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	return (counter);
}

static void	free_all(char **areas)
{
	size_t	i;

	i = 0;
	while (areas[i])
	{
		free(areas[i]);
		i++;
	}
}

static int	putarea(char **areas, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			areas[j] = ft_substr(s, start, i - start);
			if (!areas[j])
				return (0);
			j++;
		}
		else
			i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**areas;

	if (!s)
		return (NULL);
	areas = ft_calloc(counter_s(s, c) + 1, sizeof(char *));
	if (!areas)
		return (NULL);
	if (!putarea(areas, s, c))
	{
		free_all(areas);
		free(areas);
		return (NULL);
	}
	return (areas);
}
