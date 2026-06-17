/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:59:01 by aborda            #+#    #+#             */
/*   Updated: 2025/12/21 10:32:43 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_longlen(long d)
{
	long	d_base;
	size_t	i;

	d_base = d;
	i = 1;
	if (d == LONG_MIN)
		return (20);
	if (d < 0)
		d = -d;
	while (d >= 10)
	{
		d = d / 10;
		i++;
	}
	if (d_base < 0)
		i += 1;
	return (i);
}
