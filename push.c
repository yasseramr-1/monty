#include "monty.h"

/**
 * f_push - Adds a node to the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number
 *
 * Description: This function adds a node to the stack with the value
 * specified in the global variable 'bus.arg'. It checks if the argument
 * is a valid integer and handles errors accordingly. The node is added to
 * the stack or queue based on the value of 'bus.lifi'.
 *
 * Return: No return value
 */
void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0, flag = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            j++;
        for (; bus.arg[j] != '\0'; j++)
        {
            if (bus.arg[j] > '9' || bus.arg[j] < '0')
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    n = atoi(bus.arg);

    if (bus.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}
