#include "monty.h"
arg_t *data = NULL;
/**
 * main - entrycode to monty interperter
 * @ac: count of arguments
 * @av: vector for arguments
 * Return: 0
*/
int main(int ac, char **av)
{
	ifValidArgs(ac);
	dataInit();
	interpreter(av[1]);
	return (EXIT_SUCCESS);
}
