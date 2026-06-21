/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_antoine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:32:53 by aborda            #+#    #+#             */
/*   Updated: 2026/06/21 13:48:01 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "messages.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (msg(ERR_AV));
	if (!is_cub_extension(av[1]))
		return (msg(ERR_CUB_EXTENSION));
	line_map_count(av[1]);
	return (0);
}
