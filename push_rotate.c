/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:08:18 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/19 15:43:37 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_Stack *stack)
{
	t_StackNode	*last;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	last->next = stack->top;
	stack->top = stack->top->next;
	last->next->next = NULL;
}

void	ra(t_Stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_Stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_Stack *stack_a, t_Stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
