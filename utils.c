/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:26:02 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/27 01:29:24 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_sorted(t_stack *s)
{
	t_stacks *temp;

	if (s->a_size <= 1)
		return (1);
	temp = s->head_a;
	while (temp->next != s->head_a)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void ft_push_back(t_stack *sa, char *number)
{
	t_stacks *new;
	t_stacks *last;

	if (!sa->head_a)
	{
		new = (t_stacks *)malloc(sizeof(t_stacks));
		new->next = new;
		new->pre = new;
		new->data = ft_atoi(number);
		sa->head_a = new;
		sa->a_size++;
		return;
	}
	new = (t_stacks *)malloc(sizeof(t_stacks));
	new->data = ft_atoi(number);
	last = sa->head_a->pre;
	last->next = new;
	new->pre = last;
	new->next = sa->head_a;
	sa->head_a->pre = new;
	sa->a_size++;
}

t_stacks *find_higest(t_stacks *head)
{
	t_stacks *max;
	t_stacks *temp;

	max = head;
	temp = head;
	while (1)
	{
		if (temp->data > max->data)
			max = temp;
		temp = temp->next;
		if (temp == head)
			break;
	}
	return (max);
}

int find_min_index(t_stacks *s)
{
	int min_index;
	int min_value;
	int i;
	t_stacks *temp;

	min_index = -1;
	min_value = 2147483647;
	temp = s;
	i = 0;
	while (1)
	{
		if (min_value > temp->data)
		{
			min_value = temp->data;
			min_index = i;
		}
		temp = temp->next;
		i++;
		if (temp == s)
			break;
	}
	return (min_index);
}