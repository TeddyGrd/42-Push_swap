/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:56:57 by tguerran          #+#    #+#             */
/*   Updated: 2024/06/04 02:32:25 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}
