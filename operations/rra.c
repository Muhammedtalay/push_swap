/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rra.c                                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: edogruer <edogruer@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/13 14:37:34 by edogruer         #+#    #+#              */
/*   Updated: 2026/09/16 14:40:08 by edogruer        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack_a, int print)
{
	if (!stack_a || !*stack_a || !(*stack_a)->prev)
		return ;
	*stack_a = (*stack_a)->prev;
	if (print)
		write(1, "rra\n", 4);
}
