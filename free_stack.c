#include "monty.h"

/**
 * free_strct - handle free
 * @vars: var_t struct of variables
 * Return: (vars)
 */
var_t free_strct(var_t vars)
{
	fclose(vars.file);
	if (vars.line)
	{
		free(vars.line);
		vars.line = NULL;
	}
	if (vars.stack)
	{
		free_stack1(vars.stack);
		vars.stack =  NULL;
	}
	return (vars);
}

/**
 * free_stack1 - frees the stack on exit
 * @head: pointer to the head of a stack
 *
 * Return: void
 */
void free_stack1(stack_t *head)
{
	stack_t *tmp, *current = head;

	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
