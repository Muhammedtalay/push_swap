/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rb.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: edogruer <edogruer@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/12 21:09:21 by edogruer         #+#    #+#              */
/*   Updated: 2026/09/16 14:39:07 by edogruer        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node **stack_b, int print)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	*stack_b = (*stack_b)->next;
	if (print)
		write(1, "rb\n", 3);
}
