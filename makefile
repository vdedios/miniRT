# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 14:19:32 by vde-dios          #+#    #+#              #
#    Updated: 2020/06/26 12:51:05 by vde-dios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	miniRT
NAME_BONUS			=	miniRT_bonus
OS 					:=	$(shell uname)

SRC_DIR 			= 	src/
BONUS_DIR 			= 	src_bonus/
LIBFT_DIR			=	dependencies/libft/
PRINTF_DIR			=	dependencies/printf/
GNL_DIR				=	dependencies/get_next_line/
OBJ_DIR				=	obj/
OBJ_DIR_BONUS		=	obj_bonus/

PRINTF_INCL			=	dependencies/printf/includes

LIBFT_A_DIR			=	dependencies/libft/libft.a
PRINTF_A_DIR		=	dependencies/printf/libftprintf.a

CC					=	gcc
CFLAGS				= 	-Werror -Wall -Wextra -g 
OPENGL				= 	-lz -framework OpenGL -framework AppKit
INCLUDES			=	-Iincludes/ -Iincludes/bonus -I$(PRINTF_INCL) \
						-I$(GNL_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) 
ifeq ($(OS), Linux)
	MINILIBX_DIR = dependencies/minilibx-linux
	OPENGL = -lm -lbsd -lX11 -lXext
endif
ifeq ($(OS), Darwin)
	MINILIBX_DIR = dependencies/minilibx_opengl
	OPENGL = -lz -framework OpenGL -framework AppKit
endif

MINILIBX_A_DIR 		=	$(MINILIBX_DIR)/libmlx.a

BONUS_FILES			=	algebra/algebra_1.c\
					algebra/algebra_2.c\
					algebra/algebra_3.c\
					color/color_bonus.c\
					color/color_utils_bonus.c\
					disruption/color_plane_bonus.c\
					disruption/color_sphere_bonus.c\
					disruption/color_utils_bonus.c\
					disruption/filter_bonus.c\
					disruption/light_bonus.c\
					geometry/cylinder.c\
					geometry/cylinder_caps.c\
					geometry/plane.c\
					geometry/sphere.c\
					geometry/square.c\
					geometry/triangle.c\
					hooks/minirt.c\
					hooks/minirt_utils.c\
					load/load.c\
					load/load_geometry_bonus.c\
					load/load_light_bonus.c\
					load/load_options_bonus.c\
					load/load_scene_bonus.c\
					load/load_utils.c\
					load/load_utils_3.c\
					load/load_utils_bonus.c\
					main/main_bonus.c\
					main/main_options_bonus.c\
					main/main_utils_bonus.c\
					shadows/cylinder_shadows.c\
					shadows/plane_shadows.c\
					shadows/shadows.c\
					shadows/sphere_shadows.c\
					shadows/square_shadows.c\
					shadows/triangle_shadows.c\
					axis.c\
					bmp.c\
					camera.c\
					clean_memory.c\
					clean_memory_2.c\
					error.c\
					pipeline_bonus.c

SRC_FILES			=	algebra/algebra_1.c \
					algebra/algebra_2.c \
					algebra/algebra_3.c \
					geometry/cylinder.c \
					geometry/cylinder_caps.c \
					geometry/plane.c \
					geometry/sphere.c \
					geometry/square.c \
					geometry/triangle.c \
					load/load.c \
					load/load_utils.c \
					load/load_utils_3.c \
					hooks/minirt.c \
					hooks/minirt_utils.c \
					shadows/cylinder_shadows.c \
					shadows/plane_shadows.c \
					shadows/shadows.c \
					shadows/sphere_shadows.c \
					shadows/square_shadows.c \
					shadows/triangle_shadows.c \
					main/main.c \
					main/main_options.c \
					color.c \
					color_utils.c \
					pipeline.c \
					load/load_1.c \
					load/load_2.c \
					load/load_utils_2.c \
					camera.c \
					clean_memory.c\
					clean_memory_2.c\
 					light.c \
					error.c \
					axis.c \
					bmp.c

GNL_FILES			=	get_next_line.c \
						get_next_line_utils.c	

OBJ_FILES			=	$(SRC_FILES:.c=.o)
OBJ 				= 	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJ_BONUS_FILES		=	$(BONUS_FILES:.c=.o)
OBJ_BONUS 			= 	$(addprefix $(OBJ_DIR_BONUS), $(OBJ_BONUS_FILES))
GNL					= 	$(addprefix $(GNL_DIR), $(GNL_FILES))

all		:	dependencies $(OBJ_DIR) $(NAME)

bonus	:	dependencies $(OBJ_DIR_BONUS) $(NAME_BONUS)

$(OBJ_DIR)	:
		@mkdir -p $(OBJ_DIR)
		@mkdir -p $(OBJ_DIR)algebra
		@mkdir -p $(OBJ_DIR)geometry
		@mkdir -p $(OBJ_DIR)hooks
		@mkdir -p $(OBJ_DIR)load
		@mkdir -p $(OBJ_DIR)main
		@mkdir -p $(OBJ_DIR)shadows
		@echo Created printf Object directory 📌

$(OBJ_DIR_BONUS)	:
		@mkdir -p $(OBJ_DIR_BONUS)
		@mkdir -p $(OBJ_DIR_BONUS)algebra
		@mkdir -p $(OBJ_DIR_BONUS)color
		@mkdir -p $(OBJ_DIR_BONUS)disruption
		@mkdir -p $(OBJ_DIR_BONUS)geometry
		@mkdir -p $(OBJ_DIR_BONUS)hooks
		@mkdir -p $(OBJ_DIR_BONUS)load
		@mkdir -p $(OBJ_DIR_BONUS)main
		@mkdir -p $(OBJ_DIR_BONUS)shadows
		@echo Created printf Object directory 📌

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	    $(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< 

$(OBJ_DIR_BONUS)%.o : $(BONUS_DIR)%.c
	    $(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< 

$(NAME)	:	$(OBJ)	 
	@echo Building miniRT...
	@$(CC) $(CFLAGS) $(OBJ) $(GNL) $(INCLUDES)\
	$(PRINTF_A_DIR) $(LIBFT_A_DIR) $(MINILIBX_A_DIR) $(OPENGL) \
	-o $(NAME)
	@echo success ✅

$(NAME_BONUS):	$(OBJ_BONUS)
	@echo Building bonus miniRT...
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(GNL) $(INCLUDES) \
	$(PRINTF_A_DIR) $(LIBFT_A_DIR) $(MINILIBX_A_DIR) $(OPENGL) \
	-o $(NAME_BONUS)
	@echo you got the bonus!...🌟
	
dependencies	:	
	@echo Building libft
	@make -C $(LIBFT_DIR)	
	@echo Building printf
	@make -C $(PRINTF_DIR)
	@make -C $(MINILIBX_DIR)

clean	:
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	@rm -rf $(NAME_BONUS)
	@rm -rf $(NAME_BONUS).dSYM
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@rm -rf *.o
	@echo cleaning miniRT...

fclean	: 	clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@make clean -C $(MINILIBX_DIR)

re		:	fclean all

.PHONY: clean fclean all re bonus dependencies
