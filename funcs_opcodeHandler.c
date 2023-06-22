#include "monty.h"
/**
 * push - push int i to stack
 * @stack: affected stack
 * @line_number: number of the executed line.
 * Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack;

	fflush(stderr);
	if (data->n_tokens <= 1 || !(checknumber(data->tokens[1])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		garbageCollection();
		exit(EXIT_FAILURE);
	}
	s = malloc(sizeof(stack_t));
	if (!s)
		mallocErrorHandler();
	s->next = s->prev = NULL;
	s->n = (int) atoi(data->tokens[1]);
	if (!data->head)
		data->head = s;
	else
	{
		if (data->stack)
		{
			s->next = data->head;
			data->head->prev = s;
			data->head = s;
		}
		else
		{
			stack_t *newstack = data->head;

			while (newstack->next)
				newstack = newstack->next;
			newstack->next = s;
			s->prev = newstack;
		}
	}
	data->stack_length += 1;
}
/**
 * pall - func to print elements in stack.
 * @stack: affected stack.
 * @line_number: number of the executed line.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *newstack;

	if (!data->head)
		return;
	newstack = data->head;
	while (newstack)
	{
		printf("%d\n", newstack->n);
		newstack = newstack->next;
	}
	(void) line_number;
	(void) stack;
}
/**
 * pint - prints top of the stack.
 * @stack: affected stack.
 * @line_number: number of the executed line.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!data->head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		garbageCollection();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", data->head->n);
	(void) stack;
	fflush(stdout);
}
/**
 * pop - pops top element of the stack.
 * @stack: affected stack
 * @line_number: number of the executed line.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (data->head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		garbageCollection();
		exit(EXIT_FAILURE);
	}
	popTopStack();
	data->stack_length -= 1;
	(void) stack;
}
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the swap function is called.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *nstack1, *nstack2;

	if (data->stack_length < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		garbageCollection();
		exit(EXIT_FAILURE);
	}
	nstack1 = data->head;
	nstack2 = nstack1->next;
	nstack1->next = nstack2->next;
	if (nstack1->next)
		nstack1->next->prev = nstack1;
	nstack2->next = nstack1;
	nstack1->prev = nstack2;
	nstack2->prev = NULL;
	data->head = nstack2;
	(void) stack;
}
