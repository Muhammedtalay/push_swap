/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:59:29 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/08 12:17:31 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_node **stack_b, t_operations *op_count)
{
	if (!stack_b || !*stack_b || !(*stack_b)->prev)
		return ;
	*stack_b = (*stack_b)->prev;
	if (op_count)
	{
		write(1, "rrb\n", 4);
		op_count->rrb++;
	}
}
