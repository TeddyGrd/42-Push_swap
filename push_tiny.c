/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:41:01 by mcombeau          #+#    #+#             */
/*   Updated: 2024/05/22 01:41:19 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_highest_value(t_Stack *stack)
{
	int highest = stack->top->data;
	t_StackNode *current = stack->top;
	while (current)
	{
		if (current->data > highest)
			highest = current->data;
		current = current->next;
	}
	return highest;
}

void tiny_sort(t_Stack **stack)
{
	if (is_sorted(*stack))
		return;

	int highest = find_highest_value(*stack);

	if ((*stack)->top->data == highest)
		ra(stack);
	else if ((*stack)->top->next->data == highest)
		rra(stack);

	if ((*stack)->top->data > (*stack)->top->next->data)
		sa(*stack);
}