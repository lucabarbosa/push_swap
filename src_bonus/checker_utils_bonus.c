/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:28:33 by lbento            #+#    #+#             */
/*   Updated: 2025/10/15 13:39:18 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_bonus_arguments(t_stack **stack_a);
void	read_execute(t_stack **stack_a, t_stack **stack_b);
int	execute_operation(t_stack **stack_a, t_stack **stack_b, char *line);
static void	silent_ss(t_stack **stack_a, t_stack **stack_b);
static void silent_rr_rrr(t_stack **stack_a, t_stack **stack_b, int each);

void	check_bonus_arguments(t_stack **stack_a)
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
		{
			ft_putendl_fd("OK", 1);
			free_and_exit(*stack_a, NULL, 0);
		}
}

void	read_execute(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int	result;

	line = get_next_line(0);
	while (line != NULL)
	{
		result = execute_operation(stack_a, stack_b, line);
		if (result)
		{
			free(line);
			free_and_exit(*stack_a, *stack_b, 1);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	execute_operation(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		return (swap_a(stack_a, 0), 0);
	else if (ft_strncmp(line, "sb", 2) == 0)
		return (swap_b(stack_b, 0), 0);
	else if (ft_strncmp(line, "ss", 2) == 0)
		return (silent_ss(stack_a, stack_b), 0);
	else if (ft_strncmp(line, "pa", 2) == 0)
		push_a(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "pb", 2) == 0)
		push_b(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "ra", 2) == 0)
		rotate_a(stack_a, 0);
	else if (ft_strncmp(line, "rb", 2) == 0)
		rotate_b(stack_b, 0);
	else if (ft_strncmp(line, "rr", 2) == 0)
		silent_rr_rrr(stack_a, stack_b, 1);
	else if (ft_strncmp(line, "rra", 3) == 0)
		reverse_rotate_a(stack_a, 0);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		reverse_rotate_b(stack_b, 0);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		silent_rr_rrr(stack_a, stack_b, 2);
	else
		return (1);
}

static void	silent_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
}

static void silent_rr_rrr(t_stack **stack_a, t_stack **stack_b, int each)
{
	if (each == 1)
	{
		rotate_a(stack_a, 0);
		rotate_b(stack_b, 0);
	}
	if (each == 2)
	{
		reverse_rotate_a(stack_a, 0);
		reverse_rotate_b(stack_b, 0);
	}
}