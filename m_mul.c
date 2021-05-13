#include "monty.h"

/**
 * m_mul - multiply top two elements of stack and push result
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *head = *stack;

	if (!head || !head->next)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	next = head->next;
	next->n *= head->n;
	m_pop(stack, line_number);
}
