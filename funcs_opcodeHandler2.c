#include "monty.h"
/**
 * add - Adds top two elements in stack.
 * @stack: affected stack.
 * @line_number: number of the executed line.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *newstack1, *newstack2;

	if (data->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		garbageCollection();
		exit(EXIT_FAILURE);
	}
	newstack1 = data->head;
	newstack2 = newstack1->next;
	newstack2->n = newstack1->n + newstack2->n;
	popTopStack();
	data->stack_length -= 1;
	(void) stack;
}
/**
 * nop - do nothing
 * @stack: affected stack.
 * @line_number: number of the executed line.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
/**
 * sub - opcode to subtract top element from the second top element.
 * @stack: affected stack.
 * @line_number: number of the executed line.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *newstack1, *newstack2;

	if (data->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		garbageCollection();
		exit(EXIT_FAILURE);
	}
	newstack1 = data->head;
	newstack2 = newstack1->next;
	newstack2->n = newstack2->n - newstack1->n;
	popTopStack();
	data->stack_length -= 1;
	(void) stack;
}
/**
 * ddiv - opcode to Divide second top element by the top element.
 * @stack: affected stack.
 * @line_number: number of the executed line.
 */
void ddiv(stack_t **stack, unsigned int line_number)
{
	stack_t *newstack1, *newstack2;

	if (data->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		garbageCollection();
		exit(EXIT_FAILURE);
	}
	newstack1 = data->head;
	newstack2 = newstack1->next;
	if (newstack1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		garbageCollection();
		exit(EXIT_FAILURE);
	}
	newstack2->n = newstack2->n / newstack1->n;
	popTopStack();
	data->stack_length -= 1;
	(void) stack;
}
/**
 * mul - Divides the second top element of the stack by the top element.
 * @stack: affected stack.
 * @line_number: number of the executed line.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *newstack1, *newstack2;

	if (data->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		garbageCollection();
		exit(EXIT_FAILURE);
	}
	newstack1 = data->head;
	newstack2 = newstack1->next;
	newstack2->n = newstack2->n * newstack1->n;
	popTopStack();
	data->stack_length -= 1;
	(void) stack;
}
