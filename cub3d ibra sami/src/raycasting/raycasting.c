/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:32:30 by yabed             #+#    #+#             */
/*   Updated: 2022/12/30 16:00:37 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ray_draw(t_param *ptr)
{
	if (ptr->raydir_x < 0)
	{
		ptr->step_x = -1;
		ptr->side_dist_x = (ptr->pos_x - ptr->map_x) \
			* ptr->delta_dist_x;
	}
	else
	{
		ptr->step_x = 1;
		ptr->side_dist_x = (ptr->map_x + 1.0 - ptr->pos_x) \
			* ptr->delta_dist_x;
	}
	if (ptr->raydir_y < 0)
	{
		ptr->step_y = -1;
		ptr->side_dist_y = (ptr->pos_y - ptr->map_y) \
			* ptr->delta_dist_y;
	}
	else
	{
		ptr->step_y = 1;
		ptr->side_dist_y = (ptr->map_y + 1.0 - ptr->pos_y) \
			* ptr->delta_dist_y;
	}
}

void	ft_camera_3d(t_param *ptr)
{
	ptr->camera_x = 2 * (ptr->x / (double)(ptr->screen_w)) - 1;
	ptr->raydir_x = ptr->dir_x + ptr->plane_x \
		* ptr->camera_x;
	ptr->raydir_y = ptr->dir_y + ptr->plane_y \
		* ptr->camera_x;
	ptr->map_x = (int)ptr->pos_x;
	ptr->map_y = (int)ptr->pos_y;
	ptr->delta_dist_x = sqrt(1 + pow(ptr->raydir_y, 2) \
		/ pow(ptr->raydir_x, 2));
	ptr->delta_dist_y = sqrt(1 + pow(ptr->raydir_x, 2) \
		/ pow(ptr->raydir_y, 2));
	ptr->hit = 0;
	ray_draw(ptr);
}

void	ray_casting(t_param *ptr)
{
	while (ptr->hit == 0)
	{
		if (ptr->side_dist_x < ptr->side_dist_y)
		{
			ptr->side_dist_x += ptr->delta_dist_x;
			ptr->map_x += ptr->step_x;
			ptr->side = 0;
		}
		else
		{
			ptr->side_dist_y += ptr->delta_dist_y;
			ptr->map_y += ptr->step_y;
			ptr->side = 1;
		}
		if (ptr->map.map[ptr->map_x][ptr->map_y] == '1')
			ptr->hit = 1;
	}
	if (ptr->side == 0)
		ptr->perp_wall_dist = fabs((ptr->map_x - ptr->pos_x + \
		(1 - ptr->step_x) / 2) / ptr->raydir_x);
	else
		ptr->perp_wall_dist = fabs((ptr->map_y - ptr->pos_y + \
		(1 - ptr->step_y) / 2) / ptr->raydir_y);
}

void	distance_cal(t_param *d)
{
	if (!d->perp_wall_dist)
		d->perp_wall_dist = 1;
	d->line_height = (int)(d->screen_h / d->perp_wall_dist);
	d->draw_start = -d->line_height / 2 + d->screen_h / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->line_height / 2 + d->screen_h / 2;
	if (d->draw_end >= d->screen_h)
		d->draw_end = d->screen_h - 1;
}

void	start_drw(t_param *param)
{
	while (param->x < param->screen_w)
	{	
		ft_camera_3d(param);
		ray_casting(param);
		distance_cal(param);
		ft_ceiling_floor(param);
		get_texture(param);
		texture_wall(param);
		put_texture(param);
		param->x++;
	}
	mlx_put_image_to_window(param->mlx, param->win_ptr, param->img.ptr, 0, 0);
}
