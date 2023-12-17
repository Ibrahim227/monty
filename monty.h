#ifndef MONTY_H /* Start Monty */
#define MONTY_H
#define SIZE 5

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

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


void open_file(char *file_name);
void read_f(FILE *fd);
int parse_l(char *buffer, int line_number, int format);
void find_func(char *opcode, char *value, int ln, int format);
void call_fun(op_func func, char *op, char *val, int ln, int format);
void err(int err_code, ...);
void more_err(int err_code, ...);
void string_err(int err_code, ...);


#endif /* MONTY_H */
