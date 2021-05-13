#include "monty.h"

/**
 * check_for_digit - checks that a string only contains digits
 * @arg: string to check
 *
 * Return: 0 if only digits, else 1
 */
static int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * m_push - push an integer onto the stack
 * @param: node
 * @vars: struct of variables
 *
 * Return: vars
 */

var_t m_push(char *param, var_t vars)
{
	int n;
	stack_t *new, *current = vars.stack;
	char *arg = NULL;

        arg = strchr(param, '\n');
        if (arg)
                *arg = 0;
	if (!strlen(param) || check_for_digit(param))
	{
		dprintf(STDOUT_FILENO,
			"L%d: usage: push integer\n",
			vars.line_number);
		fclose(vars.file);
		free(vars.line);
		free_stack1(vars.stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(param);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		fclose(vars.file);
		free(vars.line);
		free_stack1(vars.stack);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (!current)
	{
		new->prev = NULL;
		vars.stack = new;
		return (vars);
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
	new->prev = current;
	return (vars);
}

/**
 * m_push2 - push an integer onto the stack
 * @param: node
 * @vars: struct of variables
 *
 * Return: vars
 */

var_t m_push2(char *param, var_t vars)
{
	int n;
	stack_t *new;
	char *arg = NULL;

	arg = strchr(param, '\n');
	if (arg)
		*arg = 0;
	if (!strlen(param) || check_for_digit(param))
	{
		dprintf(STDERR_FILENO,
			"L%d: usage: push integer\n",
			vars.line_number);
		fclose(vars.file);
		free(vars.line);
		free_stack1(vars.stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(param);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		fclose(vars.file);
		free(vars.line);
		free_stack1(vars.stack);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = vars.stack;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	vars.stack = new;
	return (vars);
}
