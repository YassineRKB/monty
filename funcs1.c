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
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * push - function for monty opcode push, puts int i in stack
 * @i: int i to be pushed to stack
 * Return: void
*/
void push(int i);
