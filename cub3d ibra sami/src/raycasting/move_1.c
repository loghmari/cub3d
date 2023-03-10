/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:36:39 by memam             #+#    #+#             */
/*   Updated: 2022/12/30 15:59:18 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	start_scan(void *ptr)
{
	t_param	*start_ptr;

	start_ptr = ptr;
	mlx_clear_window(start_ptr->mlx, start_ptr->win_ptr);
	start_drw(start_ptr);
	return (0);
}

void	move(t_param *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->img.ptr);
	ptr->img.ptr = mlx_new_image(ptr->mlx, ptr->screen_w, \
		ptr->screen_h);
	if (ptr->r_right == 1)
		rotate(ptr, -(ptr->r_angle));
	else if (ptr->r_left == 1)
		rotate(ptr, ptr->r_angle);
	else if (ptr->m_up == 1)
		forward(ptr);
	else if (ptr->m_down == 1)
		backward(ptr);
	else if (ptr->m_right == 1)
		right(ptr);
	else if (ptr->m_left == 1)
		left(ptr);
	mlx_clear_window(ptr->mlx, ptr->win_ptr);
	ptr->x = 0;
	start_scan(ptr);
	mini_map(ptr);
}

int	press(int key, t_param *ptr)
{
	if (key == 124)
		ptr->r_right = 1;
	else if (key == 123)
		ptr->r_left = 1;
	else if (key == 13)
		ptr->m_up = 1;
	else if (key == 1)
		ptr->m_down = 1;
	else if (key == 2)
		ptr->m_right = 1;
	else if (key == 0)
		ptr->m_left = 1;
	else if (key == 53)
		ft_close(ptr);
	else
		return (1);
	move(ptr);
	return (0);
}

int	release(int key, t_param *ptr)
{
	if (key == 124)
		ptr->r_right = 0;
	else if (key == 123)
		ptr->r_left = 0;
	else if (key == 13)
		ptr->m_up = 0;
	else if (key == 1)
		ptr->m_down = 0;
	else if (key == 2)
		ptr->m_right = 0;
	else if (key == 0)
		ptr->m_left = 0;
	return (0);
}
