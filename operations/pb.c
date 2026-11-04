/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 16:33:50 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/07 15:25:02 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **stack_a, t_node **stack_b, t_operations *op_count)
{
	t_node	*tmp;

	if (!stack_a || !stack_b || !*stack_a)
		return ;
	tmp = pop_node(stack_a);
	push_node(stack_b, tmp);
	if (op_count)
	{
		write(1, "pb\n", 3);
		op_count->pb++;
	}
}
