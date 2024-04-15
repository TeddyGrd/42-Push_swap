/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:26:02 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/15 14:39:46 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Stack	*createstack(void)
{
	t_Stack	*stack;

	stack = (t_Stack *)malloc(sizeof(t_Stack));
	stack->top = NULL;
	return (stack);
}

int	pop(t_Stack *stack)
{
	int			data;
	t_StackNode	*temp;

	if (stack->top == NULL)
	{
		ft_printf("La pile est vide\n");
		return (-1);
	}
	data = stack->top->data;
	temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	return (data);
}

void	printstack(t_Stack *stack)
{
	t_StackNode	*current;

	if (stack == NULL || stack->top == NULL)
	{
		ft_printf("La pile est vide.\n");
		return ;
	}
	ft_printf("Contenu de la pile : ");
	current = stack->top;
	while (current != NULL)
	{
		ft_printf("%d ", current->data);
		current = current->next;
	}
	ft_printf("\n");
}
