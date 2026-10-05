/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ra.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: edogruer <edogruer@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/12 19:26:54 by edogruer         #+#    #+#              */
/*   Updated: 2026/09/16 14:35:23 by edogruer        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a, int print)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	*stack_a = (*stack_a)->next;
	if (print)
		write(1, "ra\n", 3);
}
