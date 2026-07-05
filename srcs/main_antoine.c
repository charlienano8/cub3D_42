/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_antoine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:32:53 by aborda            #+#    #+#             */
/*   Updated: 2026/07/05 17:32:51 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		ret;

	game.map = NULL;
	if (ac != 2)
		return (msg(ERR_AV));
	if (!is_cub_extension(av[1]))
		return (msg(ERR_CUB_EXTENSION));
	ret = init_game(&game, av[1]);
	if (ret != 0)
		return (free_map(game.map), ret);
	ret = check_map(&game);
	if (ret != 0)
		return (free_map(game.map), ret);
	free_map(game.map);
	return (0);
}
