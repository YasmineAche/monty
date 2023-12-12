#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _pall - print all elements of the stack
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    (void)line_number;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}
