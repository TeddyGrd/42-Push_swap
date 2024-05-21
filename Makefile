# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:12:00 by tguerran          #+#    #+#              #
#    Updated: 2024/05/22 01:45:36 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Push_swap

CFLAGS = -Wall -Werror -Wextra 

SRC = push_swap.c \
		push_push.c \
		push_reverse.c \
		push_rotate.c \
		push_error.c \
		push_utils.c \
		push_main.c \
		push_algo.c \
		push_tiny.c 

OFILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	@make -C Libft
	cc $(CFLAGS) $(OFILES) Libft/libft.a
	
clean:
	@make clean -C Libft
	rm -f $(OFILES)

fclean: clean
	@make fclean -C Libft
	rm -f $(NAME)

re: fclean $(NAME)