/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:14:31 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/31 01:53:40 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_head(t_stacks **head, int *size)
{
	t_stacks	*temp;

	temp = *head;
	if ((*head)->next == *head)
		*head = NULL;
	else
	{
		(*head)->pre->next = (*head)->next;
		(*head)->next->pre = (*head)->pre;
		*head = (*head)->next;
	}
	(*size)--;
	free(temp);
}

void	add_node(t_stacks **head, int *size, int data)
{
	t_stacks	*new;

	new = (t_stacks *)malloc(sizeof(t_stacks));
	if (!new)
		exit(EXIT_FAILURE);
	new->data = data;
	if (!*size)
	{
		new->next = new;
		new->pre = new;
		*head = new;
	}
	else
	{
		new->next = *head;
		new->pre = (*head)->pre;
		(*head)->pre->next = new;
		(*head)->pre = new;
		*head = new;
	}
	(*size)++;
}

void	pa(t_stack *stack)
{
	if (stack->b_size)
	{
		add_node(&stack->head_a, &stack->a_size, stack->head_b->data);
		delete_head(&stack->head_b, &stack->b_size);
		ft_printf("pa\n");
	}
}

void	pb(t_stack *stack)
{
	if (stack->a_size)
	{
		add_node(&stack->head_b, &stack->b_size, stack->head_a->data);
		delete_head(&stack->head_a, &stack->a_size);
		ft_printf("pb\n");
	}
}
