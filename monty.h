#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct arg_s - arguments struct with memebers
 * @stream: stream
 * @line: line
 * @line_number: line number
 * @tokens: tokens
 * @n_tokens: number of tokens
 * @instruction: instructions
 * @head: top of stack
 * @stack: structure
 * @stack_length: checks number of nodes in linked list
 * Description: global pointer with various members
 * to be intialized at the start of the program
*/
typedef struct arg_s
{
	stack_t *head;
	int stack;
	int stack_length;
	FILE *stream;
	char *line;
	unsigned int line_number;
	char **tokens;
	int n_tokens;
	instruction_t *instruction;
} arg_t;
extern arg_t *data;

/* monty funcs */
void interpreter(char *filename);
void garbageCollection(void);

/* Argument&Data funcs */
void ifValidArgs(int ac);
void dataInit(void);
void mallocErrorHandler(void);
void freeData(void);
int checknumber(char *str);
void freeStack(stack_t *h);
void popTopStack(void);

/* stream funcs */
void streamErrorHandler(char *filename);
void openStream(char *filename);
void closeStream(void);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/* token funcs */
void genTokens(void);
void freeTokens(void);

/* instructions funcs */
void parseInstractions(void);
void runInstruction(void);
void invalidInstructionHandler(void);


/* opcode funcs */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void ddiv(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

#endif
