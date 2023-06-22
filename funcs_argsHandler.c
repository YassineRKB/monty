#include "monty.h"
/**
 * ifValidArgs - func to check supplied arguments
 * @ac: coount of passed arguments
 * Return: Void
*/
void ifValidArgs(int ac)
{
	if (ac == 2)
		return;
	fprintf(stderr, PORPER_USAGE);
	exit(EXIT_FAILURE);
}
/**
 * dataInit - func to init args
 * Return: void
*/
void dataInit(void)
{
	data = malloc(sizeof(arg_t));
	if (!data)
		mallocErrorHandler();
	data->instruction = malloc(sizeof(instruction_t));
	if (!data->instruction)
		mallocErrorHandler();
	data->stack = 1;
	data->stack_length = 0;
	data->head = NULL;
	data->stream = NULL;
	data->line = NULL;
	data->line_number = 0;
	data->n_tokens = 0;
}
/**
 * mallocErrorHandler - func to handle failed malloc
 * Return: void
*/
void mallocErrorHandler(void)
{
	fprintf(stderr, MALLOC_ERR);
	garbageCollection();
	exit(EXIT_FAILURE);
}
/**
 * freeData - func to free initialized args after fatal error
 * Return: void
*/
void freeData(void)
{
	if (!data)
		return;
	if (data->line)
	{
		free(data->line);
		data->line = NULL;
	}
	if (data->instruction)
	{
		free(data->instruction);
		data->instruction = NULL;
	}
	if (data->head)
	{
		freeStack(data->head);
		data->head = NULL;
	}
	free(data);
}
/**
 * checknumber - func to check if str represents valid integer number.
 * @str: target string.
 * Return: 1 on success, 0 on fail.
 */
int checknumber(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
