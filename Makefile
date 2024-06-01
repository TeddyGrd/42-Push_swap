# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:12:00 by tguerran          #+#    #+#              #
#    Updated: 2024/06/01 18:09:59 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra 

SRC = swap.c \
		push.c \
		reverse.c \
		rotate.c \
		error.c \
		error2.c \
		utils.c \
		main.c \
		algo.c \
		init.c \
		push_tiny.c \
		utils2.c \
		parse.c \
		free.c

OFILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	@make -C Libft
	@if [ ! -z "$$(ar -t Libft/libft.a | grep libft.a)" ]; then \
		cc $(CFLAGS) $(OFILES) Libft/libft.a -o $(NAME); \
	else \
		cc $(CFLAGS) $(OFILES) -L Libft -lft -o $(NAME); \
	fi	
clean:
	@make clean -C Libft
	rm -f $(OFILES)

fclean: clean
	@make fclean -C Libft
	rm -f $(NAME)

re: fclean $(NAME)