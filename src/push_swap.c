/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:26:37 by lbento            #+#    #+#             */
/*   Updated: 2025/10/06 01:10:12 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list *creation_list(int argc, char **argv);
void free_and_exit(t_list **stack_a, t_list **stack_b, int exit_num);
static void check_num (t_list *stack_a, int nbr);

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	if (argc != 1)
	{
		stack_a = creation_list(argc, argv);
		stack_b = NULL;
	}
	return (0);
}

static t_list *creation_list(int argc, char **argv)
{
	t_list *first_list;
	t_list *list;
	t_list *temp;
	int i;
	int num;

	first_list = (t_list *)malloc(sizeof(t_list));
	if (!first_list)
		free_and_exit(NULL, NULL, 1);
	i = 1;
	while (i < argc)
	{
		list = (t_list *)malloc(sizeof(t_list));
		num = ft_atoi(argv[i]);
		check_num(&first_list, num);
		list->number = num;
		list->position = -1;
		list->previous = temp;
		temp->next = list;
		temp = list;
		i++;
	}
	return (first_list);
}

static void check_num (t_list *stack_a, int nbr)
{
	if (nbr >= 2147483648)
		free_and_exit(stack_a, NULL, 1);
	if (nbr < -2147483648)
		free_and_exit(stack_a, NULL, 1);
}


void free_and_exit(t_list **stack_a, t_list **stack_b, int exit_num)
{
	t_list *list;
	t_list *temp;

	list = *stack_a;
	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	list = *stack_b;
	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	if(exit_num == 0)
		exit(0);
	if(exit_num == 1)
		exit(1);
}
