#include "monty.h"

/**
 * m_pop - pop top element off of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop = *stack;
	stack_t *next;

	if (!pop)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	next = pop->next;
	free(pop);
	*stack = next;
	pop = *stack;
	if (pop)
		pop->prev = NULL;
}
