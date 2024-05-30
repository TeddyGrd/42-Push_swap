/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:26:02 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/31 00:21:53 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	t_stacks	*temp;

	if (stack->a_size <= 1)
		return (1);
	temp = stack->head_a;
	while (temp->next != stack->head_a)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_push_back(t_stack *sa, char *number)
{
	t_stacks	*new;
	t_stacks	*last;

	if (!sa->head_a)
	{
		new = (t_stacks *)malloc(sizeof(t_stacks));
		new->next = new;
		new->pre = new;
		new->data = ft_atoi(number);
		sa->head_a = new;
		sa->a_size++;
		return ;
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

t_stacks	*find_highest(t_stacks *head)
{
	t_stacks	*max;
	t_stacks	*temp;

	max = head;
	temp = head;
	while (1)
	{
		if (temp->data > max->data)
			max = temp;
		temp = temp->next;
		if (temp == head)
			break ;
	}
	return (max);
}

int	find_min_index(t_stacks *stack)
{
	int			min_index;
	int			min_value;
	int			i;
	t_stacks	*temp;

	min_index = -1;
	min_value = 2147483647;
	temp = stack;
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
		if (temp == stack)
			break ;
	}
	return (min_index);
}

long long	ft_strtoll(const char *nptr, char **endptr)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ')
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	if (endptr != NULL)
		*endptr = (char *)nptr;
	return (result * sign);
}
