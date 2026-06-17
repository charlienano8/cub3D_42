/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:04:57 by aborda            #+#    #+#             */
/*   Updated: 2026/01/21 11:35:30 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	process_read(int bytes_read, char *buffer, char *stash, char **tmp)
{
	if (bytes_read == -1)
	{
		free(stash);
		free(buffer);
		return (-1);
	}
	if (bytes_read == 0)
	{
		if (stash == NULL || stash[0] == '\0')
		{
			free(stash);
			free(buffer);
			return (-1);
		}
		*tmp = stash;
		free(buffer);
		return (1);
	}
	return (0);
}

int	read_and_join_buffer(int bytes_read, char *buffer, char *stash, char **tmp)
{
	int	result;

	result = 0;
	result = process_read(bytes_read, buffer, stash, tmp);
	if (result == -1)
		return (-1);
	if (result == 1)
		return (0);
	buffer[bytes_read] = '\0';
	*tmp = ft_strjoin(stash, buffer);
	if (*tmp == NULL)
	{
		free(stash);
		free(buffer);
		return (-1);
	}
	free(stash);
	free(buffer);
	return (0);
}

int	read_until_newline(int fd, char **tmp)
{
	int		bytes_read;
	int		result;
	char	*buffer;
	char	*stash;

	bytes_read = 1;
	if (*tmp == NULL)
		*tmp = ft_strdup("");
	if (*tmp == NULL)
		return (-1);
	while ((!ft_strchr(*tmp, '\n')) && (bytes_read > 0))
	{
		stash = ft_strdup(*tmp);
		if (stash == NULL)
			return (free(*tmp), *tmp = NULL, -1);
		free(*tmp);
		*tmp = NULL;
		buffer = alloc_and_read(fd, &bytes_read);
		if (buffer == NULL)
			return (free(stash), -1);
		result = read_and_join_buffer(bytes_read, buffer, stash, tmp);
		if (result != 0)
			return (result);
	}
	return (0);
}

char	*extract_line_with_new_line(char **tmp)
{
	int		i;
	char	*line;
	char	*new_tmp;

	i = 0;
	while ((*tmp)[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (free(*tmp), *tmp = NULL, NULL);
	i = 0;
	while ((*tmp)[i] != '\n')
	{
		line[i] = (*tmp)[i];
		i++;
	}
	new_tmp = ft_strdup((*tmp) + i + 1);
	if (new_tmp == NULL)
		return (free(line), free(*tmp), *tmp = NULL, NULL);
	free(*tmp);
	*tmp = new_tmp;
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (read_until_newline(fd, &tmp[fd]) == -1)
		return (NULL);
	if (ft_strchr(tmp[fd], '\n'))
		line = extract_line_with_new_line(&tmp[fd]);
	else
	{
		line = ft_strdup(tmp[fd]);
		free(tmp[fd]);
		tmp[fd] = NULL;
	}
	return (line);
}
