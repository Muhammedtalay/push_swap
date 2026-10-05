/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:15:26 by mutalay           #+#    #+#             */
/*   Updated: 2026/08/24 20:40:12 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int n)
{
	int			counter;
	long int	number;

	number = n;
	counter = 0;
	if (number <= 0)
	{
		counter++;
		number = number * -1;
	}
	while (number > 0)
	{
		counter++;
		number = number / 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	long int	number;
	char		*area;
	int			i;
	int			flag;

	flag = 0;
	number = n;
	i = ft_counter(n);
	area = ft_calloc(i + 1, sizeof(char));
	if (!area)
		return (NULL);
	while (i > flag)
	{
		if (number < 0)
		{
			area[0] = '-';
			number = number * -1;
			flag = 1;
		}
		area[i -1] = (number % 10) + '0';
		number = number / 10;
		i--;
	}
	return (area);
}
