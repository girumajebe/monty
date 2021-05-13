#include "monty.h"

/**
 * m_swap - swap top two elements of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *head = *stack;
	int tmp;

	if (!head || !head->next)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	next = head->next;
	tmp = head->n;
	head->n = next->n;
	next->n = tmp;
}
