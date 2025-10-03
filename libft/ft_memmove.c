/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:09:06 by lbento            #+#    #+#             */
/*   Updated: 2025/09/18 19:13:17 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pasted;
	const unsigned char	*copied;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	copied = (const unsigned char *)src;
	pasted = (unsigned char *)dest;
	if (pasted > copied)
		while (n-- > 0)
			pasted[n] = copied [n];
	else
	{
		i = 0;
		while (i < n)
		{
			pasted[i] = copied[i];
			i++;
		}
	}
	return (dest);
}
