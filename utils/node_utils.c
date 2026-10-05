/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: edogruer <edogruer@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/09 20:15:22 by edogruer         #+#    #+#              */
/*   Updated: 2026/09/16 00:48:47 by edogruer        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_back(t_node **head, t_node *new)
{
	t_node	*tmp;

	if (!*head)
	{
		new->prev = new;
		new->next = new;
		*head = new;
		return ;
	}
	else
	{
		tmp = (*head)->prev;
		(*head)->prev = new;
		new->prev = tmp;
		tmp->next = new;
		new->next = *head;
		return ;
	}
}

t_node	*pop_node(t_node **stack)
{
	t_node	*node;

	node = *stack;
	if (node->next == node)
		*stack = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*stack = node->next;
	}
	return (node);
}

void	push_node(t_node **stack, t_node *node)
{
	if (!*stack)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = *stack;
		node->prev = (*stack)->prev;
		(*stack)->prev->next = node;
		(*stack)->prev = node;
	}
	*stack = node;
}
