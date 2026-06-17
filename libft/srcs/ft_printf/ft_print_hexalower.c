/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexalower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:23:23 by aborda            #+#    #+#             */
/*   Updated: 2025/11/19 18:05:24 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex(unsigned int n)
{
	size_t	count;
	size_t	mod;
	char	c;

	count = 0;
	mod = n % 16;
	if (n >= 16)
	{
		count = ft_print_hex(n / 16);
	}
	if (mod < 10)
		c = mod + '0';
	else
		c = mod - 10 + 'a';
	write (1, &c, 1);
	return (count + 1);
}

int	ft_print_hexalower(va_list args, int len)
{
	unsigned int	n;
	int				size;

	n = va_arg(args, unsigned int);
	size = ft_print_hex(n);
	len += size;
	return (len);
}
