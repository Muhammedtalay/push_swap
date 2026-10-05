/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple_utils.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: edogruer <edogruer@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/21 16:35:26 by edogruer         #+#    #+#              */
/*   Updated: 2026/09/21 16:40:00 by edogruer        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *a)
{
	t_node	*cur;
	int		count;

	count = 1;
	if (!a)
		return (0);
	cur = a;
	while (cur->next != a)
	{
		cur = cur->next;
		count++;
	}
	return (count);
}
