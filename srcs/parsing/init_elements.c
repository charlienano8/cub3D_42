/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:48:07 by aborda            #+#    #+#             */
/*   Updated: 2026/07/08 09:36:05 by aborda           ###   ########.fr       */
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
			if (dispatch_elements(game, current_line, fd))
				return (1);
		free(current_line);
		current_line = get_next_line(fd);
	}
	close(fd);
	if (!is_check_elements(game))
		return (msg_parse(ERR_ELEMENTS_MISSING));
	return (0);
}
