/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:08:26 by aborda            #+#    #+#             */
/*   Updated: 2026/07/12 11:06:44 by aborda           ###   ########.fr       */
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
	else if (msg_code == ERR_FD)
		ft_putstr_fd("Error, file open failed\n", 2);
	else if (msg_code == ERR_GNL)
		ft_putstr_fd("Error, GNL failed\n", 2);
	else if (msg_code == ERR_MLX)
		ft_putstr_fd("Error, mlx failed\n", 2);
	else if (msg_code == ERR_XPM_TEXTURES)
		ft_putstr_fd("Error, Failed to load XPM textures\n", 2);
	return (1);
}

int	msg_parse(t_msg msg_code)
{
	if (msg_code == ERR_VALID_MAP_CHARS)
		ft_putstr_fd("Error, map chars invalid\n", 2);
	else if (msg_code == ERR_VALID_MAP_PLAYER)
		ft_putstr_fd("Error, map player invalid\n", 2);
	else if (msg_code == ERR_VALID_MAP_CLOSED)
		ft_putstr_fd("Error, map not closed\n", 2);
	else if (msg_code == ERR_VALID_MAP_END)
		ft_putstr_fd("Error, map is not at the end\n", 2);
	else if (msg_code == ERR_DOUBLE_KEY)
		ft_putstr_fd("Error, double key\n", 2);
	else if (msg_code == ERR_ELEMENTS_MISSING)
		ft_putstr_fd("Error, elements is missing\n", 2);
	else if (msg_code == ERR_ELEMENTS_INVALID_COLOR)
		ft_putstr_fd("Error, invalid color value\n", 2);
	else if (msg_code == ERR_ELEMENTS_INVALID_TEXTURE_PATH)
		ft_putstr_fd("Error, invalid texture path\n", 2);
	else if (msg_code == ERR_UNKNOWN_DIRECTIVE)
		ft_putstr_fd("Error, unknown directive\n", 2);
	return (1);
}
