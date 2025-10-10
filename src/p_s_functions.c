/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:53:19 by lbento            #+#    #+#             */
/*   Updated: 2025/10/09 21:42:20 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack_a, int put_text);
void	swap_b(t_stack **stack_b, int put_text);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	swap_a_and_b(t_stack **stack_a, t_stack **stack_b);

void	swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	write(1, "ss\n", 3);
}

void	swap_a(t_stack **stack_a, int put_text)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	third = second->next;
	*stack_a = second;
	first->next = third;
	first->previous = second;
	second->next = first;
	second->previous = NULL;
	if (third != NULL)
		third->previous = first;
	if (put_text)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack_b, int put_text)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	third = second->next;
	*stack_b = second;
	first->next = third;
	first->previous = second;
	second->next = first;
	second->previous = NULL;
	if (third != NULL)
		third->previous = first;
	if (put_text)
		write(1, "sb\n", 3);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*old_first_a;
	t_stack	*first_b;
	t_stack	*second_b;

	if (!stack_b || !(*stack_b))
		return ;
	first_b = *stack_b;
	second_b = first_b -> next;
	*stack_b = second_b;
	if (second_b != NULL)
		second_b->previous = NULL;
	old_first_a = *stack_a;
	listadd_front(stack_a, first_b);
	if (old_first_a != NULL)
		old_first_a->previous = first_b;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*old_first_b;
	t_stack	*first_a;
	t_stack	*second_a;

	if (!stack_a || !(*stack_a))
		return ;
	first_a = *stack_a;
	second_a = first_a -> next;
	*stack_a = second_a;
	if (second_a != NULL)
		second_a->previous = NULL;
	old_first_b = *stack_b;
	listadd_front(stack_b, first_a);
	if (old_first_b != NULL)
		old_first_b->previous = first_a;
	write(1, "pb\n", 3);
}
