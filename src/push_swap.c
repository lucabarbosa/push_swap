/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:26:37 by lbento            #+#    #+#             */
/*   Updated: 2025/10/09 22:12:12 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*creation_list(int argc, char **argv);
static t_stack	*init_first_node(char *argv);
static int		check_num(t_stack *stack_a, char *argv);
void			free_and_exit(t_stack *stack_a, t_stack *stack_b, int exit_num);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc != 1)
	{
		stack_a = creation_list(argc, argv);
		stack_b = NULL;
		check_arguments(&stack_a);
		algorithm_sort(&stack_a, &stack_b);
		free_and_exit(stack_a, stack_b, 0);
	}
	return (0);
}

static t_stack	*creation_list(int argc, char **argv)
{
	t_stack	*first_node;
	t_stack	*nodes;
	t_stack	*temp;
	int		i;

	first_node = init_first_node(argv[1]);
	temp = first_node;
	i = 2;
	while (i < argc)
	{
		nodes = (t_stack *)malloc(sizeof(t_stack));
		if (!nodes)
			free_and_exit(first_node, NULL, 1);
		nodes->number = check_num(first_node, argv[i]);
		nodes->position = -1;
		nodes->previous = temp;
		temp->next = nodes;
		temp = nodes;
		i++;
	}
	return (first_node);
}

static t_stack	*init_first_node(char *argv)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		free_and_exit(NULL, NULL, 1);
	node->number = check_num(node, argv);
	node->position = -1;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

static int	check_num(t_stack *stack_a, char *argv)
{
	long	total;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	total = 0;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			sign = -1;
		i++;
	}
	if (argv[i] == '\0')
		free_and_exit(stack_a, NULL, 1);
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		total = (argv[i] - '0') + (total * 10);
		if ((total > 2147483647) || (total > 2147483648 && sign == -1))
			free_and_exit(stack_a, NULL, 1);
		i++;
	}
	if (argv[i] != '\0')
		free_and_exit(stack_a, NULL, 1);
	return ((int)total * sign);
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
