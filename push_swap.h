/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:50:35 by edogruer          #+#    #+#             */
/*   Updated: 2026/11/11 14:26:53 by mutalay          ###   ########.fr       */
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
	size_t			index;
}	t_node;

typedef struct s_options
{
	int		strategy;
	int		bench;
	double	disorder;
}	t_options;

typedef struct s_operations
{
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
}	t_operations;

t_node	*create_node(int value);
int		is_strategy(char *argv, t_options *op);
void	add_back(t_node **head, t_node *new);
int		parse_args(int argc, char **argv, t_options *op, t_node **head);
int		ft_atoi_current(const char *nptr, int *error);
void	free_arg(char **argv);
void	free_list(t_node **head);
void	pa(t_node **stack_a, t_node **stack_b, t_operations *op_count);
void	pb(t_node **stack_a, t_node **stack_b, t_operations *op_count);
void	sa(t_node **stack_a, t_operations *op_count);
void	sb(t_node **stack_b, t_operations *op_count);
void	ss(t_node **stack_a, t_node **stack_b, t_operations *op_count);
void	ra(t_node **stack_a, t_operations *op_count);
void	rb(t_node **stack_b, t_operations *op_count);
void	rr(t_node **stack_a, t_node **stack_b, t_operations *op_count);
void	rra(t_node **stack_a, t_operations *op_count);
void	rrb(t_node **stack_b, t_operations *op_count);
void	rrr(t_node **stack_a, t_node **stack_b, t_operations *op_count);
t_node	*pop_node(t_node **stack);
void	push_node(t_node **stack, t_node *node);
int		is_sorted(t_node *a);
int		stack_size(t_node *a);
void	sort_simple(t_node **a, t_node **b, t_operations *op_count);
void	sort_adaptive(t_node **a, t_node **b, double disorder,
			t_operations	*op_count);
void	sort_medium(t_node **a, t_node **b, t_operations *opr_count);
size_t	get_chunk_size(size_t size);
void	sort_complex(t_node **a, t_node **b, t_operations *opr_count);
double	compute_disorder(t_node *stack_a);
void	put_index(t_node *a);
void	run_strategy(t_node **a, t_node **b, t_options *op,
			t_operations	*opr_counter);
void	print_bench(t_options *op, t_operations *count);
int		get_max_bits(int size);

#endif
