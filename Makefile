# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 14:13:25 by hayelee           #+#    #+#              #
#    Updated: 2023/03/14 11:41:25 by seshin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

SRCS			=	cub3d.c\
					main_loop.c\
					load_cub_file.c\
					make_map.c\
					check/check_map.c\
					check/check_argv.c\
					check/check_extension.c\
					check/check_line_info.c\
					check/check_path.c\
					check/check_rgb.c\
					check/check_position.c\
					check/check_map_validity.c\
					gnl/get_next_line.c\
					gnl/get_next_line_utils.c\
					init/init_dir.c\
					init/init_info.c\
					key/key_setting.c\
					key/key_move.c\
					key/key_rotate.c\
					save/save_option.c\
					save/save_map_final.c\
					utils/set.c\
					utils/draw.c\
					utils/free_array.c\
					utils/print_error.c\
					utils/malloc_array.c\
					utils/calc_by_hit_value.c\


OBJS			= $(SRCS:.c=.o)

CC				= gcc 
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I. -g3 -fsanitize=address
LIBS			= -Lmlx -framework OpenGL -framework AppKit -lm
MLX			= libmlx.a
LIBFT			= libft.a
MAKE			= make

all:			$(NAME)

$(MLX):
				$(MAKE) -C mlx
				mv mlx/$(MLX) .

$(LIBFT):		
				$(MAKE) -C libft
				mv libft/$(LIBFT) .



$(NAME):		$(MLX) $(LIBFT) $(OBJS)
				$(CC) ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS} libft.a libmlx.a



clean:
				$(MAKE) -C mlx clean
				$(MAKE) -C libft clean
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME) $(MLX) $(LIBFT)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
