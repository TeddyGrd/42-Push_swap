# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:12:00 by tguerran          #+#    #+#              #
#    Updated: 2024/03/21 15:49:24 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Push_swap

CFLAGS = -Wall -Werror -Wextra 

SRC = push_swap.c \
		error.c \

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