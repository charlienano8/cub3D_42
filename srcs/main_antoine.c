/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_antoine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:32:53 by aborda            #+#    #+#             */
/*   Updated: 2026/06/21 18:13:31 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (msg(ERR_AV));
	if (!is_cub_extension(av[1]))
		return (msg(ERR_CUB_EXTENSION));
	if (init_game(&game, av[1]))
		return (1);
	return (0);
}
