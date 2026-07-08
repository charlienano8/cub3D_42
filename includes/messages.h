/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:23:22 by aborda            #+#    #+#             */
/*   Updated: 2026/07/08 09:34:34 by aborda           ###   ########.fr       */
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
	ERR_DOUBLE_KEY,
	ERR_ELEMENTS_MISSING,
	ERR_ELEMENTS_COLOR
}	t_msg;

int	msg(t_msg msg_code);
int	msg_parse(t_msg msg_code);

#endif
