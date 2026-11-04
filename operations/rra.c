/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:37:34 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/07 15:25:58 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack_a, t_operations *op_count)
{
	if (!stack_a || !*stack_a || !(*stack_a)->prev)
		return ;
	*stack_a = (*stack_a)->prev;
	if (op_count)
	{
		write(1, "rra\n", 4);
		op_count->rra++;
	}
}
