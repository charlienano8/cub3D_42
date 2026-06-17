/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:17:03 by aborda            #+#    #+#             */
/*   Updated: 2026/02/09 14:39:28 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_print_char(va_list args, int len);
int		ft_print_str(va_list args, int len);
int		ft_print_pointer(va_list args, int len);
int		ft_print_decimal(va_list args, int len);
int		ft_print_unsigned_decimal(va_list args, int len);
int		ft_print_hexalower(va_list args, int len);
int		ft_print_hexaupper(va_list args, int len);
int		ft_print_percent(int len);

#endif
