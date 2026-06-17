/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:23:23 by aborda            #+#    #+#             */
/*   Updated: 2025/11/18 16:57:31 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args, int len)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	len += 1;
	return (len);
}
