/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:43:45 by aborda            #+#    #+#             */
/*   Updated: 2026/07/08 16:27:48 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_elements(t_game *game)
{
	int	fd;

	if (game->texture_path_no == NULL
		|| game->texture_path_so == NULL
		|| game->texture_path_we == NULL
		|| game->texture_path_ea == NULL
		|| game->color_floor.r == -1
		|| game->color_ceil.r == -1)
		return (msg_parse(ERR_ELEMENTS_MISSING));
	fd = open(game->texture_path_no, O_RDONLY);
	if (fd == -1)
		return (msg_parse(ERR_ELEMENTS_INVALID_TEXTURE_PATH));
	close(fd);
	fd = open(game->texture_path_so, O_RDONLY);
	if (fd == -1)
		return (msg_parse(ERR_ELEMENTS_INVALID_TEXTURE_PATH));
	close(fd);
	fd = open(game->texture_path_we, O_RDONLY);
	if (fd == -1)
		return (msg_parse(ERR_ELEMENTS_INVALID_TEXTURE_PATH));
	close(fd);
	fd = open(game->texture_path_ea, O_RDONLY);
	if (fd == -1)
		return (msg_parse(ERR_ELEMENTS_INVALID_TEXTURE_PATH));
	return (close(fd), 0);
}
