/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_check_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:43:45 by aborda            #+#    #+#             */
/*   Updated: 2026/07/08 08:27:36 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_check_elements(t_game *game)
{
	if (game->texture_path_no == NULL
		|| game->texture_path_so == NULL
		|| game->texture_path_we == NULL
		|| game->texture_path_ea == NULL
		|| game->color_floor.r == -1
		|| game->color_ceil.r == -1)
		return (0);
	return (1);
}
