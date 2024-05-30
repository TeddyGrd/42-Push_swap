/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:07:06 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/30 19:15:01 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stacks **head)
{
	if (!(*head) || !(*head)->next)
		return ;
	*head = (*head)->pre;
}

void	rra(t_stack *stack)
{
	if (stack->a_size > 0)
	{
		reverse_rotate(&(stack->head_a));
		ft_printf("rra\n");
	}
}

void	rrb(t_stack *stack)
{
	if (stack->b_size > 0)
	{
		reverse_rotate(&(stack->head_b));
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack *stack)
{
	if (stack->a_size > 0)
	{
		reverse_rotate(&(stack->head_a));
	}
	if (stack->b_size > 0)
	{
		reverse_rotate(&(stack->head_b));
	}
	if (stack->a_size > 0 || stack->b_size > 0)
	{
		ft_printf("rrr\n");
	}
}
