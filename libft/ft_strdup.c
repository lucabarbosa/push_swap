/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:31:27 by lbento            #+#    #+#             */
/*   Updated: 2025/09/15 01:35:05 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	size_t	size_s;
	char	*dest;

	size_s = ft_strlen(s) + 1;
	dest = (char *)malloc(size_s * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, (const void *)s, size_s);
	return (dest);
}
