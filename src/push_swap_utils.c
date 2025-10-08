/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:58:53 by lbento            #+#    #+#             */
/*   Updated: 2025/10/08 00:17:12 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a);
void check_arguments(t_list **stack_a);

void check_arguments(t_list **stack_a)
{
	t_list *temp;
	t_list *next_node;

	temp = *stack_a;
	while (temp)
	{
		next_node = temp->next;
		while (next_node)
		{
			if (temp->number == next_node->number)
				free_and_exit(stack_a, NULL, 1);
			next_node = next_node->next;
		}
		temp = temp->next;
	}
	if (is_sorted(&stack_a) == 1)
		free_and_exit(stack_a, NULL, 0);
}

int	is_sorted(t_list *stack_a)
{
	int temp;
	t_list *checked;
	
	while (stack_a && stack_a->next)
	{
		temp = stack_a->number;
		stack_a = stack_a->next;
		if (stack_a->number < temp)
			return (0);
	}
	return (1);
}