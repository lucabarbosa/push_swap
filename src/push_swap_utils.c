/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:58:53 by lbento            #+#    #+#             */
/*   Updated: 2025/10/20 17:15:38 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		list_size(t_stack *stack);
t_stack	*list_last(t_stack *stack);
void	listadd_front(t_stack **stack, t_stack *new);
int		is_sorted(t_stack *stack_a);
void	check_arguments(t_stack **stack_a);

int	list_size(t_stack *stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = stack;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_stack	*list_last(t_stack *stack)
{
	while (stack != NULL)
	{
		if (stack->next == NULL)
		{
			return (stack);
		}
		stack = stack->next;
	}
	return (NULL);
}

void	check_arguments(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*next_node;

	temp = *stack_a;
	while (temp)
	{
		next_node = temp->next;
		while (next_node)
		{
			if (temp->number == next_node->number)
				free_and_exit(*stack_a, NULL, 1);
			next_node = next_node->next;
		}
		temp = temp->next;
	}
	if (is_sorted(*stack_a) == 1)
		free_and_exit(*stack_a, NULL, 0);
}

int	is_sorted(t_stack *stack_a)
{
	int		temp;

	while (stack_a && stack_a->next)
	{
		temp = stack_a->number;
		stack_a = stack_a->next;
		if (stack_a->number < temp)
			return (0);
	}
	return (1);
}
