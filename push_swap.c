/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:10:16 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/08 15:43:52 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void sa(Stack* stack) {
    if (stack->top == NULL || stack->top->next == NULL) {
        return;
    }
    int temp = stack->top->data;
    stack->top->data = stack->top->next->data;
    stack->top->next->data = temp;
}

void sb(Stack* stack) {
    if (stack->top == NULL || stack->top->next == NULL) {
        return;
    }
    int temp = stack->top->data;
    stack->top->data = stack->top->next->data;
    stack->top->next->data = temp;
}

void ss(Stack* stack_a, Stack* stack_b) {
    sa(stack_a);
    sb(stack_b);
}

void pa(Stack* stack, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pb(Stack* stack_a, Stack* stack_b) {
    if (stack_a->top == NULL || stack_a->top->next == NULL) {
        return;
    }
    StackNode* last_a = stack_a->top;
    StackNode* last_b = stack_b->top;
    while (last_a->next != NULL) {
        last_a = last_a->next;
    }
    last_a->next = stack_b->top;
    stack_b->top = stack_a->top->next;
    last_a->next->next = NULL;
}

void ra(Stack* stack) {
    if (stack->top == NULL || stack->top->next == NULL) {
        return;
    }
    StackNode* last = stack->top;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = stack->top;
    stack->top = stack->top->next;
    last->next->next = NULL;
}

void rb(Stack* stack) {
    if (stack->top == NULL || stack->top->next == NULL) {
        return;
    }
    StackNode* last = stack->top;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = stack->top;
    stack->top = stack->top->next;
    last->next->next = NULL;
}

void rr(Stack* stack_a, Stack* stack_b) {
    ra(stack_a);
    rb(stack_b);
}

void rra(Stack* stack) {
    if (stack->top == NULL || stack->top->next == NULL) {
        return;
    }
    StackNode* last = stack->top;
    while (last->next->next != NULL) {
        last = last->next;
    }
    last->next->next = stack->top;
    stack->top = last->next;
    last->next = NULL;
}
void rrb(Stack* stack) {
    if (stack->top == NULL || stack->top->next == NULL) {
        return;
    }
    StackNode* last = stack->top;
    while (last->next->next != NULL) {
        last = last->next;
    }
    last->next->next = stack->top;
    stack->top = last->next;
    last->next = NULL;
}

void rrr(Stack* stack_a, Stack* stack_b) {
    rra(stack_a);
    rrb(stack_b);
}

bool isSorted(Stack* stack) {
    if (stack == NULL || stack->top == NULL) {
        return true;
    }

    StackNode* current = stack->top;
    while (current->next != NULL) {
        if (current->data > current->next->data) {
            return false;
        }
        current = current->next;
    }
    return true;
}

void printStack(Stack* stack) {
    if (stack == NULL || stack->top == NULL) {
        printf("La pile est vide.\n");
        return;
    }

    printf("Contenu de la pile : ");
    StackNode* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


int main() {
    Stack* stack_a = createStack();
    // Stack* stack_b = createStack();
    stack_a = ;

    printStack(stack_a);
    rra(stack_a);
    rrb(stack_a);
    printStack(stack_a);
    printf("La pile a est triée.\n");

    // Libérer la mémoire
    // ...

    return 0;
}
