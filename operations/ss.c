/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:45:09 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/07 15:28:46 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node **stack_a, t_node **stack_b, t_operations *op_count)
{
	if (!stack_a || !stack_b)
		return ;
	sa(stack_a, NULL);
	sb(stack_b, NULL);
	if (op_count)
	{
		write(1, "ss\n", 3);
		op_count->ss++;
	}
}
