/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:48:06 by mutalay           #+#    #+#             */
/*   Updated: 2026/10/08 15:21:31 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_options		op;
	t_node			*head_a;
	t_node			*head_b;
	t_operations	opr_count;

	head_a = NULL;
	head_b = NULL;
	op.bench = 0;
	op.strategy = 0;
	ft_bzero(&opr_count, sizeof(t_operations));
	if (parse_args(argc, argv, &op, &head_a) == 0)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	op.disorder = compute_disorder(head_a);
	put_index(head_a);
	if (!is_sorted(head_a))
		run_strategy(&head_a, &head_b, &op, &opr_count);
	if (op.bench == 1)
		print_bench(&op, &opr_count);
	free_list(&head_a);
	return (0);
}
