/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:08:26 by aborda            #+#    #+#             */
/*   Updated: 2026/06/18 16:18:20 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "messages.h"

int	msg(t_msg msg_code)
{
	if (msg_code == ERR_BASE)
		ft_putstr_fd("Error\n", 2);
	else if (msg_code == ERR_AV)
		ft_putstr_fd("Error, exactly one argument required\n", 2);
	else if (msg_code == ERR_CUB_EXTENSION)
		ft_putstr_fd("Error, file is not a .cub\n", 2);
	else if (msg_code == ERR_MALLOC)
		ft_putstr_fd("Error, malloc failed\n", 2);
	else if (msg_code == ERR_MLX)
		ft_putstr_fd("Error, mlx failed\n", 2);
	return (1);
}
