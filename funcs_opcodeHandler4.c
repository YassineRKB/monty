#include "monty.h"
/**
 * stack -  LIFO opcode to sets the structure of data in stack.
 * @stack: affected stack.
 * @line_number: number of the executed line.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	data->stack = 1;
	(void) stack;
	(void) line_number;
}
/**
 * queue -  FIFO opcode to sets the structure of data in stack.
 * @stack: affected stack.
 * @line_number: number of the executed line.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	data->stack = 0;
	(void) stack;
	(void) line_number;
}
