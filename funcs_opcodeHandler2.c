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
