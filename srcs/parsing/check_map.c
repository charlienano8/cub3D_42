/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 16:24:07 by aborda            #+#    #+#             */
/*   Updated: 2026/07/08 09:37:19 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_game *game)
{
	if (!is_valid_map_chars(game))
		return (msg_parse(ERR_VALID_MAP_CHARS));
	if (!is_valid_map_player(game))
		return (msg_parse(ERR_VALID_MAP_PLAYER));
	if (!is_valid_map_closed(game))
		return (msg_parse(ERR_VALID_MAP_CLOSED));
	return (0);
}
