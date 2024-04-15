/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:14:31 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/15 13:16:20 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushdata(t_Stack *stack, int data)
{
	t_StackNode	*newNode;

	newNode = (t_StackNode *)malloc(sizeof(t_StackNode));
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
}

void	pa(t_Stack *stack_a, t_Stack *stack_b)
{
	int	data;

	if (stack_b == NULL || stack_b->top == NULL)
		return ;
	data = pop(stack_b);
	pushdata(stack_a, data);
}

void	pb(t_Stack *stack_b, t_Stack *stack_a)
{
	int	data;

	if (stack_a == NULL || stack_a->top == NULL)
		return ;
	data = pop(stack_a);
	pushdata(stack_b, data);
}
