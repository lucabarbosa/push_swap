/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:22:50 by lbento            #+#    #+#             */
/*   Updated: 2025/10/14 18:24:19 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			algorithm_sort(t_stack **stack_a, t_stack **stack_b);
void			include_position(t_stack **stack_a, int size);
static void		sort_three(t_stack **stack_a);
static void		sort_small(t_stack **stack_a, t_stack **stack_b, int size);
static void		move_to_b(t_stack **stack_a, int size, int position);

void	algorithm_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = list_size(*stack_a);
	include_position(stack_a, size);
	if (size == 2)
		swap_a(stack_a, 1);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4 || size == 5)
		sort_small(stack_a, stack_b, size);
	else
		chunk_sort(stack_a, stack_b, size);
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

static void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->number;
	second = (*stack_a)->next->number;
	third = (*stack_a)->next->next->number;
	if (first > second && second < third && first < third)
		swap_a(stack_a, 1);
	else if (first > second && second < third && first > third)
		rotate_a(stack_a, 1);
	else if (first < second && second > third && first < third)
	{
		swap_a(stack_a, 1);
		rotate_a(stack_a, 1);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(stack_a, 1);
	else if (first > second && second > third)
	{
		swap_a(stack_a, 1);
		reverse_rotate_a(stack_a, 1);
	}
}

static void	sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 4)
	{
		while ((*stack_a)->position != 0)
			rotate_a (stack_a, 1);
		push_b(stack_a, stack_b);
		sort_three(stack_a);
		push_a(stack_a, stack_b);
	}
	else
	{
		move_to_b(stack_a, size, 0);
		push_b(stack_a, stack_b);
		move_to_b(stack_a, size -1, 1);
		push_b(stack_a, stack_b);
		sort_three(stack_a);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
}

static void	move_to_b(t_stack **stack_a, int size, int position)
{
	int		i;
	t_stack	*current;

	current = *stack_a;
	i = 0;
	while (current)
	{
		if (current->position == position)
			break ;
		i++;
		current = current->next;
	}
	if (i <= size / 2)
	{
		while ((*stack_a)->position != position)
			rotate_a(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->position != position)
			reverse_rotate_a(stack_a, 1);
	}
}
