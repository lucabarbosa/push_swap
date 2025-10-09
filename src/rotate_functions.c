/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:17:16 by lbento            #+#    #+#             */
/*   Updated: 2025/10/08 21:36:29 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a, int put_text)
{
	t_list	*old_first_node;
	t_list	*old_last_node;

	if (!stack_a || !(*stack_a)->next)
		return ;
	old_first_node = *stack_a;
	*stack_a = old_first_node->next;
	(*stack_a)->previous = NULL;
	old_last_node = ft_lstlast(*stack_a);
	old_last_node->next = old_first_node;
	old_first_node->previous = old_last_node;
	old_first_node->next = NULL;
	if (put_text)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b, int put_text)
{
	t_list	*old_first_node;
	t_list	*old_last_node;

	if (!stack_b || !(*stack_b)->next)
		return ;
	old_first_node = *stack_b;
	*stack_b = old_first_node->next;
	(*stack_b)->previous = NULL;
	old_last_node = ft_lstlast(*stack_b);
	old_last_node->next = old_first_node;
	old_first_node->previous = old_last_node;
	old_first_node->next = NULL;
	if (put_text)
		write(1, "rb\n", 3);
}

void	reverse_rotate_a(t_list **stack_a, int put_text)
{
	t_list	*old_first_node;
	t_list	*old_last_node;
	t_list	*penultimate;

	if (!stack_a || !(*stack_a)->next)
		return ;
	old_first_node = *stack_a;
	old_last_node = ft_lstlast(*stack_a);
	penultimate = old_last_node->previous;
	penultimate->next = NULL;
	(*stack_a)->previous = NULL;
	(*stack_a)->next = old_first_node;
	old_first_node->previous = *stack_a;
	if (put_text)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **stack_b, int put_text)
{
	t_list	*old_first_node;
	t_list	*old_last_node;
	t_list	*penultimate;

	if (!stack_b || !(*stack_b)->next)
		return ;
	old_first_node = *stack_b;
	old_last_node = ft_lstlast(*stack_b);
	penultimate = old_last_node->previous;
	penultimate->next = NULL;
	(*stack_b)->previous = NULL;
	(*stack_b)->next = old_first_node;
	old_first_node->previous = *stack_b;
	if (put_text)
		write(1, "rra\n", 4);
}

void	rotateab_or_reverseab(t_list **stack_a, t_list **stack_b, int each)
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
