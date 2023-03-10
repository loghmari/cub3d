/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:42:56 by memam             #+#    #+#             */
/*   Updated: 2022/12/30 16:00:37 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	encode_rgb(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

void	ft_ceiling_floor(t_param *ptr)
{
	int	i;

	i = -1;
	while (++i < ptr->draw_start)
		ptr->img.arr[i * ptr->screen_w + ptr->x] = \
		encode_rgb(ptr->map.ceiling_color);
	i = ptr->draw_end;
	while (++i < ptr->screen_h)
		ptr->img.arr[i * ptr->screen_w + ptr->x] = \
		encode_rgb(ptr->map.floor_color);
}

void	get_texture(t_param *ptr)
{
	if (ptr->side == 0 && ptr->step_x == -1)
		ptr->tex.ptr = mlx_xpm_file_to_image(ptr->mlx, ptr->\
		map.north_texture, &ptr->tex.width, &ptr->tex.height);
	if (ptr->side == 0 && ptr->step_x == 1)
		ptr->tex.ptr = mlx_xpm_file_to_image(ptr->mlx, ptr->\
		map.south_texture, &ptr->tex.width, &ptr->tex.height);
	if (ptr->side == 1 && ptr->step_y == -1)
		ptr->tex.ptr = mlx_xpm_file_to_image(ptr->mlx, ptr->\
		map.west_texture, &ptr->tex.width, &ptr->tex.height);
	if (ptr->side == 1 && ptr->step_y == 1)
		ptr->tex.ptr = mlx_xpm_file_to_image(ptr->mlx, ptr->\
		map.east_texture, &ptr->tex.width, &ptr->tex.height);
	ptr->tex.arr = (int *)mlx_get_data_addr(ptr->tex.ptr, &ptr->\
		tex.len, &ptr->tex.bpp, &ptr->tex.endian);
}

void	texture_wall(t_param *ptr)
{
	if (ptr->side == 0)
		ptr->wallx = ptr->pos_y + ptr->perp_wall_dist * \
		ptr->raydir_y;
	else
		ptr->wallx = ptr->pos_x + ptr->perp_wall_dist * \
		ptr->raydir_x;
	ptr->wallx -= (int)((ptr->wallx));
	ptr->tex_x = (int)(ptr->wallx * (double)(ptr->tex.width));
	if (ptr->side == 0 && ptr->raydir_x > 0)
		ptr->tex_x = ptr->tex.width - ptr->tex_x - 1;
	if (ptr->side == 1 && ptr->raydir_x < 0)
		ptr->tex_x = ptr->tex.width - ptr->tex_x - 1;
	ptr->tex_step = 1.0 * ptr->tex.height / ptr->line_height;
	ptr->tex_pos = (ptr->draw_start - ptr->screen_h \
		/ 2 + ptr->line_height / 2) * ptr->tex_step;
}

void	put_texture(t_param *ptr)
{
	int		color;
	int		y;

	y = ptr->draw_start;
	while (y < ptr->draw_end)
	{
		ptr->tex_y = (int)ptr->tex_pos & (ptr->tex.height - 1);
		ptr->tex_pos += ptr->tex_step;
		color = ptr->tex.arr[ptr->tex.height * ptr->tex_y \
			+ ptr->tex_x];
		if (ptr->side == 1)
			color = (color >> 1) & 8355711;
		ptr->img.arr[y * (ptr->screen_w) + (ptr->x)] = color;
		y++;
	}
}
