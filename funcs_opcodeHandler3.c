#include "monty.h"
/**
 * mod - opcode to get remain of div of 2nd top element by the top element.
 * @stack: affected stack.
 * @line_number: number of the executed line.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *newstack1, *newstack2;

	if (data->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
	newstack2->n = newstack2->n % newstack1->n;
	popTopStack();
	data->stack_length -= 1;
	(void) stack;
}
/**
 * pchar - opcode tp print the char in top of the stack,
 * followed by a new line
 * @stack: affected stack.
 * @line_number: number of the executed line.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *newstack;

	if (data->head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		garbageCollection();
		exit(EXIT_FAILURE);
	}
	newstack = data->head;
	if (newstack->n < 0 || newstack->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		garbageCollection();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", newstack->n);
	(void) stack;
}
/**
 * pstr - opcode to print the string on top of the stack, followed by a newline
 * @stack: affected stack.
 * @line_number: number of the executed line.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *newstack;

	newstack = data->head;
	while (newstack != NULL)
	{
		if (newstack->n <= 0 || newstack->n > 127)
			break;
		printf("%c", newstack->n);
		newstack = newstack->next;
	}
	printf("\n");
	(void) stack;
	(void) line_number;
}
