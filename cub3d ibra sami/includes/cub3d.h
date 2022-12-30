/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:02:56 by sloghmar          #+#    #+#             */
/*   Updated: 2022/12/30 16:03:01 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "structs.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>  
// #define MINI_SCALE 0.20
// #define TILE_SIZE 30
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
/*************** MLX ******************/
void	cub_3d(t_param *ptr_mlx, t_map *parma);
int		mini_map(t_param *maps);
/*************** INIT_STRUCT ******************/
void	init_color(t_color *color);
void	init_map(t_map *map);
void	init_game(t_param *game);
void	start_game(t_param *game);
/*************** utils ******************/
void	exit_error(char *msg, int code);
void	free_all(t_map *parma);
void	free_split(char **tab);
/*************** PARS ******************/
		/******pars******/	
void	get_data(t_param *parma);
void	get_map_path(char *argv, t_param *parma);
void	ft_get_map(t_param *parma);
void	find_player(t_param *parma);
		/******pars_utils******/
int		set_char(char c, char *str);
int		nb_ligne_of_map(char *path);
int		ft_maplen(t_param *parma);
		/******check_map******/
int		check_space(char **map, int ligne, int colone);
int		check_maps(char **map);
int		check_map_2(t_param *map, int ligne, int colone);
int		check_all_map(t_param *parma);
		/******check_map_utils******/
int		check_borde(char **map, int ligne, int index);
int		check_borde2(char **map, int ligne, int index);
int		chech_map_closed(char **map, int ligne);
void	check_map_content(t_param *param);
int		check_new_line(char *str);
		/******get_path_tex******/
void	get_path_texture(t_param *parma);
void	get_path_color(t_param *parma);
void	get_player_pos(t_map *map);

/*************** raycasting_tste ******************/
		/******move******/
int		release(int key, t_param *ptr);
int		press(int key, t_param *ptr);
void	move(t_param *ptr);
void	rotate(t_param *ptr, double angle);
void	left(t_param *ptr);
void	right(t_param *ptr);
void	backward(t_param *ptr);
void	forward(t_param *ptr);
int		start_scan(void *ptr);
void	ft_new_window(t_param *game);
int		ft_close(t_param *game);
/*******************************************************/
void	ray_draw(t_param *wall);
void	ft_camera_3d(t_param *cam);
void	ray_casting(t_param *ray);
void	distance_cal(t_param *d);
int		encode_rgb(t_color color);
void	ft_ceiling_floor(t_param *star);
void	get_texture(t_param *parm);
void	texture_wall(t_param *parm);
void	put_texture(t_param *parm);
void	start_drw(t_param *parm);

#endif
