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
