/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rr.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: edogruer <edogruer@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/13 14:26:37 by edogruer         #+#    #+#              */
/*   Updated: 2026/09/17 23:34:17 by edogruer        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_node **stack_a, t_node **stack_b, int print)
{
	if (!stack_a || !stack_b)
		return ;
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		write(1, "rr\n", 3);
}
