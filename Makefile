# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:12:00 by tguerran          #+#    #+#              #
#    Updated: 2024/05/27 01:30:26 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Push_swap

CFLAGS = -Wall -Werror -Wextra 

SRC = swap.c \
		push.c \
		reverse.c \
		rotate.c \
		error.c \
		utils.c \
		main.c \
		algo.c \
		init.c \
		push_tiny.c \
		free.c

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