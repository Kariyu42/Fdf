# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 15:32:35 by kquetat-          #+#    #+#              #
#    Updated: 2023/04/30 13:34:28 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Colors ###
ITALIC		=	\033[3m
BOLD		=	\033[1m
LGREEN		=	\033[1;32m
PALEBLUE	=	\033[38;5;153m
CREAM		=	\033[38;5;255m
CHAMPAGNE	=	\033[38;5;224m
BEIGE		=	\033[38;5;230m
RESET		=	\033[0m

### Name of library & other variables ###
NAME 		=	libft.a
HEADER_PATH	=	../inc/
SRCS_PATH	=	srcs/
COUNTER		=	0
CUR_UP		=	\033[A

### Loading Bar ###
TOTAL_SRCS	=	$(shell find srcs -type f -name '*.c' | wc -l)
PERCENT		=	$(shell expr 100 \* $(COUNTER) / $(TOTAL_SRCS))
BAR			=	$(shell expr 27 \* $(COUNTER) / $(TOTAL_SRCS))

### Compiler & Other variables ###
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c
	@$(eval COUNTER = $(shell expr $(COUNTER) + 1))
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo " $(PALEBLUE)$(BOLD)$(ITALIC) Loading [$(LGREEN)LIBFT$(PALEBLUE)]: $(RESET)"
	@printf "\t\t\t$(BOLD)$(PALEBLUE)[$(BEIGE)%-27.$(BAR)s$(PALEBLUE)] %d/%d [%d%%]" "===========================" $(COUNTER) $(TOTAL_SRCS) $(PERCENT)
	@echo "$(CUR_UP)$(CUR_UP)"

OBJ	=	$(SRCS:.c=.o)

RM	=	rm -f

### Mandatory part ###
SRCS	=	${addprefix $(SRCS_PATH), ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memchr.c ft_memmove.c ft_toupper.c ft_tolower.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c}

### Rules ###
all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@printf "\n\n\n\t$(ITALIC)$(BOLD)$(PALEBLUE)[$(LGREEN)LIBFT$(PALEBLUE)] $(BEIGE)Compiled!$(RESET)\n"

clean:
	@$(RM) $(OBJ)
	@printf "\n\t$(ITALIC)$(BOLD)$(CREAM)CLEANED [$(BEIGE)LIBFT .o$(CREAM)] files$(RESET)\n"

fclean:	clean
	@$(RM) $(NAME)
	@printf "\n\t$(ITALIC)$(BOLD)$(CHAMPAGNE)libft.a CLEANED$(RESET)\n\n"

re:	fclean all

.PHONY:	all clean fclean re