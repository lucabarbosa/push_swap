/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:28:33 by lbento            #+#    #+#             */
/*   Updated: 2025/10/16 02:07:55 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void			read_execute(t_stack **stack_a, t_stack **stack_b);
int				exe_operation(t_stack **stack_a, t_stack **stack_b, char *line);
static void		silent_ss(t_stack **stack_a, t_stack **stack_b);
static void		silent_rr_rrr(t_stack **stack_a, t_stack **stack_b, int each);
void			free_and_exit(t_stack *stack_a, t_stack *stack_b, int exit_num);

void	read_execute(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		result;

	line = get_next_line(0);
	while (line != NULL)
	{
		result = exe_operation(stack_a, stack_b, line);
		if (result == 1)
		{
			free(line);
			free_and_exit(*stack_a, *stack_b, 1);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	exe_operation(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		return (swap_a(stack_a, 0), 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		return (swap_b(stack_b, 0), 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		return (silent_ss(stack_a, stack_b), 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		return (push_a(stack_a, stack_b, 0), 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		return (push_b(stack_a, stack_b, 0), 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		return (rotate_a(stack_a, 0), 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		return (rotate_b(stack_b, 0), 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		return (silent_rr_rrr(stack_a, stack_b, 1), 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		return (reverse_rotate_a(stack_a, 0), 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		return (reverse_rotate_b(stack_b, 0), 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		return (silent_rr_rrr(stack_a, stack_b, 2), 0);
	else
		return (1);
}

static void	silent_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
}

static void	silent_rr_rrr(t_stack **stack_a, t_stack **stack_b, int each)
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

void	free_and_exit(t_stack *stack_a, t_stack *stack_b, int exit_num)
{
	t_stack	*temp;

	while (stack_a)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
	while (stack_b)
	{
		temp = stack_b;
		stack_b = stack_b->next;
		free(temp);
	}
	if (exit_num)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	else
		exit(0);
}