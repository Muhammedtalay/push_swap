/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 18:19:54 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/07 18:03:40 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_node *a)
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

static void	rotate_to_top(t_node **a, int index, int size,
		t_operations *opr_count)
{
	int	i;

	i = 0;
	if (index <= size / 2)
	{
		while (i < index)
		{
			ra(a, opr_count);
			i++;
		}
	}
	else
	{
		while (i < size - index)
		{
			rra(a, opr_count);
			i++;
		}
	}
}

void	sort_simple(t_node **a, t_node **b, t_operations *opr_count)
{
	int	size;
	int	min;

	size = stack_size(*a);
	while (*a)
	{
		min = find_min_index(*a);
		rotate_to_top(a, min, size, opr_count);
		pb(a, b, opr_count);
		size = size - 1;
	}
	while (*b)
		pa(a, b, opr_count);
}
