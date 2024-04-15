/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:08:18 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/15 13:14:15 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_Stack *stack_a)
{
	t_StackNode	*last;

	if (stack_a->top == NULL || stack_a->top->next == NULL)
		return ;
	last = stack_a->top;
	while (last->next != NULL)
		last = last->next;
	last->next = stack_a->top;
	stack_a->top = stack_a->top->next;
	last->next->next = NULL;
}

void	rb(t_Stack *stack_b)
{
	t_StackNode	*last;

	if (stack_b->top == NULL || stack_b->top->next == NULL)
		return ;
	last = stack_b->top;
	while (last->next != NULL)
		last = last->next;
	last->next = stack_b->top;
	stack_b->top = stack_b->top->next;
	last->next->next = NULL;
}

void	rr(t_Stack *stack_a, t_Stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
