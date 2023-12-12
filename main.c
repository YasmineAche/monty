#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    stack_t *stack = NULL;
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    char *line = NULL;
    size_t len = 0;
    int line_number = 1;
    while (getline(&line, &len, file) != -1)
    {
        char *opcode = strtok(line, " \n");
        if (opcode == NULL || opcode[0] == '#')
        {
            free(line);
            continue;
        }
        get_func(opcode)(&stack, line_number);
        free(line);
        line_number++;
    }
    fclose(file);
    free_stack(stack);
    return (0);
}
