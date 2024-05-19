/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:59:37 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/19 16:51:10 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_all_save_three(t_Stack **stack_a, t_Stack **stack_b) {
    int stack_size;
    int pushed;
    int i;

    stack_size = stack_size(*stack_a); // Remplacer par ta fonction pour obtenir la taille de la pile
    pushed = 0;
    i = 0;
    while (stack_size > 6 && i < stack_size && pushed < stack_size / 2) {
        if ((*stack_a)->top->data <= stack_size / 2) { // Remplacer par l'accès au premier élément de la pile
            pb(stack_a, stack_b); // Remplacer par ta fonction pour pousser un élément de A à B
            pushed++;
        } else {
            ra(stack_a); // Remplacer par ta fonction pour faire une rotation de la pile A
        }
        i++;
    }
    while (stack_size - pushed > 3) {
        pb(stack_a, stack_b); // Remplacer par ta fonction pour pousser un élément de A à B
        pushed++;
    }
}

static void shift_stack(t_Stack **stack_a) {
    int lowest_pos;
    int stack_size;

    stack_size = stack_size(*stack_a); // Remplacer par ta fonction pour obtenir la taille de la pile
    lowest_pos = get_lowest_index_position(stack_a); // Adapter pour fonctionner avec ta structure de données
    if (lowest_pos > stack_size / 2) {
        while (lowest_pos < stack_size) {
            rra(stack_a); // Remplacer par ta fonction pour faire une rotation inverse de la pile A
            lowest_pos++;
        }
    } else {
        while (lowest_pos > 0) {
            ra(stack_a); // Remplacer par ta fonction pour faire une rotation de la pile A
            lowest_pos--;
        }
    }
}

void sort(t_Stack **stack_a, t_Stack **stack_b) {
    push_all_save_three(stack_a, stack_b); // Adapter pour fonctionner avec tes structures de données
    tiny_sort(stack_a); // Adapter pour fonctionner avec tes structures de données
    while (*stack_b) {
        get_target_position(stack_a, stack_b); // Adapter pour fonctionner avec tes structures de données
        get_cost(stack_a, stack_b); // Adapter pour fonctionner avec tes structures de données
        do_cheapest_move(stack_a, stack_b); // Adapter pour fonctionner avec tes structures de données
    }
    if (!is_sorted(*stack_a)) {
        shift_stack(stack_a); // Adapter pour fonctionner avec tes structures de données
    }
}

static int find_highest_value(t_StackNode *top) {
    int highest = top->data; // Initialiser avec la première valeur de la pile
    while (top) {
        if (top->data > highest) {
            highest = top->data; // Mettre à jour la valeur la plus élevée
        }
        top = top->next; // Passer au prochain élément de la pile
    }
    return highest;
}


void tiny_sort(t_Stack **stack) {
    int highest;

    if (is_sorted(*stack)) {
        return;
    }
    highest = find_highest_value((*stack)->top); // Trouver la plus grande valeur dans la pile
    if ((*stack)->top->data == highest) { // Si la première valeur est la plus grande
        ra(stack); // Faire une rotation de la pile A
    } else if ((*stack)->top->next->data == highest) { // Si la deuxième valeur est la plus grande
        rra(stack); // Faire une rotation inverse de la pile A
    }
    if ((*stack)->top->data > (*stack)->top->next->data) { // Si les deux premières valeurs sont dans le mauvais ordre
        sa(stack); // Faire un échange des deux premiers éléments de la pile A
    }
}



