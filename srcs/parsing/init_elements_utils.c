/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:08:55 by aborda            #+#    #+#             */
/*   Updated: 2026/07/12 10:10:54 by aborda           ###   ########.fr       */
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

static int	is_element_prefix(char *current_line, char *elements)
{
	return (ft_strncmp(current_line, elements, ft_strlen(elements)) == 0
		&& ft_isspace(current_line[ft_strlen(elements)]));
}

static int	dispatch_textures(char *current_line, char *elements,
		char **path)
{
	int	i;

	if (is_element_prefix(current_line, elements))
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

	if (is_element_prefix(current_line, elements))
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
	if (current_line[0] != '\n'
		&& !is_element_prefix(current_line, "NO")
		&& !is_element_prefix(current_line, "SO")
		&& !is_element_prefix(current_line, "WE")
		&& !is_element_prefix(current_line, "EA")
		&& !is_element_prefix(current_line, "F")
		&& !is_element_prefix(current_line, "C"))
		return (msg_parse(ERR_UNKNOWN_DIRECTIVE));
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
