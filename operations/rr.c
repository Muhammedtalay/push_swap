/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:26:37 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/07 15:29:14 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_node **stack_a, t_node **stack_b, t_operations *op_count)
{
	if (!stack_a || !stack_b)
		return ;
	ra(stack_a, NULL);
	rb(stack_b, NULL);
	if (op_count)
	{
		op_count->rr++;
		write(1, "rr\n", 3);
	}
}
