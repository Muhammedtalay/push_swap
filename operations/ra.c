/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:26:54 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/07 15:24:54 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a, t_operations *op_count)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	*stack_a = (*stack_a)->next;
	if (op_count)
	{
		op_count->ra++;
		write(1, "ra\n", 3);
	}
}
