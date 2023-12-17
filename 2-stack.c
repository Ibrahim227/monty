#include "monty.h"

/**
 * nop - Does nothing
 * @stack: Pointer point to top node
 * @line_number: Interger
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_node - Swaps the top two elements of the stack
 * @stack: Pointer
 * @line_number: Interger
 */
void swap_node(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_node - Adds node
 * @stack: Pointer
 * @line_number: Interger
 */
void add_node(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_node - delete node
 * @stack: Pointer
 * @line_number: Interg
 */
void sub_node(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_node - Add node
 * @stack: Pointer
 * @line_number: Intergerr
 */
void div_node(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
