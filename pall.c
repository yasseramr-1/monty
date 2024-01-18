#include "monty.h"

/**
 * f_pall - Prints the elements of the stack
 * @head: Pointer to the head of the stack
 * @counter: Unused parameter
 *
 * Description: This function prints the elements of the stack.
 * It traverses the stack and prints each element followed by a newline.
 *
 * Return: No return value
 */
void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *current;
    (void)counter;

    current = *head;

    if (current == NULL)
        return;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
