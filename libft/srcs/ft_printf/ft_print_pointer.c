/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:23:23 by aborda            #+#    #+#             */
/*   Updated: 2025/11/19 18:06:20 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conv_dectohex_lower(unsigned long n)
{
	size_t	count;
	size_t	mod;
	char	c;

	count = 0;
	mod = n % 16;
	if (n >= 16)
	{
		count = ft_conv_dectohex_lower(n / 16);
	}
	if (mod < 10)
		c = mod + '0';
	else
		c = mod - 10 + 'a';
	write (1, &c, 1);
	return (count + 1);
}

int	ft_print_pointer(va_list args, int len)
{
	unsigned long	n;
	int				size;

	n = va_arg(args, unsigned long);
	if (!n)
	{
		ft_putstr_fd("(nil)", 1);
		return (len + 5);
	}
	ft_putstr_fd("0x", 1);
	size = ft_conv_dectohex_lower(n) + 2;
	len += size;
	return (len);
}
