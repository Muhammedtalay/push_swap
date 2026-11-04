/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 20:19:21 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/06 15:34:35 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_node *stack_a)
{
	int		mistakes;
	int		total_pairs;
	t_node	*i;
	t_node	*j;

	mistakes = 0;
	total_pairs = 0;
	i = stack_a;
	while (i->next != stack_a)
	{
		j = i->next;
		while (j != stack_a)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double) mistakes / total_pairs);
}
