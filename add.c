#include "monty.h"

/**
 * m_add - add the top two elements of the stack
 * @stack: double pointer tot he beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void m_add(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *head = *stack;

	if (!head || !head->next)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	next = head->next;
	next->n += head->n;
	m_pop(stack, line_number);
}
