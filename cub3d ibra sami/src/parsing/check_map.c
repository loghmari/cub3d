/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:50:52 by memam             #+#    #+#             */
/*   Updated: 2022/12/30 15:47:49 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_space(char **map, int line, int colonne)
{
	if (map[line][colonne + 1] == ' ' || \
		map[line][colonne -1] == ' ' || \
		map[line + 1][colonne] == ' ' || \
		map[line -1][colonne] == ' ')
		exit_error("Invalid Map\n", 1);
	return (0);
}

int	check_maps(char **map)
{
	int	line;
	int	column;
	int	find;

	line = 0;
	find = 0;
	while (map[line])
	{
		column = 0;
		while (map[line][column] > 0)
		{
			if (!set_char(map[line][column], " 01NSEW"))
				exit_error("Invalid Map: Character\n", 1);
			if (set_char(map[line][column], "NSEW") \
			&& !check_space(map, line, column))
				find++;
			column++;
		}
		line++;
	}
	if (!find)
		exit_error("Invalid Map: Player\n", 1);
	else if (find > 1)
		exit_error("Not a Multiplayer Game\n", 1);
	return (0);
}

int	check_map_2(t_param *map, int line, int column)
{
	if ((line == 0 && check_borde(map->map.map, line, column)) \
		|| (line == map->map.line - 1 && \
		check_borde(map->map.map, line, column)))
		exit_error("Invalid Map\n", 1);
	else if (column == 0 && check_borde(map->map.map, line, column))
		exit_error("Inavlid Map\n", 1);
	else if (column == ft_strlen(map->map.map[line]) - 1 && \
		check_borde(map->map.map, line, column))
		exit_error("Invalid Map\n", 1);
	else if ((line > 0 && line < map->map.line - 1) \
			&& (column > 0 && column < ft_strlen(map->map.map[line]) - 1))
	{
		if (map->map.map[line][column] == '0' && \
			(map->map.map[line + 1][column] == ' ' \
			|| map->map.map[line - 1][column] == ' ' \
			|| map->map.map[line][column + 1] == ' ' \
			|| map->map.map[line][column - 1] == ' '))
			exit_error("Invalid Map\n", 1);
	}
	return (0);
}

int	check_all_map(t_param *param)
{
	int	line;
	int	column;

	line = 0;
	while (param->map.map[line])
	{
		column = 0;
		if (chech_map_closed(param->map.map, line))
			exit_error("Invalid : map is not Close\n", 1);
		while (param->map.map[line][column])
		{
			check_map_2(param, line, column);
			column++;
		}
		line++;
	}
	return (0);
}
