/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 07:40:40 by memam             #+#    #+#             */
/*   Updated: 2022/12/30 15:55:02 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	set_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	nb_ligne_of_map(char *path)
{
	int		i;
	int		fd;
	char	*ligne;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_error("File Descriptor Failure\n", 1);
	ligne = get_next_line(fd);
	while (ligne)
	{
		free(ligne);
		i++;
		ligne = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	ft_maplen(t_param *param)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (param->cub_content[i])
	{
		if (param->cub_content[i][0] == '1'
			|| param->cub_content[i][0] == '0'
			|| param->cub_content[i][0] == ' ')
			len++;
		i++;
	}
	return (len);
}

int	check_new_line(char *str)
{
	return (str[ft_strlen(str) - 1] == '\n');
}
