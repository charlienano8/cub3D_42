/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:23:22 by aborda            #+#    #+#             */
/*   Updated: 2026/07/12 11:06:53 by aborda           ###   ########.fr       */
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
	ERR_VALID_MAP_END,
	ERR_DOUBLE_KEY,
	ERR_ELEMENTS_MISSING,
	ERR_ELEMENTS_INVALID_COLOR,
	ERR_ELEMENTS_INVALID_TEXTURE_PATH,
	ERR_XPM_TEXTURES,
	ERR_UNKNOWN_DIRECTIVE
}	t_msg;

int	msg(t_msg msg_code);
int	msg_parse(t_msg msg_code);

#endif
