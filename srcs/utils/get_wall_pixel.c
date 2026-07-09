/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 08:57:21 by makui             #+#    #+#             */
/*   Updated: 2026/07/09 08:59:45 by makui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*select_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (&game->tex_ea);
		return (&game->tex_we);
	}
	if (ray->ray_dir_y > 0)
		return (&game->tex_so);
	return (&game->tex_no);
}

int	get_wall_pixel(t_game *game, t_ray *ray, int tex_y, double wall_x)
{
	t_img	*tex;
	int		tex_x;

	tex = select_wall_texture(game, ray);
	tex_x = (int)(wall_x * 64.0);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = 64 - tex_x - 1;
	if (tex_x < 0 || tex_x >= 64 || tex_y < 0 || tex_y >= 64)
		return (0);
	return (*(unsigned int *)(tex->addr + (tex_y * tex->line_length
			+ tex_x * (tex->bits_per_pixel / 8))));
}
