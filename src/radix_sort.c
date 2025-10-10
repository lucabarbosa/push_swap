/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 04:10:28 by lbento            #+#    #+#             */
/*   Updated: 2025/10/10 04:11:38 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			radix_sort(t_stack **stack_a, t_stack **stack_b, int size);
static int		get_pixels(int position, int amount_bit_position);
static int		total_bits(int size);

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	amount_bits;
	int	current_bit;
	int	i;

	current_bit = 0;
	amount_bits = total_bits(size);
	while (current_bit < amount_bits)
	{
		i = 0;
		while (i < size)
		{
			if (get_pixels((*stack_a)->position, current_bit) == 1)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a, 1);
			i++;
		}
		while (*stack_b)
			push_a(stack_a, stack_b);
		current_bit++;
	}
}

static int	total_bits(int size)
{
	int	total_bits;

	total_bits = 0;
	while (size > 0)
	{
		size /= 2;
		total_bits++;
	}
	return (total_bits);
}

static int	get_pixels(int position, int amount_bit_position)
{
	if (((position >> amount_bit_position) & 1) == 0)
		return (0);
	else
		return (1);
}
