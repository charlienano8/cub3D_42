/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:48:07 by aborda            #+#    #+#             */
/*   Updated: 2026/07/06 10:29:43 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	store_texture_line(char *current_line, char **path, int fd, int i)
{
	char	*trimed_current_line;

	trimed_current_line = ft_strtrim(current_line + i, "\n ");
	if (trimed_current_line == NULL)
	{
		msg(ERR_MALLOC);
		free(current_line);
		close(fd);
		return (1);
	}
	*path = trimed_current_line;
	return (0);
}

static int	store_color(char *current_line, t_color *colors, int i)
{
	colors->r = ft_atoi(&current_line[i]);
	while (current_line[i] != ',')
		i++;
	i++;
	colors->g = ft_atoi(&current_line[i]);
	while (current_line[i] != ',')
		i++;
	i++;
	colors->b = ft_atoi(&current_line[i]);
	return (0);
}

static int	dispatch_textures(char *current_line, int fd, char *elements,
		char **path)
{
	int	i;

	if (ft_strncmp(current_line, elements, ft_strlen(elements)) == 0)
	{
		i = 0;
		while (!ft_isspace(current_line[i]))
			i++;
		while (ft_isspace(current_line[i]))
			i++;
		if (*path != NULL)
			return (free(current_line), free(*path), close(fd), msg(ERR_DOUBLE_KEY));
		if (store_texture_line(current_line, path, fd, i))
			return (1);
	}
	return (0);
}

static int	dispatch_colors(char *current_line, int fd, char *elements,
		t_color *color)
{
	int	i;

	if (ft_strncmp(current_line, elements, ft_strlen(elements)) == 0)
	{
		i = 0;
		while (!ft_isspace(current_line[i]))
			i++;
		while (ft_isspace(current_line[i]))
			i++;
		if (color->r != -1)
			return (free(current_line), close(fd), msg(ERR_DOUBLE_KEY));
		if (store_color(current_line, color, i))
			return (1);
	}
	return (0);
}

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
			if (dispatch_textures(current_line, fd, "NO", &game->texture_path_no))
				return (1);
			if (dispatch_textures(current_line, fd, "SO", &game->texture_path_so))
				return (1);
			if (dispatch_textures(current_line, fd, "WE", &game->texture_path_we))
				return (1);
			if (dispatch_textures(current_line, fd, "EA", &game->texture_path_ea))
				return (1);
			if (dispatch_colors(current_line, fd, "F", &game->color_floor))
				return (1);
			if (dispatch_colors(current_line, fd, "C", &game->color_ceil))
				return (1);
		}
		free(current_line);
		current_line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
