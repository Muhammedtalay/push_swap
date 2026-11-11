/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:57:08 by mutalay           #+#    #+#             */
/*   Updated: 2026/11/11 15:34:58 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_one_bit(t_node **a, t_node **b, int bit, t_operations *opr)
{
	int	size;
	int	i;

	size = stack_size(*a);
	i = 0;
	while (i < size)
	{
		if (((*a)->index >> bit) & 1)
		{
			ra(a, opr);
		}
		else
			pb(a, b, opr);
		i++;
	}
	while (*b)
	{
		pa(a, b, opr);
	}
}

static void	radix_sort(t_node **a, t_node **b, int max_bits, t_operations *opr)
{
	int	bit;

	bit = 0;
	while (bit < max_bits)
	{
		radix_one_bit(a, b, bit, opr);
		bit++;
	}
}

void	sort_complex(t_node **a, t_node **b, t_operations *opr_count)
{
	int	size;
	int	i;
	int	max_bits;

	size = stack_size(*a);
	i = 0;
	max_bits = get_max_bits(size);
	radix_sort(a, b, max_bits, opr_count);
}
