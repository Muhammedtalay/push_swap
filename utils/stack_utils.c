/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 19:21:58 by mutalay           #+#    #+#             */
/*   Updated: 2026/10/08 12:34:33 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_index(t_node *a, int value, size_t size)
{
	t_node	*tmp_2;
	size_t	j;
	size_t	counter;

	counter = 0;
	tmp_2 = a;
	j = 0;
	while (j < size)
	{
		if (tmp_2->value < value)
			counter++;
		tmp_2 = tmp_2->next;
		j++;
	}
	return (counter);
}

void	put_index(t_node *a)
{
	t_node	*tmp;
	size_t	i;
	size_t	size;

	if (!a)
		return ;
	tmp = a;
	i = 0;
	size = stack_size(a);
	while (i < size)
	{
		tmp->index = count_index(a, tmp->value, size);
		tmp = tmp->next;
		i++;
	}
}

int	stack_size(t_node *a)
{
	t_node	*cur;
	int		count;

	count = 1;
	if (!a)
		return (0);
	cur = a;
	while (cur->next != a)
	{
		cur = cur->next;
		count++;
	}
	return (count);
}

int	is_sorted(t_node *a)
{
	t_node	*cur;

	if (!a)
		return (1);
	cur = a;
	while (cur->next != a)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
