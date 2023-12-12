#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _push - push an element to the stack
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    int value;

    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    value = (*stack)->n;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    *stack = new_node;
}
