/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:23:23 by aborda            #+#    #+#             */
/*   Updated: 2025/11/20 10:11:25 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(va_list args, int len)
{
	long	i;

	i = va_arg(args, int);
	if (i == -2147483648)
	{
		ft_putnbr_fd(i, 1);
		return (len += 11);
	}
	ft_putnbr_fd(i, 1);
	len += ft_intlen(i);
	return (len);
}
