/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:04:19 by mutalay           #+#    #+#             */
/*   Updated: 2026/09/17 18:53:47 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arg(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
	{
		return ;
	}
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_list(t_node **head)
{
	t_node	*tmp;
	t_node	*last;

	if (!head || !*head)
		return ;
	tmp = (*head)->next;
	last = (*head)->prev;
	while (tmp != *head)
	{
		free(tmp->prev);
		tmp = tmp->next;
	}
	free(last);
	*head = NULL;
}
