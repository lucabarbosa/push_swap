/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:28:15 by lbento            #+#    #+#             */
/*   Updated: 2025/10/20 17:24:31 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_stack	*creation_list(int argc, char **argv);
static t_stack	*init_first_node(char *argv);
static int		check_num(t_stack *stack_a, char *argv);
static int		verify_result(t_stack *stack_a, t_stack *stack_b);

int	main(int argc, char **argv)
{
	t_stack	*bonus_a;
	t_stack	*bonus_b;
	int		result;

	if (argc != 1)
	{
		bonus_a = creation_list(argc, argv);
		bonus_b = NULL;
		check_bonus_arguments(&bonus_a);
		read_execute(&bonus_a, &bonus_b);
		result = verify_result (bonus_a, bonus_b);
		if (result)
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
		free_and_exit(bonus_a, bonus_b, 0);
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
		nodes->number = 0;
		nodes->position = -1;
		nodes->previous = temp;
		temp->next = nodes;
		nodes->number = check_num(first_node, argv[i]);
		temp = nodes;
		i++;
	}
	temp->next = NULL;
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
	long	num;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	num = 0;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			sign = -1;
		i++;
	}
	if (!(argv[i] >= '0' && argv[i] <= '9'))
		free_and_exit(stack_a, NULL, 1);
	while (argv[i])
	{
		if ((argv[i] < '0' || argv[i] > '9'))
			free_and_exit(stack_a, NULL, 1);
		num = (argv[i] - '0') + (num * 10);
		if ((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
			free_and_exit(stack_a, NULL, 1);
		i++;
	}
	return ((int)num * sign);
}

static int	verify_result(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b != NULL)
		return (0);
	if (stack_a == NULL)
		return (0);
	if (is_sorted(stack_a) == 1)
		return (1);
	return (0);
}
