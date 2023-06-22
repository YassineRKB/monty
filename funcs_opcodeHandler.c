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

	if (!data || data->n_tokens <= 1 || !(checknumber(data->tokens[1])))
	{
		garbageCollection();
		fprintf(stderr, PUSH_ERROR, line_number);
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
