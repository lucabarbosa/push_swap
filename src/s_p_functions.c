/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_p_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:53:19 by lbento            #+#    #+#             */
/*   Updated: 2025/10/08 16:15:41 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a, int put_text);
void	swap_b(t_list **stack_b, int put_text);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	swap_a_and_b(t_list **stack_a, t_list **stack_b);

void	swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a, 1);
	swap_b(stack_b, 1);
	write(1, "ss\n", 3);
}

void		swap_a(t_list **stack_a, int put_text)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	
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
	if (put_text == 0)
		write(1, "sa\n", 3);
}

void		swap_b(t_list **stack_b, int put_text)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	
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
	if (put_text == 0)
		write(1, "sb\n", 3);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list *old_first_a;
	t_list *first_b;
	t_list *second_b;
	
	if (!stack_b || !(*stack_b))
   	return ;

	first_b = *stack_b;
	second_b = first_b -> next;
	*stack_b = second_b;
	if (second_b != NULL)
		second_b->previous = NULL;

	old_first_a = *stack_a;
	ft_lstadd_front(stack_a, first_b);
	if (old_first_a != NULL)
		old_first_a->previous = first_b;
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list *old_first_b;
	t_list *first_a;
	t_list *second_a;
	
	if (!stack_a || !(*stack_a))
   	return ;

	first_a = *stack_a;
	second_a = first_a -> next;
	*stack_a = second_a;
	if (second_a != NULL)
		second_a->previous = NULL;

	old_first_b = *stack_b;
	ft_lstadd_front(stack_b, first_a);
	if (old_first_b != NULL)
		old_first_b->previous = first_a;
	write(1, "pb\n", 3);
}
