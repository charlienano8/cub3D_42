/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:13:49 by aborda            #+#    #+#             */
/*   Updated: 2025/11/19 17:44:08 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_format_type(char c)
{
	char	*correct_types;
	size_t	i;

	correct_types = "cspdiuxX%";
	i = 0;
	if (!c)
		return (0);
	while (correct_types[i])
	{
		if (c == correct_types[i])
			return (c);
		i++;
	}
	return (0);
}

static int	ft_dispatch(char format_type, va_list args, int len)
{
	if (format_type == 'c')
		return (ft_print_char(args, len));
	if (format_type == 's')
		return (ft_print_str(args, len));
	if (format_type == 'p')
		return (ft_print_pointer(args, len));
	if (format_type == 'd')
		return (ft_print_decimal(args, len));
	if (format_type == 'i')
		return (ft_print_decimal(args, len));
	if (format_type == 'u')
		return (ft_print_unsigned_decimal(args, len));
	if (format_type == 'x')
		return (ft_print_hexalower(args, len));
	if (format_type == 'X')
		return (ft_print_hexaupper(args, len));
	if (format_type == '%')
		return (ft_print_percent(len));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t		i;
	int			len;
	va_list		args;

	va_start (args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			i++;
			len++;
		}
		else
		{
			if (ft_get_format_type(format[i + 1]))
				len = ft_dispatch(ft_get_format_type(format[i + 1]), args, len);
			i += 2;
		}
	}
	va_end(args);
	return (len);
}
