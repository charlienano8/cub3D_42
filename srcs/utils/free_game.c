/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 12:40:55 by aborda            #+#    #+#             */
/*   Updated: 2026/07/08 09:04:37 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_game *game)
{
	free(game->texture_path_no);
	free(game->texture_path_so);
	free(game->texture_path_we);
	free(game->texture_path_ea);
	free_map(game->map);
}
