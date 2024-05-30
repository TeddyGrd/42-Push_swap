/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:55:58 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/30 18:31:57 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_bits(int num)
{
	int	counter;

	counter = 0;
	while (num)
	{
		counter++;
		num = num / 2;
	}
	return (counter);
}

void	radix_one(t_stack *stack, int bit, int b_size, int max_bit)
{
	while (b_size-- && (bit <= max_bit))
	{
		if (((stack->head_b->data >> bit) & 1) == 1)
			pa(stack);
		else
			rb(stack);
	}
}

void	radix_zero(t_stack *stack, int bit)
{
	if (!ft_is_sorted(stack))
	{
		if (((stack->head_a->data >> bit) & 1) == 0)
			pb(stack);
		else
			ra(stack);
	}
}

void	radix_sort(t_stack *stack)
{
	int		i;
	int		j;
	int		max_bit;
	int		size;
	int		b_size;

	i = 0;
	max_bit = find_max_bits(stack->a_size);
	while (i <= max_bit)
	{
		j = 0;
		size = stack->a_size;
		while (j < size)
		{
			radix_zero(stack, i);
			j++;
		}
		b_size = stack->b_size;
		i++;
		radix_one(stack, i, b_size, max_bit);
	}
	while (stack->b_size)
		pa(stack);
}
