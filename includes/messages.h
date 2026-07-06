/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:23:22 by aborda            #+#    #+#             */
/*   Updated: 2026/07/06 08:56:20 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

typedef enum e_msg
{
	ERR_BASE,
	ERR_AV,
	ERR_CUB_EXTENSION,
	ERR_MALLOC,
	ERR_FD,
	ERR_GNL,
	ERR_MLX,
	ERR_VALID_MAP_CHARS,
	ERR_VALID_MAP_PLAYER,
	ERR_VALID_MAP_CLOSED,
	ERR_DOUBLE_KEY
}	t_msg;

int	msg(t_msg msg_code);

#endif
