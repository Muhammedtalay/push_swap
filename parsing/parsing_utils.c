/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:54:20 by mutalay           #+#    #+#             */
/*   Updated: 2026/09/14 15:57:44 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_strategy(char *argv, t_options *op)
{
	if (ft_strncmp(argv, "--adaptive", 11) == 0)
		op->strategy = 0;
	else if (ft_strncmp(argv, "--simple", 9) == 0)
		op->strategy = 1;
	else if (ft_strncmp(argv, "--medium", 9) == 0)
		op->strategy = 2;
	else if (ft_strncmp(argv, "--complex", 10) == 0)
		op->strategy = 3;
	else if (ft_strncmp(argv, "--bench", 8) == 0)
		op->bench = 1;
	else
		return (0);
	return (1);
}

static int	sign_read(const char *nptr, int *i)
{
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		(*i)++;
		if (nptr[*i -1] == '-')
			return (-1);
	}
	return (1);
}

int	ft_atoi_current(const char *nptr, int *error)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	result = 0;
	sign = sign_read(nptr, &i);
	if (nptr[i] == '\0')
		*error = 1;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
		if (sign * result > INT_MAX_PS || sign * result < INT_MIN_PS)
		{
			*error = 1;
			return (0);
		}
	}
	if (nptr[i] != '\0')
		*error = 1;
	return ((int)(sign * result));
}
