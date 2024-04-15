/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:24:17 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/15 14:39:53 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct StackNode
{
	int					data;
	struct StackNode	*next;
}	t_StackNode;

typedef struct Stack
{
	t_StackNode	*top;
}	t_Stack;

t_Stack	*createstack(void);
int		check_error(int argc, char *argv[]);
void	ra(t_Stack *stack_a);
void	rb(t_Stack *stack_b);
void	rr(t_Stack *stack_a, t_Stack *stack_b);
void	rra(t_Stack *stack_a);
void	rrb(t_Stack *stack_b);
void	rrr(t_Stack *stack_a, t_Stack *stack_b);
void	pa(t_Stack *stack_a, t_Stack *stack_b);
void	pb(t_Stack *stack_b, t_Stack *stack_a);
void	pushdata(t_Stack *stack, int data);
int		pop(t_Stack *stack);
void	printstack(t_Stack *stack);
int		main(int argc, char *argv[]);

#endif
