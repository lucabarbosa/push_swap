/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:32:08 by lbento            #+#    #+#             */
/*   Updated: 2025/10/20 17:27:54 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"
# include "../src/push_swap.h"

void		check_bonus_arguments(t_stack **stack_a);
void		read_execute(t_stack **stack_a, t_stack **stack_b);
void		free_and_exit(t_stack *stack_a, t_stack *stack_b, int exit_num);
void		silent_ss_rr_rrr(t_stack **stack_a, t_stack **stack_b, int each);
int			exe_operation(t_stack **stack_a, t_stack **stack_b, char *line);

#endif
