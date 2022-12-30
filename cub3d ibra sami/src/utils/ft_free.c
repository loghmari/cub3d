/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:27:14 by memam             #+#    #+#             */
/*   Updated: 2022/12/30 16:07:56 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	exit_error(char *msg, int code)
{
	ft_putstr_fd(msg, code);
	exit(code);
}

void	free_all(t_map *param)
{
	int	i;

	i = -1;
	while (param->map[++i])
	{
		free(param->map[i]);
	}
	free(param->map);
}

void	free_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
