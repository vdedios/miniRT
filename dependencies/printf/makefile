# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 14:19:32 by vde-dios          #+#    #+#              #
#    Updated: 2020/01/23 16:59:54 by vde-dios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

OBJDIR 		=	obj/
SRC_DIR 	= 	src/
HEAD_DIR	=	includes/

CC			=	gcc
FLAGS		=	-Werror -Wall -Wextra -g
LFLAGS		=	-I includes/
AR			=	ar -rcs

SRC_FILES	= 	flags.c				\
				printf.c			\
				types_cspdiu.c		\
				types_hexfegn.c		\
				utils_format.c		\
				utils_printf.c		\
				utils_hexp.c		\
				width_precision.c	\
				thousands_utils.c	\
				utils_e.c			\
				utils_e_max.c		\
				utils_f.c			\
				utils_g.c

OBJ_FILES	=	$(SRC_FILES:%.c=%.o)
OBJ 		=	$(addprefix $(OBJDIR), $(OBJ_FILES))

all	: $(NAME)

$(OBJDIR):
		@mkdir -p $(OBJDIR)

$(NAME)	:	$(OBJDIR) $(OBJ)
		@echo compiling printf...
		@$(AR) $(NAME) $(OBJ)
		@echo success ✅

$(OBJDIR)%.o : $(SRC_DIR)%.c
		@$(CC) $(FLAGS) $(LFLAGS) -I../libft/ -c $< -o $@

bonus	:	all

clean	:
		@echo cleaning printf...
		@rm -rf $(OBJDIR)

fclean	: 	clean
		@rm -rf $(NAME)

re	:	fclean all

.PHONY: clean fclean all re bonus
