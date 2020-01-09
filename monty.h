#ifndef _MONTY_H
#define _MONTY_H

/* libraries */
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/* global structure */
/**
 * struct monty_s - global structure
 * @file: open file value
 * @stack: stack
 * @buff: file content
 * @new_n: strtok content
 *
 * Description: global structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct monty_s
{
	FILE *file;
	stack_t *stack;
	char *buff;
	char *new_n;
	bool change;
} monty_t;
/* global variable */
extern monty_t global;
/* functions of the program process */
void _open(char *filename);
int _read(void);
void _execute(void);
/* error functions */
void err_one_arg(int ac);
void err_op(char *filename);
void err_line(unsigned int line, char *opcd, int sel);
void err_malloc(stack_t *elem);
void err_ascii(stack_t **stack, unsigned int line_number);
/* get instruction */
void(*get(char *s, unsigned int l))(stack_t **stack, unsigned int line_number);
/* _isdigit*/
int _isdigit(void);
/* free */
void free_stack(stack_t *stack);
void free_close(void);
/* Instruction functions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void queue_stack(stack_t **stack, unsigned int line_number);
void _pstack(stack_t **stack, stack_t *elem);
void _pqueue(stack_t **stack, stack_t *elem);
stack_t *_ps(stack_t **stack, int n);

#endif /* _MONTY_H */
