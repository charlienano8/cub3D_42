/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 11:33:17 by aborda            #+#    #+#             */
/*   Updated: 2026/06/21 12:39:27 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_map_line(char *line)
{
	if ((ft_strncmp(line, "NO", 2)) == 0)
		return (0);
	if ((ft_strncmp(line, "SO", 2)) == 0)
		return (0);
	if ((ft_strncmp(line, "WE", 2)) == 0)
		return (0);
	if ((ft_strncmp(line, "EA", 2)) == 0)
		return (0);
	if ((ft_strncmp(line, "F", 1)) == 0)
		return (0);
	if ((ft_strncmp(line, "C", 1)) == 0)
		return (0);
	if ((ft_strncmp(line, "\n", 1)) == 0)
		return (0);
	return (1);
}
