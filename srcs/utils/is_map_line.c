/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 11:33:17 by aborda            #+#    #+#             */
/*   Updated: 2026/06/21 15:51:54 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	starts_with_ignore_case(char *line, char *prefix)
{
	int	i;

	i = 0;
	while (prefix[i])
	{
		if (ft_toupper(line[i]) != ft_toupper(prefix[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_map_line(char *line)
{
	if (starts_with_ignore_case(line, "NO"))
		return (0);
	if (starts_with_ignore_case(line, "SO"))
		return (0);
	if (starts_with_ignore_case(line, "WE"))
		return (0);
	if (starts_with_ignore_case(line, "EA"))
		return (0);
	if (starts_with_ignore_case(line, "F"))
		return (0);
	if (starts_with_ignore_case(line, "C"))
		return (0);
	if (line[0] == '\n')
		return (0);
	return (1);
}
