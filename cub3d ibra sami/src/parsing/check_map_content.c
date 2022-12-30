/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:23:31 by memam             #+#    #+#             */
/*   Updated: 2022/12/30 15:42:46 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_map_dir_content(t_param *param, int *i)
{
	int		find;

	find = 0;
	while (*i < 4 && param->cub_content[*i])
	{
		if (ft_strncmp(param->cub_content[*i], "NO ", 3) == 0 \
			|| ft_strncmp(param->cub_content[*i], "SO ", 3) == 0 \
			|| ft_strncmp(param->cub_content[*i], "WE ", 3) == 0 \
			|| ft_strncmp(param->cub_content[*i], "EA ", 3) == 0 \
			)
		{		
			find++;
		}
		(*i)++;
	}
	if (*i != find && find != 4)
		exit_error("Texture Invalid\n", 1);
	if (*i == 0)
		exit_error("File Invalid: Empty Texture", 1);
}

void	check_color(char **color, int *i)
{
	int		find;
	int		ii;
	int		k;

	find = 0;
	k = *i;
	ii = *i + 2;
	while (*i < ii && color[*i])
	{
		if (ft_strncmp(color[*i], "F ", 2) == 0 \
			|| ft_strncmp(color[*i], "C ", 2) == 0)
			find++;
		(*i)++;
	}
	if (*i - k != find)
		exit_error("Color Invalid\n", 1);
}

void	check_map_content(t_param *param)
{
	int	i;

	i = 0;
	check_map_dir_content(param, &i);
	while (param->cub_content[i] && ft_strcmp(param->cub_content[i], "\n") == 0)
		i++;
	check_color(param->cub_content, &i);
	while (param->cub_content[i] && ft_strcmp(param->cub_content[i], "\n") == 0)
		i++;
}
