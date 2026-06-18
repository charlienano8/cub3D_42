/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_antoine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:32:53 by aborda            #+#    #+#             */
/*   Updated: 2026/06/18 15:23:31 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.h"

int	main(int ac, char **av)
{
	(void) av;

	if (ac != 2)
		return (msg(ERR_AV));

	char *ptr;

	ptr = ft_strrchr(av[1], '.');





	return (0);
}
