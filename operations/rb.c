/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:09:21 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/07 15:24:47 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node **stack_b, t_operations *op_count)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	*stack_b = (*stack_b)->next;
	if (op_count)
	{
		write(1, "rb\n", 3);
		op_count->rb++;
	}
}
