/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 05:22:28 by memam             #+#    #+#             */
/*   Updated: 2022/12/30 15:55:02 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_data(t_param *param)
{
	int	len;
	int	i;
	int	fd;

	i = 0;
	len = nb_ligne_of_map(param->map.filename);
	param->cub_content = malloc(sizeof(char *) * (len + 1));
	if (!param->cub_content)
		exit_error("Malloc Failure\n", 1);
	fd = open(param->map.filename, O_RDONLY);
	if (fd == -1)
		exit_error("File Descriptor Failure\n", 1);
	param->cub_content[i] = get_next_line(fd);
	while (i < len && param->cub_content[i++])
		param->cub_content[i] = get_next_line(fd);
	param->cub_content[i] = 0;
	close(fd);
}

void	ft_get_map(t_param *param)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	param->map.line = ft_maplen(param);
	param->map.map = malloc(sizeof(char *) * (param->map.line + 1));
	param->map.colonne = 0;
	if (!param->map.map)
		exit_error("Malloc Failure\n", 1);
	while (param->cub_content[i])
	{
		if (param->cub_content[i][0] == '1'
			|| param->cub_content[i][0] == ' '
			|| param->cub_content[i][0] == '0')
		{
			param->map.map[k++] = ft_strndup(param->cub_content[i],
					ft_strlen(param->cub_content[i]) - \
					check_new_line(param->cub_content[i]));
			if (param->map.colonne < ft_strlen(param->map.map[k - 1]))
				param->map.colonne = ft_strlen(param->map.map[k - 1]);
		}
		i++;
	}
	param->map.map[k] = NULL;
}

void	get_map_path(char *argv, t_param *param)
{
	param->map.filename = ft_strdup(argv);
	get_data(param);
	check_map_content(param);
	get_path_texture(param);
	get_path_color(param);
	ft_get_map(param);
	get_player_pos(&param->map);
	check_maps(param->map.map);
	check_all_map(param);
}
