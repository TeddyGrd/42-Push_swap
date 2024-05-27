/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:14:31 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/27 01:47:31 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void delete_head_a(t_stack *sa)
{
	t_stacks *temp;

	temp = sa->head_a;
	if (sa->head_a->next == sa->head_a)
		sa->head_a = NULL;
	else
	{
		sa->head_a->pre->next = sa->head_a->next;
		sa->head_a->next->pre = sa->head_a->pre;
		sa->head_a = sa->head_a->next;
	}
	sa->a_size--;
	free(temp);
	ft_printf("pb\n");
}

void delete_head_b(t_stack *sa)
{
	t_stacks *temp;

	temp = sa->head_b;
	if (sa->head_b->next == sa->head_b)
		sa->head_b = NULL;
	else
	{
		sa->head_b->pre->next = sa->head_b->next;
		sa->head_b->next->pre = sa->head_b->pre;
		sa->head_b = sa->head_b->next;
	}
	sa->b_size--;
	free(temp);
	ft_printf("pa\n");
}

void pa(t_stack *stack)
{
	t_stacks *new;

	if (stack->b_size)
	{
		new = (t_stacks *)malloc(sizeof(t_stacks));
		if (!new)
		{
			exit(EXIT_FAILURE);
		}
		new->data = stack->head_b->data;

		if (!stack->a_size)
		{
			new->next = new;
			new->pre = new;
			stack->head_a = new;
		}
		else
		{
			new->next = stack->head_a;
			new->pre = stack->head_a->pre;
			stack->head_a->pre->next = new;
			stack->head_a->pre = new;
			stack->head_a = new;
		}
		stack->a_size++;
		delete_head_b(stack);
	}
}

void pb(t_stack *stack)
{
	t_stacks *new;

	if (stack->a_size)
	{
		new = (t_stacks *)malloc(sizeof(t_stacks));
		if (!new)
		{
			exit(EXIT_FAILURE);
		}
		new->data = stack->head_a->data;

		if (!stack->b_size)
		{
			new->next = new;
			new->pre = new;
			stack->head_b = new;
		}
		else
		{
			new->next = stack->head_b;
			new->pre = stack->head_b->pre;
			stack->head_b->pre->next = new;
			stack->head_b->pre = new;
			stack->head_b = new;
		}
		stack->b_size++;
		delete_head_a(stack);
	}
}