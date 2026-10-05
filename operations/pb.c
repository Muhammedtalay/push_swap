/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   pb.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: edogruer <edogruer@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/12 16:33:50 by edogruer         #+#    #+#              */
/*   Updated: 2026/09/17 23:03:00 by edogruer        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **stack_a, t_node **stack_b, int print)
{
	t_node	*tmp;

	if (!stack_a || !stack_b || !*stack_a)
		return ;
	tmp = pop_node(stack_a);
	push_node(stack_b, tmp);
	if (print)
		write(1, "pb\n", 3);
}
