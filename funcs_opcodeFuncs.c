#include "monty.h"
/**
 * popTopStack - func to delete node from linked list
*/
void popTopStack(void)
{
	stack_t *newstack;

	newstack = data->head;
	data->head = newstack->next;
	free(newstack);
}
