# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:12:00 by tguerran          #+#    #+#              #
#    Updated: 2024/04/15 13:28:36 by tguerran         ###   ########.fr        #
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
		push_main.c

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