#include "monty.h"
/**
 * openStream - func to handle stream
 * @filename: monty file
 * Return: void
*/
void openStream(char *filename)
{
	data->stream = fopen(filename, "r");
	if (!data->stream)
		streamErrorHandler(filename);
}
/**
 * streamErrorHandler - func to handl file i/o erro
 * @filename: target file
 * Return: void
*/
void streamErrorHandler(char *filename)
{
	fprintf(stderr, STREAM_ERROR, filename);
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
