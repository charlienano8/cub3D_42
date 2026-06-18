/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:23:22 by aborda            #+#    #+#             */
/*   Updated: 2026/06/18 14:50:37 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

typedef enum e_msg
{
	ERR_BASE,
	ERR_AV,
	ERR_MALLOC
}	t_msg;

int	msg(t_msg msg_code);

#endif
