/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:10:16 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/22 01:40:35 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_Stack *stack)
{
	int temp;

	if (stack->top == NULL || stack->top->next == NULL)
		return;
	temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
}

void sa(t_Stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void sb(t_Stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void ss(t_Stack *stack_a, t_Stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
