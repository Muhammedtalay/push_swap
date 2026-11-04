/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogruer <edogruer@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:45:06 by edogruer          #+#    #+#             */
/*   Updated: 2026/10/28 14:50:20 by edogruer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	int_sqrt(size_t n)
{
	size_t	i;

	i = 1;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}

size_t	get_chunk_size(size_t size)
{
	size_t	chunk;

	chunk = int_sqrt(size) * 3 / 2;
	if (chunk < 1)
		chunk = 1;
	return (chunk);
}
