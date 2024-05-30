/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:56:57 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/31 01:57:15 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tab_init(int argc, char **argv, int *tab)
{
	char	**numbers;
	int		i;
	int		j;
	int		c;

	i = 1;
	c = 0;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		j = 0;
		while (numbers[j])
			tab[c++] = ft_atoi(numbers[j++]);
		free_split(numbers);
		i++;
	}
}

void	ft_init_sort(t_stack *stack)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < stack->a_size)
	{
		j = i + 1;
		while (j < stack->a_size)
		{
			if (stack->sorted[i] > stack->sorted[j])
			{
				temp = stack->sorted[i];
				stack->sorted[i] = stack->sorted[j];
				stack->sorted[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_sorted(t_stack *stack)
{
	t_stacks	*tmp;
	int			i;

	i = 0;
	stack->sorted = (int *)malloc(sizeof(int) * stack->a_size);
	tmp = stack->head_a;
	while (1)
	{
		stack->sorted[i++] = tmp->data;
		tmp = tmp->next;
		if (tmp == stack->head_a)
			break ;
	}
}

void	ft_init_index(t_stack *stack)
{
	int			i;
	t_stacks	*temp;

	temp = stack->head_a;
	while (1)
	{
		i = 0;
		while (i < stack->a_size)
		{
			if (temp->data == stack->sorted[i])
			{
				temp->data = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
		if (temp == stack->head_a)
			break ;
	}
}

void	ft_stack_init(t_stack *stack, int argc, char **argv)
{
	int		i;
	int		j;
	char	**numbers;

	stack->a_size = 0;
	stack->b_size = 0;
	stack->head_a = NULL;
	stack->head_b = NULL;
	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		j = 0;
		while (numbers[j])
			ft_push_back(stack, numbers[j++]);
		free_split(numbers);
		i++;
	}
	if (ft_is_sorted(stack))
		ft_free_init(stack);
	ft_init_sorted(stack);
	ft_init_sort(stack);
	ft_init_index(stack);
}
