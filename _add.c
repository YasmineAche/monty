#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _add - add the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->prev = *stack;
    (*stack)->prev = (*stack)->next;
    (*stack)->next = (*stack)->next->next;
    (*stack)->prev->next = *stack;
    *stack = (*stack)->prev;
    (*stack)->next->next = tmp;
    tmp->prev = (*stack)->next;
    tmp->next = NULL;
}
