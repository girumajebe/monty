#include "monty.h"

/**
 * init - sets initial values for data
 * @vars: global variable
 * Return: (vars)
 */
var_t init(var_t vars)
{
	vars.file = NULL;
	vars.line = NULL;
	vars.stack = NULL;
	vars.line_number = 1;
	vars.state = 0;
	return (vars);
}

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments passed
 * @argv: array of argument strings
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	var_t vars;
	char *val, *op = NULL;
	size_t n = 0;

	vars = init(vars);
	if (argc != 2)
	{
		dprintf(STDOUT_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	vars.file = fopen(argv[1], "r");
	if (vars.file == NULL)
	{
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&vars.line, &n, vars.file) != -1)
	{
		op = strtok(vars.line, "\n\t\r ");
		if (*op == '#' || *op == '\n')
		{
			vars.line_number++;
			continue;
		}
		if (strcmp(op, "push") == 0)
		{
			val = strtok(NULL, " ");
			vars = m_push2(val, vars);
			vars.line_number++;
			continue;
		}
		if (op != NULL && op[0] != '#')
		{
			get_op(op, &vars.stack, vars.line_number);
		}
		vars.line_number++;
	}
	free_strct(vars);
	exit(EXIT_SUCCESS);
}
