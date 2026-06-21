/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 13:52:07 by aborda            #+#    #+#             */
/*   Updated: 2026/06/21 17:34:56 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_map(t_game *game)
{
	char	**map;

	map = malloc(sizeof(char *) * (game->line_map_nb + 1));
	if (map == NULL)
		return (msg(ERR_MALLOC));
	game->map = map;
	return (0);
} 

int	fill_map(t_game  *game, char *file)
{
	char	*current_line;
	char	*trimed_current_line;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (msg(ERR_FD));
	current_line = get_next_line(fd);
	i = 0;
	while (current_line != NULL)
	{
		if (is_map_line(current_line))
		{
			trimed_current_line = ft_strtrim(current_line, "\n");
			if (trimed_current_line == NULL)
			{
				game->map[i] = 0;
				msg(ERR_MALLOC);
				free(current_line);
				close(fd);
				return (1);
			}
			game->map[i] = trimed_current_line;
			i++;
		}
		free(current_line);
		current_line = get_next_line(fd);
	}
	game->map[i] = 0;
	close(fd);
	return (0);
}
