/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:26:37 by lbento            #+#    #+#             */
/*   Updated: 2025/10/08 22:27:02 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*creation_list(int argc, char **argv);
static t_list	*init_first_node(char *argv);
static int		check_num(t_list *stack_a, char *argv);
void			free_and_exit(t_list *stack_a, t_list *stack_b, int exit_num);

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc != 1)
	{
		stack_a = creation_list(argc, argv);
		stack_b = NULL;
		check_arguments(&stack_a);
		algorithm_sort(stack_a, stack_b);
		free_and_exit(stack_a, stack_b, 0);
	}
	return (0);
}

static t_list	*creation_list(int argc, char **argv)
{
	t_list	*first_node;
	t_list	*nodes;
	t_list	*temp;
	int		i;
	int		num;

	first_node = init_first_node(argv[1]);
	temp = first_node;
	i = 2;
	while (i < argc)
	{
		nodes = (t_list *)malloc(sizeof(t_list));
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

static t_list	*init_first_node(char *argv)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		free_and_exit(NULL, NULL, 1);
	node->number = check_num(&node, argv);
	node->position = -1;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

static int	check_num(t_list *stack_a, char *argv)
{
	int	total;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
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

void	free_and_exit(t_list *stack_a, t_list *stack_b, int exit_num)
{
	t_list	*temp;

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
		ft_putendl_fd("Error\n", 2);
		exit(1);
	}
	else
		exit(0);
}
