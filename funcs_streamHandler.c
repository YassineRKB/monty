#include "monty.h"
/**
 * openStream - func to handle stream
 * @filename: monty file
 * Return: void
*/
void openStream(char *filename)
{
	int fileDesc;

	fileDesc = open(filename, O_RDONLY);
	if (fileDesc == -1)
		streamErrorHandler(filename);

	data->stream = fdopen(fileDesc, "r");
	if (data->stream == NULL)
	{
		close(fileDesc);
		streamErrorHandler(filename);
	}
}
/**
 * streamErrorHandler - func to handl file i/o erro
 * @filename: target file
 * Return: void
*/
void streamErrorHandler(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	garbageCollection();
	exit(EXIT_FAILURE);
}
/**
 * closeStream - func to close stream
 * Return: void
*/
void closeStream(void)
{
	if (!data->stream)
		return;
	fclose(data->stream);
	data->stream = NULL;
}
