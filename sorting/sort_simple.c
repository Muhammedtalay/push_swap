/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_simple.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: edogruer <edogruer@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/15 18:19:54 by edogruer         #+#    #+#              */
/*   Updated: 2026/09/18 18:06:32 by edogruer        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_min_index(t_node *a)
{
	int		min_val;
	int		min_idx;
	int		count;
	t_node	*cur;

	if (!a)
		return (0);
	min_val = a->value;
	min_idx = 0;
	cur = a->next;
	count = 1;
	while (cur != a)
	{
		if (cur->value < min_val)
		{
			min_val = cur->value;
			min_idx = count;
		}
		cur = cur->next;
		count++;
	}
	return (min_idx);
}

void	rotate_to_top(t_node **a, int index, int size)
{
	int	i;

	i = 0;
	if (index <= size / 2)
	{
		while (i < index)
		{
			ra(a, 1);
			i++;
		}
	}
	else
	{
		while (i < size - index)
		{
			rra(a, 1);
			i++;
		}
	}
}

void	sort_simple(t_node **a, t_node **b)
{
	int	size;
	int	min;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	while (*a)
	{
		min = find_min_index(*a);
		rotate_to_top(a, min, size);
		pb(a, b, 1);
		size = size - 1;
	}
	while (*b)
		pa(a, b, 1);
}
