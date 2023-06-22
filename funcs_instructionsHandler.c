#include "monty.h"
/**
 * parseInstractions - func to get instructions from tokens
 * Return: void
*/
void parseInstractions(void)
{
	instruction_t instructions[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"nop", &nop},
		{"sub", &sub},
		{"div", &ddiv},
		{"mul", &mul},
		{"mod", &mod},
		{"pchar", &pchar},
		{"pstr", &pstr},
		{"rotl", &rotl},
		{NULL, NULL}
	};
	int i = 0;

	if (data->n_tokens == 0)
		return;
	if (data->tokens[0][0] == '#')
	{
		data->instruction->opcode = "nop";
		data->instruction->f = nop;
		return;
	}
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, data->tokens[0]) == 0)
		{
			data->instruction->opcode = instructions[i].opcode;
			data->instruction->f = instructions[i].f;
			return;
		}
		i++;
	}
	invalidInstructionHandler();
}
/**
 * invalidInstructionHandler - func to handle invalid instruction
 * Return: void
*/
void invalidInstructionHandler(void)
{
	int line = data->line_number;
	char *tok = data->tokens[0];

	fprintf(stderr, "L%d: unknown instruction %s\n",
	line, tok);
	garbageCollection();
	exit(EXIT_FAILURE);
}
/**
 * runInstruction - func to run instructions
 * Return: void
*/
void runInstruction(void)
{
	stack_t *stack = NULL;

	if (data->n_tokens == 0)
		return;
	data->instruction->f(&stack, data->line_number);
}
