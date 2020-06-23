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
NAME_BONUS			=	miniRT_bonus

SRC_DIR 			= 	src/
BONUS_DIR 			= 	src/bonus/
MINILIBX_DIR 			=	dependencies/minilibx_opengl
LIBFT_DIR			=	dependencies/libft/
PRINTF_DIR			=	dependencies/printf/
GNL_DIR				=	dependencies/get_next_line/
OBJ_DIR				=	obj/
OBJ_DIR_BONUS			=	obj/bonus/
ALGB_DIR			=	algebra/
GEOMETRY_DIR			=	geometry/
LOAD_DIR			=	load/
MINIRT_DIR			=	hooks/
SHADOWS_DIR			=	shadows/

PRINTF_INCL			=	dependencies/printf/includes

MINILIBX_A_DIR 			=	dependencies/minilibx_opengl/libmlx.a
LIBFT_A_DIR			=	dependencies/libft/libft.a
PRINTF_A_DIR			=	dependencies/printf/libftprintf.a

CC				=	gcc
AR				=	ar -rcs
CFLAGS				= 	-Werror -Wall -Wextra -g
OPENGL				= 	-lz -framework OpenGL -framework AppKit
INCLUDES			=	-Iincludes/ -Iincludes/bonus -I$(PRINTF_INCL) \
					-I$(GNL_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) 
BONUS_FLAG			=


BONUS_FILES			=	color_plane_bonus.c \
 					color_sphere_bonus.c \
 					color_utils_bonus.c \
 					filter_bonus.c \
 					light_bonus.c \
 					load_bonus.c \
 					load_bonus2.c \
					main_bonus.c

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
					load/load_1.c \
					load/load_2.c \
					load/load_utils.c \
					load/load_utils_2.c \
					load/load_utils_3.c \
					hooks/miniRT.c \
					hooks/miniRT_utils.c \
					shadows/cylinder_shadows.c \
					shadows/plane_shadows.c \
					shadows/shadows.c \
					shadows/sphere_shadows.c \
					shadows/square_shadows.c \
					shadows/triangle_shadows.c \
					camera.c \
					error.c \
					pipeline.c \
					color.c \
					color_utils.c \
					axis.c \
					bmp.c \
					main.c \
					main_options.c \

GNL_FILES			=	get_next_line.c \
					get_next_line_utils.c	

OBJ_FILES			=	$(SRC_FILES:.c=.o)
OBJ 				= 	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJ_BONUS_FILES			=	$(BONUS_FILES:.c=.o)
OBJ_BONUS 			= 	$(addprefix $(OBJ_DIR_BONUS), $(OBJ_BONUS_FILES))
GNL				= 	$(addprefix $(GNL_DIR), $(GNL_FILES))


all	:	dependencies $(OBJ_DIR) $(NAME)

bonus	:	BONUS_FLAG += -D BONUS
bonus	:	dependencies $(OBJ_DIR) $(NAME_BONUS)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@mkdir -p $(OBJ_DIR_BONUS)
		@mkdir -p $(OBJ_DIR)$(ALGB_DIR)
		@mkdir -p $(OBJ_DIR)$(GEOMETRY_DIR)
		@mkdir -p $(OBJ_DIR)$(LOAD_DIR)
		@mkdir -p $(OBJ_DIR)$(MINIRT_DIR)
		@mkdir -p $(OBJ_DIR)$(SHADOWS_DIR)
		@echo Created printf Object directory 📌

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	    $(CC) $(CFLAGS) $(BONUS_FLAG) $(INCLUDES) -o $@ -c $< 

$(OBJ_DIR_BONUS)%.o : $(BONUS)%.c
	    $(CC) $(CFLAGS) $(BONUS_FLAG) $(INCLUDES) -o $@ -c $< 

$(NAME)	:	$(OBJ)	 
	@echo Building miniRT...
	@$(CC) $(CFLAGS) $(OBJ) $(GNL) $(INCLUDES)\
	$(PRINTF_A_DIR) $(LIBFT_A_DIR) $(MINILIBX_A_DIR) $(OPENGL) \
	-o $(NAME)
	@echo success ✅

$(NAME_BONUS):	$(OBJ_BONUS) $(OBJ)
	@echo Building bonus miniRT...
	$(CC) $(CFLAGS) $(BONUS_FLAG) $(OBJ) $(OBJ_BONUS) $(GNL) $(INCLUDES) \
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
	@rm -rf *.o
	@echo cleaning miniRT...

fclean	: 	clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@make clean -C $(MINILIBX_DIR)

re	:	fclean all

.PHONY: clean fclean all re bonus dependencies
