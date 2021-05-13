#include "monty.h"

/**
 * m_sub - subtract top element of stack from next element and push result
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *head = *stack;

	if (!head || !head->next)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	next = head->next;
	next->n -= head->n;
	m_pop(stack, line_number);
}
