/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:30:20 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/08 12:16:49 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a, t_operations *op_count)
{
	int	temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = temp;
	if (op_count)
	{
		write(1, "sa\n", 3);
		op_count->sa++;
	}
}
