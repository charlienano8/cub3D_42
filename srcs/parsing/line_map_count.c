/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_map_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 10:26:18 by aborda            #+#    #+#             */
/*   Updated: 2026/06/21 13:47:40 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "messages.h"
#include "libft.h"

int	line_map_count(char *file)
{
	char	*current_line;
	int		fd;
	int		count;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		msg(ERR_FD);
		return (-1);
	}
	count = 0;
	current_line = get_next_line(fd);
	while (current_line != NULL)
	{
		if (is_map_line(current_line))
			count++;
		free(current_line);
		current_line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
