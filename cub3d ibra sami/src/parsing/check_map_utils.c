/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:51:27 by memam             #+#    #+#             */
/*   Updated: 2022/12/30 15:46:10 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_borde(char **map, int line, int column)
{
	if (map[line][column] != '1' && map[line][column] != ' ')
		return (1);
	return (0);
}

int	check_borde2(char **map, int line, int index)
{
	while (map[line][index])
	{
		if (map[line][index] != '1' && map[line][index] != ' ')
			return (1);
		index++;
	}
	return (0);
}

int	chech_map_closed(char **map, int line)
{
	int	line1;
	int	line2;

	line1 = ft_strlen(map[line]);
	line2 = 0;
	if (map[line + 1])
		line2 = ft_strlen(map[line + 1]);
	if (line1 > line2 && line2 > 0)
	{
		if (check_borde2(map, line, line2))
			return (1);
	}
	else if (line2 > line1)
	{
		if (check_borde2(map, line + 1, line1))
			return (1);
	}
	return (0);
}
