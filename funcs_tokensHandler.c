#include "monty.h"
/**
 * genTokens - func to tokenize line
 * Return: void.
*/
void genTokens(void)
{
	char *token = NULL, *linecpy = NULL;
	int tokenId = 0;

	linecpy = malloc(sizeof(char) * (strlen(data->line) + 1));
	strcpy(linecpy, data->line);
	data->n_tokens = 0;
	token = strtok(linecpy, " \n");
	while (token)
	{
		data->n_tokens += 1;
		token = strtok(NULL, " \n");
	}
	data->tokens = malloc(sizeof(char *) * (data->n_tokens + 1));
	strcpy(linecpy, data->line);
	token = strtok(linecpy, " \n");
	while (token)
	{
		data->tokens[tokenId] = malloc(sizeof(char) * (strlen(token) + 1));
		if (!data->tokens[tokenId])
			mallocErrorHandler();
		strcpy(data->tokens[tokenId], token);
		token = strtok(NULL, " \n");
		tokenId++;
	}
	data->tokens[tokenId] = NULL;
	free(linecpy);
}
/**
 * freeTokens - func to handle freeing tokens
 * Return: void
*/
void freeTokens(void)
{
	int i = 0;

	if (!data->tokens)
		return;
	while (data->tokens[i])
	{
		free(data->tokens[i]);
		i++;
	}
	free(data->tokens);
	data->tokens = NULL;
}
