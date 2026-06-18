/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cub_extension.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:54:32 by aborda            #+#    #+#             */
/*   Updated: 2026/06/18 16:19:32 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_cub_extension(char *str)
{
	char	*ptr;

	ptr = ft_strrchr(str, '.');
	if ((ft_strncmp(ptr, ".cub", 4)) == 0)
		return (1);
	return (0);
}
