/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rrb.c                                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: edogruer <edogruer@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/14 21:59:29 by edogruer         #+#    #+#              */
/*   Updated: 2026/09/16 14:40:31 by edogruer        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_node **stack_b, int print)
{
	if (!stack_b || !*stack_b || !(*stack_b)->prev)
		return ;
	*stack_b = (*stack_b)->prev;
	if (print)
		write(1, "rrb\n", 4);
}
