/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:55:58 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/24 22:48:06 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(t_Stack *stack)
{
    int max = 0;
    t_StackNode *node = stack->top;
    while (node)
    {
        if (node->data > max)
        {
            max = node->data;
        }
        node = node->next;
    }
    int bits = 0;
    while (max != 0)
    {
        max /= 2;
        bits++;
    }
    return bits;
}

// Fonction pour le tri radix
void radix_sort(t_Stack *a, t_Stack *b)
{
    int max_bits = get_max_bits(a);
    int i = 0;

    while (i < max_bits)
    {
        int size = 0;
        t_StackNode *temp = a->top;
        while (temp)
        {
            size++;
            temp = temp->next;
        }

        int j = 0;
        while (j < size)
        {
            if (((a->top->data >> i) & 1) == 1)
            {
                pb(a, b); // Déplacer vers 'b' si le bit est 1
            }
            else
            {
                ra(&a); // Sinon, rotation de la pile 'a'
            }
            j++;
        }

        while (b->top)
        {
            pa(a, b); // Remettre les éléments de 'b' dans 'a'
        }
        i++;
    }
}