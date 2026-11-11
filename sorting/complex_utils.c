/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutalay <mutalay@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:51:02 by mutalay           #+#    #+#             */
/*   Updated: 2026/11/11 16:45:24 by mutalay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_max_bits(int size)
{
	int	max_index;
	int	bits;

	max_index = size - 1;
	bits = 0;
	while (max_index > 0)
	{
		max_index = max_index >> 1;
		bits++;
	}
	return (bits);
}
