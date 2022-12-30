/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:26:33 by memam             #+#    #+#             */
/*   Updated: 2022/12/30 15:49:01 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	open_texture(t_param *tex)
{
	if (open(tex->map.north_texture, O_RDONLY) < 0 \
		|| open(tex->map.south_texture, O_RDONLY) < 0 \
		|| open(tex->map.east_texture, O_RDONLY) < 0 \
		|| open(tex->map.west_texture, O_RDONLY) < 0)
		exit_error("Texture : No Exist \n", 1);
}

void	get_path_texture(t_param *param)
{
	char	**path_tex;
	int		i;

	i = 0;
	while (i < 4)
	{
		path_tex = ft_split_str(param->cub_content[i++], ", \n");
		if (!path_tex)
			return ;
		if (ft_strcmp(path_tex[0], "NO") == 0)
			param->map.north_texture = ft_strdup(path_tex[1]);
		else if (ft_strcmp(path_tex[0], "SO") == 0)
			param->map.south_texture = ft_strdup(path_tex[1]);
		else if (ft_strcmp(path_tex[0], "WE") == 0)
			param->map.west_texture = ft_strdup(path_tex[1]);
		else if (ft_strcmp(path_tex[0], "EA") == 0)
			param->map.east_texture = ft_strdup(path_tex[1]);
		free_split(path_tex);
	}
	open_texture(param);
}

void	get_color_rgb(t_color *color, char **str)
{
	color->r = ft_atoi(str[0]);
	color->g = ft_atoi(str[1]);
	color->b = ft_atoi(str[2]);
}

void	get_path_color(t_param *param)
{
	char	**get_fc;
	int		i;

	i = 0;
	while (param->cub_content[i])
	{
		get_fc = ft_split_str(param->cub_content[i++], ", \n");
		if (!get_fc)
			return ;
		if (ft_strcmp(get_fc[0], "F") == 0)
			get_color_rgb(&param->map.floor_color, get_fc + 1);
		else if (ft_strcmp(get_fc[0], "C") == 0)
			get_color_rgb(&param->map.ceiling_color, get_fc + 1);
	}
}

void	get_player_pos(t_map *map)
{
	int	line;
	int	col;

	line = 0;
	while (map->map[line])
	{
		col = 0;
		while (map->map[line][col])
		{
			if (set_char(map->map[line][col], "NSEW"))
			{
				map->player.x = line;
				map->player.y = col;
				map->starting_pos = map->map[line][col];
				return ;
			}
			col++;
		}
		line++;
	}
}
