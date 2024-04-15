/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:07:06 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/15 13:13:58 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_Stack *stack_a)
{
	t_StackNode	*last;

	if (stack_a->top == NULL || stack_a->top->next == NULL)
		return ;
	last = stack_a->top;
	while (last->next->next != NULL)
		last = last->next;
	last->next->next = stack_a->top;
	stack_a->top = last->next;
	last->next = NULL;
}

void	rrb(t_Stack *stack_b)
{
	t_StackNode	*last;

	if (stack_b->top == NULL || stack_b->top->next == NULL)
		return ;
	last = stack_b->top;
	while (last->next->next != NULL)
		last = last->next;
	last->next->next = stack_b->top;
	stack_b->top = last->next;
	last->next = NULL;
}

void	rrr(t_Stack *stack_a, t_Stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
