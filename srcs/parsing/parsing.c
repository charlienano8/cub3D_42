/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:32:53 by aborda            #+#    #+#             */
/*   Updated: 2026/07/09 08:22:54 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(t_game *game, char **av)
{
	int		ret;

	if (!is_cub_extension(av[1]))
		return (msg(ERR_CUB_EXTENSION));
	ret = init_game(game, av[1]);
	if (ret != 0)
		return (free_game(game), ret);
	ret = check_map(game);
	if (ret != 0)
		return (free_game(game), ret);
	init_cameras(game);
	return (0);
}
