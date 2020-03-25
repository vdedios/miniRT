# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 14:19:32 by vde-dios          #+#    #+#              #
#    Updated: 2020/02/02 20:07:30 by vde-dios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	 libft.a

CC		=	 gcc

CFLAGS	=	 -Werror -Wall -Wextra -g

AR		=	 ar -rcs

SRC		=	 ft_atoi.c 			\
			 ft_atoi_free.c 	\
			 ft_bzero.c 		\
			 ft_calloc.c 		\
			 ft_isalnum.c 		\
			 ft_isalpha.c 		\
			 ft_isascii.c 		\
			 ft_isdigit.c 		\
			 ft_isprint.c 		\
			 ft_itoa.c 			\
			 ft_uitoa.c 		\
			 ft_itoa_special.c 	\
			 ft_memccpy.c 		\
			 ft_memchr.c 		\
			 ft_memcmp.c 		\
			 ft_memcpy.c 		\
			 ft_memmove.c 		\
			 ft_memset.c 		\
			 ft_putchar_fd.c 	\
			 ft_putendl_fd.c 	\
			 ft_putnbr_fd.c 	\
			 ft_putstr_fd.c 	\
			 ft_putstr_len.c 	\
			 ft_split.c 		\
			 ft_strchr.c 		\
			 ft_strdup.c 		\
			 ft_strjoin.c 		\
			 ft_intjoin.c 		\
			 ft_strjoin_none.c 	\
			 ft_strjoin_second.c\
			 ft_strjoin_first.c \
			 ft_strlcat.c 		\
			 ft_strlcpy.c 		\
			 ft_strlen.c 		\
			 ft_intlen.c 		\
			 ft_toupper.c 		\
			 ft_tolower.c 		\
			 ft_substr.c 		\
			 ft_strtrim.c 		\
			 ft_strrchr.c 		\
			 ft_strncmp.c 		\
			 ft_strmapi.c 		\
			 ft_strnstr.c		\
			 ft_lstadd_front_bonus.c 	\
			 ft_lstlast_bonus.c 	\
			 ft_lstnew_bonus.c 	\
			 ft_lstsize_bonus.c 	\
			 ft_lstadd_back_bonus.c \
			 ft_lstdelone_bonus.c 	\
			 ft_lstclear_bonus.c	\
			 ft_lstmap_bonus.c	\
			 ft_lstiter_bonus.c

OBJS	 =	$(SRC:%.c=%.o)

OBJ_BONUS=	$(BONUS:%.c=%.o)

all	:	$(NAME)

$(NAME)	: 	$(OBJS) libft.h
		@echo compiling libft...
		@$(AR) $(NAME) $(OBJS)
		@echo success ✅

%.o	:	%.c
		@$(CC) $(CFLAGS) -c $< -o $@ -I.

bonus	:	$(OBJS) $(OBJ_BONUS) libft.h
		@$(AR) $(NAME) $(OBJ_BONUS) $(OBJS)

clean	:
		@echo cleaning libft...
		@rm -rf $(OBJS) $(OBJ_BONUS)

fclean	: 	clean
		@rm -rf $(NAME)

re	:	fclean all

.PHONY: clean fclean all re bonus
