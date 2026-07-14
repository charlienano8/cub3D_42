/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 21:17:48 by aborda            #+#    #+#             */
/*   Updated: 2026/07/12 21:17:51 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_component(char *current_line, int *i, int *value)
{
	int	result;
	int	count;

	result = 0;
	count = 0;
	while (ft_isdigit(current_line[*i]))
	{
		result = result * 10 + (current_line[*i] - '0');
		(*i)++;
		count++;
		if (count > 3)
			return (1);
	}
	if (count == 0)
		return (1);
	if (result < 0 || result > 255)
		return (1);
	*value = result;
	return (0);
}

int	store_color(char *current_line, t_color *colors, int i)
{
	if (parse_component(current_line, &i, &colors->r))
		return (msg_parse(ERR_ELEMENTS_INVALID_COLOR));
	if (current_line[i] != ',')
		return (msg_parse(ERR_ELEMENTS_INVALID_COLOR));
	i++;
	if (parse_component(current_line, &i, &colors->g))
		return (msg_parse(ERR_ELEMENTS_INVALID_COLOR));
	if (current_line[i] != ',')
		return (msg_parse(ERR_ELEMENTS_INVALID_COLOR));
	i++;
	if (parse_component(current_line, &i, &colors->b))
		return (msg_parse(ERR_ELEMENTS_INVALID_COLOR));
	if (current_line[i] != '\n' && current_line[i] != '\0')
		return (msg_parse(ERR_ELEMENTS_INVALID_COLOR));
	return (0);
}
