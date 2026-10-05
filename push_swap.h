/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:50:35 by mutalay           #+#    #+#             */
/*   Updated: 2026/09/18 16:55:38 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX_PS 2147483647
# define INT_MIN_PS -2147483648

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_options
{
	int	strategy;
	int	bench;
}	t_options;

t_node	*create_node(int value);
int		is_strategy(char *argv, t_options *op);
void	add_back(t_node **head, t_node *new);
int		parse_args(int argc, char **argv, t_options *op, t_node **head);
int		ft_atoi_current(const char *nptr, int *error);
void	free_arg(char **argv);
void	free_list(t_node **head);
void	pa(t_node **stack_a, t_node **stack_b, int print);
void	pb(t_node **stack_a, t_node **stack_b, int print);
void	sa(t_node **stack_a, int print);
void	sb(t_node **stack_b, int print);
void	ss(t_node **stack_a, t_node **stack_b, int print);
void	ra(t_node **stack_a, int print);
void	rb(t_node **stack_b, int print);
void	rr(t_node **stack_a, t_node **stack_b, int print);
void	rra(t_node **stack_a, int print);
void	rrb(t_node **stack_b, int print);
void	rrr(t_node **stack_a, t_node **stack_b, int print);
t_node	*pop_node(t_node **stack);
void	push_node(t_node **stack, t_node *node);

#endif
