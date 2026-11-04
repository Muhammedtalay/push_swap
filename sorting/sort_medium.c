/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:00:54 by edogruer          #+#    #+#             */
/*   Updated: 2026/11/04 18:38:01 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_position(t_node *b)
{
	t_node	*current;
	size_t	max;
	int		pos;
	int		i;
	int		size;

	if (!b)
		return (-1);
	current = b;
	max = current->index;
	pos = 0;
	i = 0;
	size = stack_size(b);
	while (i < size)
	{
		if (current->index > max)
		{
			max = current->index;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

static void	rotate_b(t_node **b, int pos, int size,
	t_operations	*op)
{
	int	count;

	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b, op);
	}
	else
	{
		count = size - pos;
		while (count-- > 0)
			rrb(b, op);
	}
}

static void	push_chunks(t_node **a, t_node **b, size_t chunk,
	t_operations	*op)
{
	size_t	pushed;

	pushed = 0;
	while (*a)
	{
		if ((*a)->index < pushed)
		{
			pb(a, b, op);
			rb(b, op);
			pushed++;
		}
		else if ((*a)->index < pushed + chunk)
		{
			pb(a, b, op);
			pushed++;
		}
		else
			ra(a, op);
	}
}

static void	push_back(t_node **a, t_node **b, t_operations *op)
{
	int	pos;
	int	size;

	while (*b)
	{
		size = stack_size(*b);
		pos = find_max_position(*b);
		if (pos < 0)
			return ;
		rotate_b(b, pos, size, op);
		pa(a, b, op);
	}
}

void	sort_medium(t_node **a, t_node **b, t_operations *op)
{
	size_t	size;
	size_t	chunk;

	if (!a || !*a || !b || is_sorted(*a))
		return ;
	size = (size_t) stack_size(*a);
	chunk = get_chunk_size(size);
	push_chunks(a, b, chunk, op);
	push_back(a, b, op);
}
