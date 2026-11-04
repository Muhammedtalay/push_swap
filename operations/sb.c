/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:33:56 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/07 15:27:36 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **stack_b, t_operations *op_count)
{
	int	temp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = temp;
	if (op_count)
	{
		write(1, "sb\n", 3);
		op_count->sb++;
	}
}
