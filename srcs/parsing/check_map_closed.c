/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
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
	char	**map_cpy;
	int		i;
	int		j;
	int		ret;

	map_cpy = malloc(sizeof(char *) * (game->line_map_nb + 1));
	if (map_cpy == NULL)
		return (msg(ERR_MALLOC));
	i = 0;
	while (game->map[i])
	{
		map_cpy[i] = ft_strdup(game->map[i]);
		if (map_cpy[i] == NULL)
			return (free_map(map_cpy), msg(ERR_MALLOC));
		i++;
	}
	map_cpy[i] = 0;
	ret = flood_fill(game, map_cpy, (int)game->player_x, (int)game->player_y);
	i = 0;
	while (map_cpy[i])
	{
		j = 0;
		while (map_cpy[i][j])
		{
			if (map_cpy[i][j] == '0')
			{
				if (is_valid_pos(game, map_cpy, j + 1, i) == -1)
					return (free_map(map_cpy), 0);
				if (is_valid_pos(game, map_cpy, j - 1, i) == -1)
					return (free_map(map_cpy), 0);
				if (is_valid_pos(game, map_cpy, j, i + 1) == -1)
					return (free_map(map_cpy), 0);
				if (is_valid_pos(game, map_cpy, j, i - 1) == -1)
					return (free_map(map_cpy), 0);
			}
			j++;
		}
		i++;
	}
	free_map(map_cpy);
	if (ret != 0)
		return (0);
	return (1);
}
