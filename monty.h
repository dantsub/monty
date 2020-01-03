#ifndef _MONTY_H
#define _MONTY_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

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

void err_one_arg(void);
void err_op(void);
void err_line(int count);
void err_malloc(void);
void (*get(char *s))(stack_t **stack, unsigned int line_number);
stack_t *_push(stack_t **stack, unsigned int line_number);
stack_t *_pall(stack_t **stack, unsigned int line_number);
stack_t *_pint(stack_t **stack, unsigned int line_number);
stack_t *_swap(stack_t **stack, unsigned int line_number);
stack_t *_pop(stack_t **stack, unsigned int line_number);
stack_t *_add(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

#endif /* _MONTY_H */
