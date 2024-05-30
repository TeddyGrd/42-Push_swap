/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:41:01 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/30 18:50:59 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack *stack)
{
	t_stacks	*max_node;

	max_node = find_highest(stack->head_a);
	if (stack->head_a == max_node)
		ra(stack);
	else if (stack->head_a->next == max_node)
		rra(stack);
	if (stack->head_a->data > stack->head_a->next->data)
		sa(stack);
}

void	four_sort(t_stack *stack)
{
	int	index;

	index = find_min_index(stack->head_a);
	while (index != 0)
	{
		if (index < stack->a_size / 2)
			ra(stack);
		else
			rra(stack);
		index = find_min_index(stack->head_a);
	}
	pb(stack);
	tiny_sort(stack);
	pa(stack);
}

void	five_sort(t_stack *stack)
{
	int	index;

	index = find_min_index(stack->head_a);
	while (index != 0)
	{
		if (index <= stack->a_size / 2)
			ra(stack);
		else
			rra(stack);
		index = find_min_index(stack->head_a);
	}
	pb(stack);
	four_sort(stack);
	pa(stack);
}
