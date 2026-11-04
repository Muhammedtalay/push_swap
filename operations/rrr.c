/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:37:38 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/08 12:17:44 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_node **stack_a, t_node **stack_b, t_operations *op_count)
{
	if (!stack_a || !stack_b)
		return ;
	rra(stack_a, NULL);
	rrb(stack_b, NULL);
	if (op_count)
	{
		write(1, "rrr\n", 4);
		op_count->rrr++;
	}
}
