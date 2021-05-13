#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack(LIFO), queues(FIFO)
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack(LIFO), queues(FIFO)
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct strct_s - struct of info's structs
 * @file: monty file
 * @line: line file
 * @stack: stack_t list
 * @line_number: line number
 * @state: int 0
 * Description: global struct with program info
 */
typedef struct var_s
{
	FILE *file;
	char *line;
	stack_t *stack;
	unsigned int line_number;
	int state;
} var_t;

extern var_t vars;

void get_op(char *op, stack_t **stack, unsigned int line_number);
var_t m_push(char *param, var_t vars);
var_t m_push2(char *param, var_t vars);
void m_pall(stack_t **stack, unsigned int line_number);
void m_pint(stack_t **stack, unsigned int line_number);
void m_pop(stack_t **stack, unsigned int line_number);
void m_swap(stack_t **stack, unsigned int line_number);
void m_add(stack_t **stack, unsigned int line_number);
void m_nop(stack_t **stack, unsigned int line_number);
void m_sub(stack_t **stack, unsigned int line_number);
void m_mul(stack_t **stack, unsigned int line_number);
void m_div(stack_t **stack, unsigned int line_number);
void m_mod(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void m_pchar(stack_t **stack, unsigned int line_number);
void m_pstr(stack_t **stack, unsigned int line_number);
var_t free_strct(var_t vars);
void free_stack1(stack_t *head);
void m_fs_close(int status, void *arg);
void free_lineptr(int status, void *arg);

#endif /* _MONTY_H_ */
