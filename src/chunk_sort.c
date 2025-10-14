/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:00:00 by lbento            #+#    #+#             */
/*   Updated: 2025/10/14 18:11:22 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_stack **a, t_stack **b, int size);
static void	push_chunk(t_stack **a, t_stack **b, int low, int high);
static int	get_hold_position(t_stack *stack, int low, int high, int from_top);
static void	sort_back(t_stack **a, t_stack **b, int size);
static int	get_target_dist(t_stack *stack, int target_pos);

void	chunk_sort(t_stack **a, t_stack **b, int size)
{
	int	num_chunks;
	int	chunk_size;
	int	i;
	int	low;
	int	high;

	if (size <= 100)
		num_chunks = 5;
	else
		num_chunks = 10;
	chunk_size = size / num_chunks;
	i = 0;
	while (i < num_chunks)
	{
		low = i * chunk_size;
		high = low + chunk_size - 1;
		if (i == num_chunks - 1)
			high = size - 1;
		push_chunk(a, b, low, high);
		i++;
	}
	sort_back(a, b, size);
}

static int	get_hold_position(t_stack *stack, int low, int high, int from_top)
{
	int		dist;
	t_stack	*curr;

	dist = 0;
	if (from_top)
		curr = stack;
	else
		curr = list_last(stack);
	while (curr)
	{
		if (curr->position >= low && curr->position <= high)
			return (dist);
		dist++;
		if (from_top)
			curr = curr->next;
		else
			curr = curr->previous;
	}
	return (-1);
}

static void push_chunk(t_stack **a, t_stack **b, int low, int high)
{
   int hold_top;
	int hold_bottom;
	int mid;
	int moved;
	
	moved = 0;
   while (1)
   {
		hold_top = get_hold_position(*a, low, high, 1);
		hold_bottom = list_size(*a) - 1 - get_hold_position(*a, low, high, 0);
		if (hold_top == -1 || hold_bottom == -1)
			break;
		if (hold_top <= hold_bottom)
			while (hold_top-- > 0)
				rotate_a(a, 1);
		else
			while (hold_bottom-- > 0)
				reverse_rotate_a(a, 1);
		push_b(a, b);
		moved++;
		mid = low + (high - low) / 2;
		if ((*b)->position <= mid)
			rotate_b(b, 1);
	}
}

static void sort_back(t_stack **a, t_stack **b, int size)
{
	int max_pos;
   
	max_pos = size - 1;
	while (*b)
   {
		int dist = get_target_dist(*b, max_pos);
      int b_size = list_size(*b);
      if (dist <= b_size / 2)
      	while (dist-- > 0)
				rotate_b(b, 1);
      else
      {
			dist = b_size - dist;
         while (dist-- > 0)
				reverse_rotate_b(b, 1);
		}
      push_a(a, b);
      max_pos--;
   }
}

static int	get_target_dist(t_stack *stack, int target_pos)
{
	int		dist;
	t_stack	*curr;

	dist = 0;
	curr = stack;
	while (curr)
	{
		if (curr->position == target_pos)
			return (dist);
		dist++;
		curr = curr->next;
	}
	return (-1);
}
