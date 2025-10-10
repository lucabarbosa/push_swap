/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 22:02:31 by lbento            #+#    #+#             */
/*   Updated: 2025/10/10 04:13:28 by lbento           ###   ########.fr       */
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
void	rotate_a(t_stack **stack_a, int put_text);
void	rotate_b(t_stack **stack_b, int put_text);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	listadd_front(t_stack **stack, t_stack *new);
void	include_position(t_stack **stack_a, int size);
void	reverse_rotate_a(t_stack **stack_a, int put_text);
void	reverse_rotate_b(t_stack **stack_b, int put_text);
void	swap_a_and_b(t_stack **stack_a, t_stack **stack_b);
void	algorithm_sort(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size);
void	free_and_exit(t_stack *stack_a, t_stack *stack_b, int exit_num);
void	rotateab_or_reverseab(t_stack **stack_a, t_stack **stack_b, int each);

#endif
