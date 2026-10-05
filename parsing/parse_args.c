/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:05:11 by mutalay           #+#    #+#             */
/*   Updated: 2026/09/18 17:32:47 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicate(t_node **head, int value)
{
	t_node	*tmp;

	if (!*head)
		return (0);
	if ((*head)->value == value)
		return (1);
	tmp = (*head)->next;
	while (tmp != *head)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	parse_number(char *str, t_node **head)
{
	int		value;
	int		error;
	t_node	*tmp;

	error = 0;
	value = ft_atoi_current(str, &error);
	if (error)
		return (0);
	if (has_duplicate(head, value))
		return (0);
	tmp = create_node(value);
	if (!tmp)
		return (0);
	add_back(head, tmp);
	return (1);
}

static int	parse_arg(char *argv, t_node **head)
{
	char	**tmp;
	int		k;

	tmp = ft_split(argv, ' ');
	k = 0;
	if (!tmp || !tmp[k])
	{
		free_arg(tmp);
		free_list(head);
		return (0);
	}
	while (tmp[k])
	{
		if (!parse_number(tmp[k], head))
		{
			free_arg(tmp);
			free_list(head);
			return (0);
		}
		k++;
	}
	free_arg(tmp);
	return (1);
}

int	parse_args(int argc, char **argv, t_options *op, t_node **head)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!is_strategy(argv[i], op))
		{
			if (!parse_arg(argv[i], head))
				return (0);
		}
		i++;
	}
	return (1);
}
