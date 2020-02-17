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

NAME		=	miniRT
MINILIBX 	=	minilibx_opengl/libmlx.a
OPENGL		= 	-framework OpenGL -framework AppKit
SRC_DIR 	= 	src/

CC			=	gcc
FLAGS		= 	-Werror -Wall -Wextra -g

SRC_FILES	=	main.c \
				miniRT.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

all		:	$(NAME)

$(NAME)	: 
		@$(CC) $(FLAGS) $(SRC) -I includes/ $(MINILIBX) $(OPENGL) -o $(NAME)
		@echo compiling done, like a boss 😎
		@echo running program... 💾
		#@./$(NAME)

bonus	:	all
		@echo you got the bonus!...🌟

clean	:
		@echo Cleaning ...🧼

fclean	: 	clean
		@rm -rf $(NAME)
		@echo everything cleaned and shiny 🗑

re		:	fclean all
		@echo Now you can reach the stars 🚀

.PHONY: clean fclean all re bonus
