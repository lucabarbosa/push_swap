/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 22:02:31 by lbento            #+#    #+#             */
/*   Updated: 2025/10/08 19:47:58 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_list
{
	int					position;
	int					number;
	struct s_list		*next;
	struct s_list		*previous;
}	t_list;

int		is_sorted(t_list *stack_a);
void	check_arguments(t_list **stack_a);
void	swap_a(t_list **stack_a, int put_text);
void	swap_b(t_list **stack_b, int put_text);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	swap_a_and_b(t_list **stack_a, t_list **stack_b);
void	algorithm_sort(t_list **stack_a, t_list **stack_b);
void	free_and_exit(t_list *stack_a, t_list *stack_b, int exit_num);

#endif
