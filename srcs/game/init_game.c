/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:09:08 by aborda            #+#    #+#             */
/*   Updated: 2026/06/22 08:34:46 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_game(t_game *game, char *file)
{
	int	ret;

	game->line_map_nb = line_map_count(file);
	if (game->line_map_nb == -1)
		return (msg(ERR_FD));
	ret = create_map(game);
	if (ret != 0)
		return (ret);
	ret = fill_map(game, file);
	if (ret != 0)
		return (ret);
	return (0);
}
