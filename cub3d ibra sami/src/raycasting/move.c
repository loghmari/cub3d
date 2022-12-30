/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:37:27 by memam             #+#    #+#             */
/*   Updated: 2022/12/30 15:59:18 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate(t_param *ptr, double angle)
{
	double	olddirx;
	double	oldplanx;

	oldplanx = ptr->plane_x;
	olddirx = ptr->dir_x;
	ptr->dir_x = ptr->dir_x * cos(angle) - \
		ptr->dir_y * sin(angle);
	ptr->dir_y = olddirx * sin(angle) + ptr->dir_y * cos(angle);
	ptr->plane_x = ptr->plane_x * cos(angle) - \
		ptr->plane_y * sin(angle);
	ptr->plane_y = oldplanx * sin(angle) + ptr->plane_y * cos (angle);
}

void	forward(t_param *ptr)
{
	if (ptr->map.map[(int)(ptr->pos_x + ptr->dir_x)][(int)(\
		ptr->pos_y + ptr->dir_y)] == '0')
	{
		ptr->pos_x += ptr->dir_x * ptr->m_speed;
		ptr->pos_y += ptr->dir_y * ptr->m_speed;
	}
}

void	backward(t_param *ptr)
{
	if (ptr->map.map[(int)(ptr->pos_x - ptr->dir_x)][(int)(\
		ptr->pos_y - ptr->dir_y)] == '0')
	{
		ptr->pos_x -= ptr->dir_x * ptr->m_speed;
		ptr->pos_y -= ptr->dir_y * ptr->m_speed;
	}
}

void	right(t_param *ptr)
{
	if (ptr->map.map[(int)(ptr->pos_x)][(int)(\
		ptr->pos_y + ptr->dir_y + ptr->plane_y)] == '0')
	{
		ptr->pos_y += ptr->plane_y * ptr->m_speed;
		ptr->pos_x += ptr->plane_x * ptr->m_speed;
	}
}

void	left(t_param *ptr)
{
	if (ptr->map.map[(int)(ptr->pos_x)][(int)(\
		ptr->pos_y + ptr->dir_y - ptr->plane_y)] == '0')
	{
		ptr->pos_y -= ptr->plane_y * ptr->m_speed;
		ptr->pos_x -= ptr->plane_x * ptr->m_speed;
	}
}
