/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:48:07 by aborda            #+#    #+#             */
/*   Updated: 2026/07/12 11:00:43 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_elements(t_game *game, char *file)
{
	char	*current_line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (msg(ERR_FD));
	current_line = get_next_line(fd);
	while (current_line != NULL)
	{
		if (!is_map_line(current_line))
		{
			if (dispatch_elements(game, current_line))
			{
				free(current_line);
				close(fd);
				return (1);
			}
		}
		free(current_line);
		current_line = get_next_line(fd);
	}
	close(fd);
	if (check_elements(game))
		return (1);
	return (0);
}
