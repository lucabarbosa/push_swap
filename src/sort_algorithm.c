/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:40:57 by lbento            #+#    #+#             */
/*   Updated: 2025/10/15 00:58:36 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_100(t_stack **stack_a, t_stack **stack_b);
void	sort_500(t_stack **stack_a, t_stack **stack_b);
static void	push_back_sorted(t_stack **stack_a, t_stack **stack_b);
static int		find_max_position(t_stack *stack_b);
static int		calculate_position_index(t_stack *stack, int position);

void	sort_100(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	chunk_size;

	i = 0;
	chunk_size = 15;
	while (*stack_a != NULL)
	{
		if (i >= 1 && (*stack_a)->position < i)
		{
			push_b(stack_a, stack_b, 1);
			rotate_b(stack_b, 1);
			i++;
		}
		else if ((*stack_a)->position < i + chunk_size)
		{
			push_b(stack_a, stack_b, 1);
			i++;
		}
		else if ((*stack_a)->position >= i + chunk_size)
			rotate_a(stack_a, 1);
	}
	push_back_sorted(stack_a, stack_b);
}

void	sort_500(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	chunk_size;

	i = 0;
	chunk_size = 35;
	while (*stack_a != NULL)
	{
		if (i >= 1 && (*stack_a)->position < i)
		{
			push_b(stack_a, stack_b, 1);
			rotate_b(stack_b, 1);
			i++;
		}
		else if ((*stack_a)->position < i + chunk_size)
		{
			push_b(stack_a, stack_b, 1);
			i++;
		}
		else if ((*stack_a)->position >= i + chunk_size)
			rotate_a(stack_a, 1);
	}
	push_back_sorted(stack_a, stack_b);
}

static void	push_back_sorted(t_stack **stack_a, t_stack **stack_b)
{
	int	max_pos;
	int	pos_index;
	int	size_b;
	
	while (*stack_b != NULL)
	{
		max_pos = find_max_position(*stack_b);
		pos_index = calculate_position_index(*stack_b, max_pos);
		size_b = list_size(*stack_b);
		if (pos_index <= size_b / 2)
		{
			while ((*stack_b)->position != max_pos)
				rotate_b(stack_b, 1);
		}
		else
		{
			while ((*stack_b)->position != max_pos)
				reverse_rotate_b(stack_b, 1);
		}
		push_a(stack_a, stack_b, 1);
	}
}

static int	find_max_position(t_stack *stack_b)
{
	int		max;
	t_stack	*current;
	
	if (!stack_b)
		return (-1);
	
	max = stack_b->position;
	current = stack_b->next;
	
	while (current != NULL)
	{
		if (current->position > max)
			max = current->position;
		current = current->next;
	}
	
	return (max);
}

static int	calculate_position_index(t_stack *stack, int position)
{
	int		index;
	t_stack	*current;
	
	index = 0;
	current = stack;
	
	while (current != NULL)
	{
		if (current->position == position)
			return (index);
		index++;
		current = current->next;
	}
	
	return (0);
}