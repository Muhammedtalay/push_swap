/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:47:49 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/07 15:25:16 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b, t_operations *op_count)
{
	t_node	*tmp;

	if (!stack_a || !stack_b || !*stack_b)
		return ;
	tmp = pop_node(stack_b);
	push_node(stack_a, tmp);
	if (op_count)
	{
		op_count->pa++;
		write(1, "pa\n", 3);
	}
}
