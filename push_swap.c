/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:10:16 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/15 13:35:19 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_Stack *stack_a)
{
	int	temp;

	if (stack_a->top == NULL || stack_a->top->next == NULL)
		return ;
	temp = stack_a->top->data;
	stack_a->top->data = stack_a->top->next->data;
	stack_a->top->next->data = temp;
}

void	sb(t_Stack *stack_b)
{
	int	temp;

	if (stack_b->top == NULL || stack_b->top->next == NULL)
		return ;
	temp = stack_b->top->data;
	stack_b->top->data = stack_b->top->next->data;
	stack_b->top->next->data = temp;
}

void	ss(t_Stack *stack_a, t_Stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
