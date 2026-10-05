/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:48:06 by mutalay           #+#    #+#             */
/*   Updated: 2026/09/18 16:48:09 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_options	op;
	t_node		*head;

	head = NULL;
	op.bench = 0;
	op.strategy = 0;
	if (parse_args(argc, argv, &op, &head) == 0)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	free_list(&head);
	return (0);
}
