/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:23:23 by aborda            #+#    #+#             */
/*   Updated: 2025/11/20 10:30:44 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_decimal(va_list args, int len)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	ft_putunsignedint_fd(i, 1);
	len += ft_unsignedint_len(i);
	return (len);
}
