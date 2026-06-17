/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:23:19 by aborda            #+#    #+#             */
/*   Updated: 2025/12/21 11:12:12 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_digits(int n)
{
	size_t	count;

	if (n == INT_MIN)
		return (10);
	if (n < 0)
		n = -n;
	count = 1;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_malloc_size(int n)
{
	int		count;
	long	n_base;

	count = 0;
	n_base = n;
	if (n < 0)
	{
		n = -n;
		count = ft_count_digits(n_base) + 1;
	}
	else
		count = ft_count_digits(n_base);
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	long	n_base;
	long	nb;

	n_base = n;
	nb = n;
	if (n < 0)
		nb = -nb;
	count = ft_count_digits(n_base);
	if (n_base < 0)
		count++;
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	count--;
	while (count >= 0)
	{
		str[count--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n_base < 0)
		str[0] = '-';
	return (str);
}
