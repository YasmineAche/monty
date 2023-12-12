#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _pop - pop the top element of the stack
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    (void)line_number;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    *stack = (*stack)->next;
    free(tmp);
    (*stack)->prev = NULL;
}
