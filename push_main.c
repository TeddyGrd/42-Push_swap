/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:28:08 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/19 16:25:05 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isEmpty(t_Stack* stack) {
    // Vérifier si le sommet de la pile est NULL, ce qui signifie que la pile est vide
    return stack->top == NULL;
}

// Algorithme de tri
// Algorithme de tri
void simpleSort(t_Stack* stack_a, t_Stack* stack_b) {
    while (!isEmpty(stack_a)) {
        int min = INT_MAX;
        t_StackNode* current = stack_a->top;
        t_StackNode* min_node = NULL;
        // Trouver le plus petit élément dans la pile A
        while (current != NULL) {
            if (current->data < min) {
                min = current->data;
                min_node = current;
            }
            current = current->next;
        }
        // Déplacer le nœud contenant le plus petit élément vers le sommet de la pile A
        if (min_node != NULL) {
            while (stack_a->top != min_node) {
                ra(stack_a);
                // Si le nœud est au bas de la pile A, faire une rotation inverse pour le ramener au sommet
                if (stack_a->top == min_node) {
                    rra(stack_a);
                }
            }
            // Déplacer le nœud contenant le plus petit élément vers la pile B
            pb(stack_a, stack_b);
        }
    }
    // Déplacer les éléments de la pile B vers la pile A (triée)
    while (!isEmpty(stack_b)) {
        pa(stack_a, stack_b);
    }
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

    simpleSort(stack_a, stack_b);
    ft_printf("\nPile triee:\n");
    printstack(stack_a);
	return (0);
}
