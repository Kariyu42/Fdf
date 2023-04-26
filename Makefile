# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 14:06:13 by kquetat-          #+#    #+#              #
#    Updated: 2023/04/26 12:30:00 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Name of executable ###
NAME		=	fdf
HEADER		=	includes/
LIBFT		=	libft/libft/
SRCS_PATH	=	srcs/

### Compilation & flags ###
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

### Source Files ###
SRCS	=	${addprefix ${SRCS_PATH}, fdf.c}

### Colors ###
BEIGE		=	\033[38;5;230m
CREAM		=	\033[38;5;255m
IVORY		=	\033[38;5;253m
OFF_WHITE	=	\033[38;5;251m
EGGSHELL	=	\033[38;5;251m
CHAMPAGNE	=	\033[38;5;224m

### Rules ###

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	make -C 

clean:
	$(RM) $(OBJS)

fclean:	clean
	

re:	fclean all

.PHONY:	all clean fclean re