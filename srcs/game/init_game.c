/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:09:08 by aborda            #+#    #+#             */
/*   Updated: 2026/06/21 17:28:34 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_game(char *file)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (msg(ERR_MALLOC));
	game->line_map_nb = line_map_count(file);
	return (0);
}
