#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - A function that adds an element onto the stack
 * @stack: A pointer to the top of the stack
 * @line_no: The line of the opcode in the monty file
 * @value: An int value thet is to be added onto the stack
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_no, int value)
{
	stack_t *node_n;
	UNUSED(line_no);
	node_n = malloc(sizeof(stack_t));

	if (node_n == NULL)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node_n->n = value;
	node_n->prev = NULL;

	if (*stack == NULL)
	{
		node_n->next = NULL;
	}
	else
	{
		node_n->next = *stack;
		(*stack)->prev = node_n;
	}
	*stack = node_n;
}

/**
 * pall - Function that returns all the elements in a stack
 * @stack: A pointer to the top of the stack
 * @line_no: The line of the opcode in the monty file
 * Return: Nothing
 */

#define UNUSED(x) (void)(x)

void pall(stack_t **stack, unsigned int line_no)
{
	stack_t *temp = *stack;
	UNUSED(line_no);

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

int main(void)
{
	stack_t *stack = NULL;

	push(&stack, 1, 1);
	push(&stack, 2, 2);
	push(&stack, 3, 3);
	push(&stack, 4, 4);

	return (0);
}
