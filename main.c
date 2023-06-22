#include "monty.h"
/**
 * main - entrycode to monty interperter
 * @ac: count of arguments
 * @av: vector for arguments
 * Return: 0 
*/
int main(int ac, char** av)
{
	int status = 0;
	FILE fileDesc;
	char *bytFile;

	//check supplied arguments
	ifValidArgs(ac);
	//handle file
	//status = interpert(file);
	//close file
	return (status);
}
