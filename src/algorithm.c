/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:22:50 by lbento            #+#    #+#             */
/*   Updated: 2025/10/09 21:51:53 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			algorithm_sort(t_stack **stack_a, t_stack **stack_b);
void			include_position(t_stack **stack_a, int size);
void			radix_sort(t_stack **stack_a, t_stack **stack_b, int size);
static int		get_pixels(int position, int amount_bit_position);
static int		total_bits(int size);

void	algorithm_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = list_size(*stack_a);
	include_position(stack_a, size);
	radix_sort(stack_a, stack_b, size);
}

void	include_position(t_stack **stack_a, int size)
{
	t_stack	*current;
	t_stack	*lowest_node;
	int		lowest_number;
	int		i;

	i = 0;
	while (i < size)
	{
		current = *stack_a;
		lowest_node = NULL;
		lowest_number = 2147483647;
		while (current != NULL)
		{
			if (current->number < lowest_number && current->position == -1)
			{
				lowest_number = current->number;
				lowest_node = current;
			}
			current = current->next;
		}
		if (lowest_node != NULL)
			lowest_node->position = i;
		i++;
	}
}

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
			i++;
		}
		while (*stack_b)
		{
			push_a(stack_b, stack_b);
			*stack_b = (*stack_b)->next;
		}
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
