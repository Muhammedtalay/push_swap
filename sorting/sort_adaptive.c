/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_adaptive.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: edogruer <edogruer@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/23 01:41:18 by edogruer         #+#    #+#              */
/*   Updated: 2026/09/23 02:01:06 by edogruer        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_node **a, t_node **b)
{
	double	d;

	d = compute_disorder(*a);
	if (d < 0.2)
		sort_simple(a, b);
	else if (d < 0.5)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}
