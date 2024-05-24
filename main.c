/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:28:08 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/24 22:09:31 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_Stack *stack)
{
	if (!stack->top)
	{
		return 1;
	}
	t_StackNode *current = stack->top;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
		{
			return 0;
		}
		current = current->next;
	}
	return 1;
}

static void push_swap(t_Stack **stack_a, t_Stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(*stack_a);
	else if (stack_size == 3 && !is_sorted(*stack_a))
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		radix_sort(*stack_a, *stack_b);
}

int main(int argc, char *argv[])
{
	t_Stack *stack_a;
	t_Stack *stack_b;
	int i;
	int stack_size;

	i = 1;
	if (check_error(argc, argv) == 1)
		return (1);
	stack_a = createstack();
	stack_b = createstack();
	while (i < argc)
	{
		pushdata(stack_a, (ft_atoi((argv[i]))));
		i++;
	}
	printstack(stack_a);
	stack_size = get_stack_size(stack_a);
	push_swap(&stack_a, &stack_b, stack_size);
	printstack(stack_a);
	if (is_sorted(stack_a))
	{
		printf("La pile est triée.\n");
	}
	else
	{
		printf("La pile n'est pas triée.\n");
	}

	return (0);
}
