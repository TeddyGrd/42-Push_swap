/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:24:17 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/24 22:42:59 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct StackNode
{
	int data;
	int index;
	struct StackNode *next;
} t_StackNode;

typedef struct Stack
{
	t_StackNode *top;
} t_Stack;

t_Stack *createstack(void);
int check_error(int argc, char *argv[]);
void sa(t_Stack *stack_a);
void sb(t_Stack *stack_b);
void ss(t_Stack *stack_a, t_Stack *stack_b);
void ra(t_Stack **stack_a);
void rb(t_Stack **stack_b);
void rr(t_Stack **stack_a, t_Stack **stack_b);
void rra(t_Stack **stack_a);
void rrb(t_Stack **stack_b);
void rrr(t_Stack **stack_a, t_Stack **stack_b);
void pa(t_Stack *stack_a, t_Stack *stack_b);
void pb(t_Stack *stack_b, t_Stack *stack_a);
void pushdata(t_Stack *stack, int data);
int pop(t_Stack *stack);
void printstack(t_Stack *stack);
int main(int argc, char *argv[]);
int is_sorted(t_Stack *stack);
void tiny_sort(t_Stack **stack);
int get_stack_size(t_Stack *stack);
void radix_sort(t_Stack *a, t_Stack *b);

#endif
