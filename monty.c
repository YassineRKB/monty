#include "monty.h"
/**
 * interpreter - main monty function
 * @filename: target file to iterpret
 * Description: a function to handle and organize the
 * logic flow of monty interpreter
 * Return: void
*/
void interpreter(char *filename)
{
	size_t buff = 0;

	openStream(filename);
	for (; getline(&data->line, &buff, data->stream) != -1;)
	{
		data->line_number += 1;
		genTokens();
		parseInstractions();
		runInstruction();
		freeTokens();
	}
	garbageCollection();
}
/**
 * garbageCollection - frees memory and sets pointers to null
 * Return: void
*/
void garbageCollection(void)
{
	closeStream();
	freeTokens();
	freeData();
}
/**
 * freeStack - func to free stack
 * @h: pointer to head node
 * Return: void
*/
void freeStack(stack_t *h)
{
	if (!h)
		return;
	if (h->next)
		freeStack(h->next);
	free(h);
}
