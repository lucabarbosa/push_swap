/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:26:15 by lbento            #+#    #+#             */
/*   Updated: 2025/08/01 14:49:38 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_one;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		next_one = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next_one;
	}
}
