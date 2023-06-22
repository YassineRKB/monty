#include "monty.h"
/**
 * get_instructions - func to get instructions from tokens
 * Return: void
*/
void parseInstractions(void)
{
	instruction_t instructions[] = {
		{"push", &push},
		{"pall", &pall},
		{NULL, NULL}
	};
	int i = 0;

	if (data->n_tokens == 0)
		return;
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
 * invlaid_instruction - func to handle invalid instruction
 * Return: void
*/
void invalidInstructionHandler(void)
{
	int line = data->line_number;
	char *tok = data->tokens[0];

	fprintf(stderr, UNKNOW_INSTRUCT,
	line, tok);
	garbageCollection();
	exit(EXIT_FAILURE);
}
/**
 * run_instruction - func to run instructions
 * Return: void
*/
void runInstruction(void)
{
	stack_t *stack = NULL;

	if (data->n_tokens == 0)
		return;
	data->instruction->f(&stack, data->line_number);
}
