/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 01:41:18 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/08 15:19:31 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_node **a, t_node **b, double disorder,
		t_operations *opr_count)
{
	if (disorder < 0.2)
		sort_simple(a, b, opr_count);
	else if (disorder < 0.5)
		sort_medium(a, b, opr_count);
	else
		sort_complex(a, b, opr_count);
}

void	run_strategy(t_node **a, t_node **b, t_options *op,
		t_operations *opr_counter)
{
	if (op->strategy == 1)
		sort_simple(a, b, opr_counter);
	else if (op->strategy == 2)
		sort_medium(a, b, opr_counter);
	else if (op->strategy == 3)
		sort_complex(a, b, opr_counter);
	else
		sort_adaptive(a, b, op->disorder, opr_counter);
}
