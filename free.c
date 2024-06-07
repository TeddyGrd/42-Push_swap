/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:26:01 by tguerran          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/07 14:48:16 by tguerran         ###   ########.fr       */
=======
/*   Updated: 2024/06/05 13:42:54 by tguerran         ###   ########.fr       */
>>>>>>> 3a55bd76fdf991af16e256b4b2827a215f159d0c
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_init(t_stack *stack)
{
	t_stacks	*temp;
	t_stacks	*next_node;

	temp = stack->head_a;
	while (1)
	{
		next_node = temp->next;
		free(temp);
		temp = next_node;
		if (temp == stack->head_a)
			break ;
	}
	stack->a_size = 0;
	stack->head_a = NULL;
	exit(0);
}

void	free_split(char **numbers)
{
	size_t	i;

	if (!numbers)
		return ;
	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}
