/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 15:59:52 by aborda            #+#    #+#             */
/*   Updated: 2026/07/12 12:04:15 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_closed(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (ft_strchr("0NSEW", game->map[i][j]) != NULL)
			{
				if (is_valid_pos(game, game->map, j + 1, i) == -1)
					return (0);
				if (is_valid_pos(game, game->map, j - 1, i) == -1)
					return (0);
				if (is_valid_pos(game, game->map, j, i + 1) == -1)
					return (0);
				if (is_valid_pos(game, game->map, j, i - 1) == -1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
