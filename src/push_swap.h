/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 22:02:31 by lbento            #+#    #+#             */
/*   Updated: 2025/10/09 19:55:26 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_stack
{
	int					position;
	int					number;
	struct s_stack		*next;
	struct s_stack		*previous;
}	t_stack;

int		list_size(t_stack *stack);
t_stack	*list_last(t_stack *stack);
int		is_sorted(t_stack *stack_a);
void	check_arguments(t_stack **stack_a);
void	swap_a(t_stack **stack_a, int put_text);
void	swap_b(t_stack **stack_b, int put_text);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	swap_a_and_b(t_stack **stack_a, t_stack **stack_b);
void	algorithm_sort(t_stack **stack_a, t_stack **stack_b);
void	free_and_exit(t_stack *stack_a, t_stack *stack_b, int exit_num);
void	algorithm_sort(t_stack **stack_a, t_stack **stack_b);
void	include_position(t_stack **stack_a, int size);

#endif
