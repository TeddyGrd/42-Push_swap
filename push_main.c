/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:28:08 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/19 16:36:21 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(t_Stack *stack) {
    t_StackNode *current = stack->top;
    int max_value = 0;
    while (current) {
        if (current->data > max_value) {
            max_value = current->data;
        }
        current = current->next;
    }
    int bits = 0;
    while ((max_value >> bits) != 0) {
        bits++;
    }
    return bits;
}

int stack_size(t_Stack *stack) {
    int size = 0;
    t_StackNode *current = stack->top;
    while (current) {
        size++;
        current = current->next;
    }
    return size;
}

void radix_sort(t_Stack *a, t_Stack *b) {
    int max_bits = get_max_bits(a);
    int i = 0;
    
    while (i < max_bits) {
        int size = stack_size(a);
        int j = 0;
        
        while (j < size) {
            int num = a->top->data;
            if ((num >> i) & 1) {
                ra(a);
            } else {
                pb(a, b);
            }
            j++;
        }
        while (b->top) {
            pa(a, b);
        }  
        i++;
    }
}

int is_sorted(t_Stack *stack) {
    if (!stack->top) {
        return 1; // Une pile vide est considérée comme triée
    }
    t_StackNode *current = stack->top;
    while (current->next != NULL) {
        if (current->data > current->next->data) {
            return 0; // La pile n'est pas triée
        }
        current = current->next;
    }
    return 1; // La pile est triée
}

int	main(int argc, char *argv[])
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;
	int		i;

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

    radix_sort(stack_a, stack_b);
	ft_printf("\nPile triee:\n");
    printstack(stack_a);
	if (is_sorted(stack_a)) {
        printf("La pile est triée.\n");
    } else {
        printf("La pile n'est pas triée.\n");
    }

	return (0);
}
