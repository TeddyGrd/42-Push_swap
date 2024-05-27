/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:24:17 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/27 01:29:34 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_stacks
{
	int data;
	struct s_stacks *next;
	struct s_stacks *pre;
} t_stacks;

typedef struct s_stack
{
	t_stacks *head_a;
	t_stacks *head_b;
	int *sorted;
	int a_size;
	int b_size;
} t_stack;

int check_error(int argc, char *argv[]);
void sa(t_stack *sa);
void sb(t_stack *sb);
void ss(t_stack *stack);
void ra(t_stack *sa);
void rb(t_stack *sb);
void rr(t_stack *stack);
void rra(t_stack *sa);
void rrb(t_stack *sb);
void rrr(t_stack *stack);
void pa(t_stack *sa);
void pb(t_stack *sb);

void ft_stack_init(t_stack *s, int argc, char **argv);
int ft_is_sorted(t_stack *stack);
void tiny_sort(t_stack *stack);
void four_sort(t_stack *stack);
void five_sort(t_stack *stack);
void radix_sort(t_stack *stack);
void ft_free(t_stack *stack);
void free_split(char **numbers);
void ft_free_init(t_stack *s);
t_stacks *find_higest(t_stacks *head);
void ft_push_back(t_stack *sa, char *number);
int find_min_index(t_stacks *s);

#endif
