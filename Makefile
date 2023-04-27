# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 14:06:13 by kquetat-          #+#    #+#              #
#    Updated: 2023/04/27 13:25:09 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Name of executable ###
NAME		=	fdf
HEADER		=	includes/
LIBFT		=	libft/libft/
SRCS_PATH	=	srcs/
GNL_PATH	=	libft/get_next_line/

### Colors ###
ITALIC		=	\033[3m
BOLD		=	\033[1m
BEIGE		=	\033[38;5;230m
CREAM		=	\033[38;5;255m
IVORY		=	\033[38;5;253m
OFF_WHITE	=	\033[38;5;251m
EGGSHELL	=	\033[38;5;251m
CHAMPAGNE	=	\033[38;5;224m

### Loading Bar ###
COUNTER		=	0
CUR_UP		=	\033[A
TOTAL_SRCS	=	$(shell find srcs -type f -name '*.c' | find $(GNL_PATH) -type f -name '*.c' | wc -l)
PERCENT		=	$(shell expr 100 \* $(COUNTER) / $(TOTAL_SRCS))
BAR			=	$(shell expr 27 \* $(COUNTER) / $(TOTAL_SRCS))

### Compilation & flags ###
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

%.o: %.c
	@$(eval COUNTER = $(shell expr $(COUNTER) + 1))
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
	@echo " $(PALEBLUE)$(BOLD)$(ITALIC) Loading [$(LGREEN)FDF$(PALEBLUE)]: $(RESET)"
	@printf "\t\t\t$(BOLD)$(PALEBLUE)[$(BEIGE)%-27.$(BAR)s$(PALEBLUE)] %d/%d [%d%%]" "===========================" $(COUNTER) $(TOTAL_SRCS) $(PERCENT)
	@echo "$(CUR_UP)$(CUR_UP)"

### Source Files ###
SRCS	=	${addprefix ${SRCS_PATH}, fdf.c} \
			${addprefix ${GNL_PATH}, get_next_line.c, get_next_line_utils.c}

OBJS	=	$(SRCS:.c=.o)

### Rules ###

all:	$(NAME)

$(NAME):	$(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBFT)libft.a $(OBJS) -o $(NAME)
	@printf "\n\n\t $(BOLD)$(ITALIC)$(EGGSHELL)FDF COMPILED $(RESET)\n"

clean:
	@$(RM) $(OBJS)
	@printf "\n\t$(BOLD)$(ITALIC)$(OFF_WHITE)[$(BEIGE)FDF$(OFF_WHITE)] .o files $(LGREEN)CLEANED$(RESET)\n"
	@make clean -C $(LIBFT)

fclean:	clean
	@$(RM) $(LIBFT)libft.a $(NAME)
	@printf "\n\t$(BOLD)$(ITALIC)$(OFF_WHITE)[$(BEIGE)FDF$(OFF_WHITE)] $(CHAMPAGNE)executable CLEANED$(RESET)\n"

re:	fclean all

.PHONY:	all clean fclean re