#ifndef _MONTY_H_
#define _MONTY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
  * struct instruction_s - opcode and its functions
  * @opcode: the opcode
  * @f: functio to handle the opdcode
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
  * struct all_vars - it holds all the variables to be passed
  * @FO: flag to fetermine stack 0 or queue(1)
  * @f_name: string holding the file name
  * @f_ptr: file pointer to open file
  * @tokened: tokenized string of our input from file
  * @head: head of the stack
  * @line_number: line number that was just read from file
  * @buff: buffer for the line in the the file
  * Description: a struct taht we make global to pass variables for stacks, LIFO, FIFO
  *
  */
typedef struct all_vars
{
	int FO;
	char *f_name;
	FILE *fp;
	char **tokened;
	char *buff;
	struct stack_s *head;
	unsigned int line_number;
} all_vars_t;

extern all_vars_t *element;

void get_toks(char *buff);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
stack_t *add_stack_end(void);
stack_t *add_stack_beg(void);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);

void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _divide(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void exit_function(unsigned int err_int);
void l_free(stack_t *head);
void free_buf(void);
void free_token(void);
void _lifo(stack_t **stack, unsigned int line_number);
void _fifo(stack_t **stack, unsigned int line_number);
void opcode_getter(void);

#endif
