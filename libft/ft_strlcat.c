/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:40:45 by lbento            #+#    #+#             */
/*   Updated: 2025/09/15 01:35:23 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t limit);

size_t	ft_strlcat(char *dest, const char *src, size_t limit)
{
	size_t	i;
	size_t	size_dest;
	size_t	size_src;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (limit <= size_dest)
		return (limit + size_src);
	i = 0;
	while ((src[i] != '\0') && ((i < limit - size_dest - 1)))
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (size_dest + size_src);
}
