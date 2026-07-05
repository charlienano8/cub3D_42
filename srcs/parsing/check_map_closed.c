/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 15:59:52 by aborda            #+#    #+#             */
/*   Updated: 2026/07/05 16:08:29 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_map_closed(t_game *game)
{
	char	**map_cpy;
	int		i;
	int		ret;

	map_cpy = malloc(sizeof(char *) * (game->line_map_nb + 1));
	if (map_cpy == NULL)
		return (msg(ERR_MALLOC));
	i = 0;
	while (game->map[i])
	{
		map_cpy[i] = ft_strdup(game->map[i]);
		if (map_cpy[i] == NULL)
			return (msg(ERR_MALLOC));
		i++;
	}
	map_cpy[i] = 0;
	ret = flood_fill(game, map_cpy, (int)game->player_x, (int)game->player_y);
	free_map(map_cpy);
	if (ret != 0)
		return (0);
	if (ret == 0)
		return (1);
	return (0);
}
