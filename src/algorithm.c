/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:22:50 by lbento            #+#    #+#             */
/*   Updated: 2025/10/09 19:55:43 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_sort(t_stack **stack_a, t_stack **stack_b);
void	include_position(t_stack **stack_a, int size);

void	algorithm_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = list_size(*stack_a);
	include_position(stack_a, size);
	if (!stack_b)
		return ;
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
