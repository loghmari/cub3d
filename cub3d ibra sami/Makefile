# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 16:48:36 by sloghmar          #+#    #+#              #
#    Updated: 2022/12/30 17:03:41 by sloghmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
OBJ_DIR		=	obj/
SRCS_DIR	=	src/
SRCS		=	main.c\
				minimap.c\
				initializ/init_structs.c\
				utils/ft_free.c\
				parsing/pars.c\
				parsing/pars_utils.c\
				parsing/check_map.c\
				parsing/check_map_utils.c\
				parsing/check_map_content.c\
				parsing/get_path_texture.c\
				raycasting/move.c\
				raycasting/move_1.c\
				raycasting/raycasting.c\
				raycasting/texture_ray.c\

				
OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
MLX		= libmlx.a
LIBFT	= libft.a
LFLAGS	= -I include/
CFLAGS = -Wall -Wextra -Werror -g
DEBUGGING = -ggdb
CC = gcc
RM = rm -rf
AR = ar rc

all: objects libft minilibx $(NAME)

libft:
	make -C libft/
minilibx:
	make -C mlx/
objects:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/initializ
	@mkdir -p $(OBJ_DIR)/raycasting



$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
		$(CC) -c $(CFLAGS) $(DEBUGGING) $(LFLAGS) $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) libft/$(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -g

clean:
		make -C mlx clean
		make -C libft clean
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

RED="\e[31m"
GREEN="\e[32m"
ENDCOLOR="\e[0m"

leak:	all
	leaks -atExit -- ./$(NAME) testing_files/small.cub

.PHONY: all clean re fclean

