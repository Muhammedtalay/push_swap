/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ss.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: edogruer <edogruer@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/09 17:45:09 by edogruer         #+#    #+#              */
/*   Updated: 2026/09/17 23:30:31 by edogruer        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node **stack_a, t_node **stack_b, int print)
{
	if (!stack_a || !stack_b)
		return ;
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print)
		write(1, "ss\n", 3);
}
