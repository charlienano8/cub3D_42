/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:08:55 by aborda            #+#    #+#             */
/*   Updated: 2026/07/12 08:45:57 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	store_texture_line(char *current_line, char **path, int i)
{
	char	*trimed_current_line;

	trimed_current_line = ft_strtrim(current_line + i, "\n ");
	if (trimed_current_line == NULL)
		return (msg(ERR_MALLOC));
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

static int	dispatch_textures(char *current_line, char *elements,
		char **path)
{
	int	i;

	if (ft_strncmp(current_line, elements, ft_strlen(elements)) == 0)
	{
		i = 0;
		while (current_line[i] && !ft_isspace(current_line[i]))
			i++;
		while (ft_isspace(current_line[i]))
			i++;
		if (*path != NULL)
		{
			free(*path);
			*path = NULL;
			return (msg_parse(ERR_DOUBLE_KEY));
		}
		if (store_texture_line(current_line, path, i))
			return (1);
	}
	return (0);
}

static int	dispatch_colors(char *current_line, char *elements,
		t_color *color)
{
	int	i;

	if (ft_strncmp(current_line, elements, ft_strlen(elements)) == 0)
	{
		i = 0;
		while (current_line[i] && !ft_isspace(current_line[i]))
			i++;
		while (ft_isspace(current_line[i]))
			i++;
		if (color->r != -1)
			return (msg_parse(ERR_DOUBLE_KEY));
		if (store_color(current_line, color, i))
			return (1);
	}
	return (0);
}

int	dispatch_elements(t_game *game, char *current_line)
{
	if (dispatch_textures(current_line, "NO", &game->texture_path_no))
		return (1);
	if (dispatch_textures(current_line, "SO", &game->texture_path_so))
		return (1);
	if (dispatch_textures(current_line, "WE", &game->texture_path_we))
		return (1);
	if (dispatch_textures(current_line, "EA", &game->texture_path_ea))
		return (1);
	if (dispatch_colors(current_line, "F", &game->color_floor))
		return (1);
	if (dispatch_colors(current_line, "C", &game->color_ceil))
		return (1);
	return (0);
}
