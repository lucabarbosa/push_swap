/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:49:35 by lbento            #+#    #+#             */
/*   Updated: 2025/07/29 19:04:18 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n);

static size_t	ft_count_dig(int n)
{
	size_t	count;
	long	num;

	count = 0;
	num = n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		count++;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static char	*ft_is_zero(char *result)
{
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char		*result;
	size_t		digits_int;
	size_t		num;

	num = n;
	digits_int = ft_count_dig(n);
	result = (char *)malloc(sizeof(char) * (digits_int + 1));
	if (result == NULL)
		return (NULL);
	if (n == 0)
		return (ft_is_zero(result));
	if (n < 0)
	{
		result[0] = '-';
		num = -num;
	}
	result[digits_int] = '\0';
	while (num > 0)
	{
		digits_int--;
		result[digits_int] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}
