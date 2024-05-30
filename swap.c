/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:10:16 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/30 19:16:56 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stacks *head)
{
	int	temp;

	if (head == NULL || head->next == NULL)
		return ;
	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
}

void	sa(t_stack *stack)
{
	swap(stack->head_a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	swap(stack->head_b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack)
{
	swap(stack->head_a);
	swap(stack->head_b);
	ft_printf("ss\n");
}
