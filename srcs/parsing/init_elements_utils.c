/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:08:55 by aborda            #+#    #+#             */
/*   Updated: 2026/07/08 10:29:48 by aborda           ###   ########.fr       */
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
	if (colors->r < 0 || colors->r > 255)
		return (msg_parse(ERR_ELEMENTS_INVALID_COLOR));
	while (current_line[i] != ',' && current_line[i] != '\0')
		i++;
	if (current_line[i] == '\0')
		return (msg_parse(ERR_ELEMENTS_INVALID_COLOR));
	i++;
	colors->g = ft_atoi(&current_line[i]);
	if (colors->g < 0 || colors->g > 255)
		return (msg_parse(ERR_ELEMENTS_INVALID_COLOR));
	while (current_line[i] != ',' && current_line[i] != '\0')
		i++;
	if (current_line[i] == '\0')
		return (msg_parse(ERR_ELEMENTS_INVALID_COLOR));
	i++;
	colors->b = ft_atoi(&current_line[i]);
	if (colors->b < 0 || colors->b > 255)
		return (msg_parse(ERR_ELEMENTS_INVALID_COLOR));
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
		{
			free(current_line);
			free(*path);
			close(fd);
			return (msg_parse(ERR_DOUBLE_KEY));
		}
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
			return (free(current_line), close(fd), msg_parse(ERR_DOUBLE_KEY));
		if (store_color(current_line, color, i))
			return (1);
	}
	return (0);
}

int	dispatch_elements(t_game *game, char *current_line, int fd)
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
	return (0);
}
