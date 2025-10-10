/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:17:16 by lbento            #+#    #+#             */
/*   Updated: 2025/10/10 17:09:33 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack_a, int put_text);
void	rotate_b(t_stack **stack_b, int put_text);
void	reverse_rotate_a(t_stack **stack_a, int put_text);
void	reverse_rotate_b(t_stack **stack_b, int put_text);
void	rotateab_or_reverseab(t_stack **stack_a, t_stack **stack_b, int each);

void	rotate_a(t_stack **stack_a, int put_text)
{
	t_stack	*old_first_node;
	t_stack	*old_last_node;

	if (!stack_a || !(*stack_a)->next)
		return ;
	old_first_node = *stack_a;
	*stack_a = old_first_node->next;
	(*stack_a)->previous = NULL;
	old_last_node = list_last(*stack_a);
	old_last_node->next = old_first_node;
	old_first_node->previous = old_last_node;
	old_first_node->next = NULL;
	if (put_text)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack_b, int put_text)
{
	t_stack	*old_first_node;
	t_stack	*old_last_node;

	if (!stack_b || !(*stack_b)->next)
		return ;
	old_first_node = *stack_b;
	*stack_b = old_first_node->next;
	(*stack_b)->previous = NULL;
	old_last_node = list_last(*stack_b);
	old_last_node->next = old_first_node;
	old_first_node->previous = old_last_node;
	old_first_node->next = NULL;
	if (put_text)
		write(1, "rb\n", 3);
}

void	reverse_rotate_a(t_stack **stack_a, int put_text)
{
	t_stack	*old_first_node;
	t_stack	*old_last_node;
	t_stack	*penultimate;

	if (!stack_a || !(*stack_a)->next)
		return ;
	old_first_node = *stack_a;
	old_last_node = list_last(*stack_a);
	penultimate = old_last_node->previous;
	*stack_a = old_last_node;
	penultimate->next = NULL;
	old_last_node->previous = NULL;
	old_last_node->next = old_first_node;
	old_first_node->previous = old_last_node;
	if (put_text)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **stack_b, int put_text)
{
	t_stack	*old_first_node;
	t_stack	*old_last_node;
	t_stack	*penultimate;

	if (!stack_b || !(*stack_b)->next)
		return ;
	old_first_node = *stack_b;
	old_last_node = list_last(*stack_b);
	penultimate = old_last_node->previous;
	*stack_b = old_last_node;
	penultimate->next = NULL;
	old_last_node->previous = NULL;
	old_last_node->next = old_first_node;
	old_first_node->previous = old_last_node;
	if (put_text)
		write(1, "rrb\n", 4);
}

void	rotateab_or_reverseab(t_stack **stack_a, t_stack **stack_b, int each)
{
	if (each == 1)
	{
		rotate_a(stack_a, 0);
		rotate_b(stack_b, 0);
		write(1, "rr\n", 3);
	}
	if (each == 2)
	{
		reverse_rotate_a(stack_a, 0);
		reverse_rotate_b(stack_b, 0);
		write(1, "rrr\n", 3);
	}
}
