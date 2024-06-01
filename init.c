/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:56:57 by tguerran          #+#    #+#             */
/*   Updated: 2024/06/01 18:16:17 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	char	**numbers;

	i = 0;
	stack->a_size = 0;
	stack->b_size = 0;
	stack->head_a = NULL;
	stack->head_b = NULL;
	numbers = parse_arguments(&argc, argv);
	while (i < argc)
		ft_push_back(stack, numbers[i++]);
	free_split(numbers);
	if (ft_is_sorted(stack))
	{
		ft_free_init(stack);
		return ;
	}
	ft_init_sorted(stack);
	ft_init_sort(stack);
	ft_init_index(stack);
}
