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

MINILIBX_A_DIR 	=	dependencies/minilibx_opengl/libmlx.a
LIBFT_A_DIR		=	dependencies/libft/libft.a
PRINTF_A_DIR		=	dependencies/printf/libftprintf.a

CC					=	gcc
CFLAGS				= 	-Werror -Wall -Wextra -g
OPENGL				= 	-framework OpenGL -framework AppKit

SRC_FILES			=	main.c \
						miniRT.c

SRC 				= $(addprefix $(SRC_DIR), $(SRC_FILES))

all		:	dependencies $(NAME)

$(NAME)	:	$(SRC) 
	@echo Building miniRT...
	@$(CC) $(CFLAGS) $(SRC) -I includes/ $(PRINTF_A_DIR) \
		$(LIBFT_A_DIR) $(MINILIBX_A_DIR) $(OPENGL) -o $(NAME)
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
