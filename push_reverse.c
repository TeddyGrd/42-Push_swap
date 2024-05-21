/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:07:06 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/22 00:44:10 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_Stack **stack)
{
	t_StackNode *last;
	t_StackNode *second_last;

	if (*stack == NULL || (*stack)->top == NULL || (*stack)->top->next == NULL)
		return;
	last = (*stack)->top;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = (*stack)->top;
	(*stack)->top = last;
}

void rra(t_Stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void rrb(t_Stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void rrr(t_Stack **stack_a, t_Stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
