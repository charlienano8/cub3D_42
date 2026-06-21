/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cub_extension.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:54:32 by aborda            #+#    #+#             */
/*   Updated: 2026/06/21 15:51:09 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_cub_extension(char *str)
{
	char	*ptr;

	ptr = ft_strrchr(str, '.');
	if (ptr == NULL)
		return (0);
	if ((ft_strncmp(ptr, ".cub", 4)) == 0 && (ft_strlen(ptr) == 4))
		return (1);
	return (0);
}
