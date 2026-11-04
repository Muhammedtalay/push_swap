/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 18:09:05 by mutalay           #+#    #+#             */
/*   Updated: 2026/10/08 15:36:36 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_strategy(t_options *op)
{
	ft_putstr_fd("\n[bench] strategy:  ", 2);
	if (op->strategy == 1)
		ft_putstr_fd("Simple / (n^2)\n", 2);
	else if (op->strategy == 2)
		ft_putstr_fd("Medium / (n√n)\n", 2);
	else if (op->strategy == 3)
		ft_putstr_fd("Complex / (n log n)\n", 2);
	else if (op->disorder < 0.2)
		ft_putstr_fd("Adaptive / (n^2)\n", 2);
	else if (op->disorder < 0.5)
		ft_putstr_fd("Adaptive / (n√n)\n", 2);
	else
		ft_putstr_fd("Adaptive / (n log n)\n", 2);
}

static size_t	total_ops(t_operations *count)
{
	return (count->pa + count->pb + count->ra + count->rb
		+ count->rr + count->rra + count->rrb + count->rrr
		+ count->sa + count->sb + count->ss);
}

static void	put_opr(char *name, int count)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd("  ", 2);
	ft_putnbr_fd(count, 2);
	ft_putstr_fd("  ", 2);
}

static void	put_disorder(double d)
{
	int	n;

	n = (int)(d * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(n / 100, 2);
	ft_putstr_fd(".", 2);
	if (n % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(n % 100, 2);
	ft_putstr_fd("%", 2);
}

void	print_bench(t_options *op, t_operations *count)
{
	put_disorder(op->disorder);
	put_strategy(op);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(total_ops(count), 2);
	ft_putstr_fd("\n[bench] ", 2);
	put_opr("sa", count->sa);
	put_opr("sb", count->sb);
	put_opr("ss", count->ss);
	put_opr("pa", count->pa);
	put_opr("pb", count->pb);
	ft_putstr_fd("\n[bench] ", 2);
	put_opr("ra", count->ra);
	put_opr("rb", count->rb);
	put_opr("rr", count->rr);
	put_opr("rra", count->rra);
	put_opr("rrb", count->rrb);
	put_opr("rrr", count->rrr);
	ft_putstr_fd("\n", 2);
}
