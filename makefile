# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 14:19:32 by vde-dios          #+#    #+#              #
#    Updated: 2020/01/25 17:44:54 by vde-dios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	miniRT

SRC_DIR 			= 	src/
MINILIBX_DIR 		=	dependencies/minilibx_opengl
LIBFT_DIR			=	dependencies/libft/
PRINTF_DIR			=	dependencies/printf/
GNL_DIR				=	dependencies/get_next_line/

PRINTF_INCL			=	dependencies/printf/includes

MINILIBX_A_DIR 		=	dependencies/minilibx_opengl/libmlx.a
LIBFT_A_DIR			=	dependencies/libft/libft.a
PRINTF_A_DIR		=	dependencies/printf/libftprintf.a

CC					=	gcc
CFLAGS				= 	-Werror -Wall -Wextra -g
OPENGL				= 	-framework OpenGL -framework AppKit

SRC_FILES			=	algebra/algebra_1.c \
					algebra/algebra_2.c \
					algebra/algebra_3.c \
					camera.c \
					error.c \
					geometry/cylinder.c \
					geometry/cylinder_caps.c \
					geometry/plane.c \
					geometry/sphere.c \
					geometry/square.c \
					geometry/triangle.c \
					load/load.c \
					load/load_1.c \
					load/load_2.c \
					load/load_utils.c \
					load/load_utils_2.c \
					shadows/cylinder_shadows.c \
					shadows/plane_shadows.c \
					shadows/shadows.c \
					shadows/sphere_shadows.c \
					shadows/square_shadows.c \
					shadows/triangle_shadows.c \
					pipeline.c \
					color.c \
					color_waves.c \
					axis.c \
					bmp.c \
					main.c \
					miniRT.c 

GNL_FILES			=	get_next_line.c \
					get_next_line_utils.c	

GNL					= $(addprefix $(GNL_DIR), $(GNL_FILES))
SRC 				= $(addprefix $(SRC_DIR), $(SRC_FILES))

all		:	dependencies $(NAME)

$(NAME)	:	$(SRC) 
	@echo Building miniRT...
	@$(CC) $(CFLAGS) $(SRC) $(GNL) -Iincludes/ -I$(PRINTF_INCL) \
	-I$(GNL_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) \
	$(PRINTF_A_DIR) $(LIBFT_A_DIR) $(MINILIBX_A_DIR) $(OPENGL) \
	-o $(NAME)
	@echo success ✅
	@#echo running program... 💾
	@#./$(NAME)

dependencies	:	
	@echo Building libft
	@make -C $(LIBFT_DIR)	
	@echo Building printf
	@make -C $(PRINTF_DIR)
	@echo Building minilibX
	@make -C $(MINILIBX_DIR)

bonus	:	all
	@echo you got the bonus!...🌟

clean	:
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	@echo cleaning miniRT...

fclean	: 	clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@make clean -C $(MINILIBX_DIR)

re		:	fclean all

.PHONY: clean fclean all re bonus dependencies
