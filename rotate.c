/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:08:18 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/30 19:15:40 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stacks **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return ;
	*head = (*head)->next;
}

void	ra(t_stack *stack)
{
	rotate(&stack->head_a);
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	rotate(&stack->head_b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack)
{
	rotate(&stack->head_a);
	rotate(&stack->head_b);
	ft_printf("rr\n");
}
