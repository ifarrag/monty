#include "monty.h"
int the_N_check;
/**
 * push - push value to new stack
 * @stack: the head
 * @line_number: line number from check()
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *head = NULL;
	stack_t *new = NULL;

	if (the_N_check == -1)
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		free(the_code);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	if (head == NULL)
	{
		head = malloc(sizeof(stack_t));
		if (head == NULL)
		{
			dprintf(2, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		head->n = the_number;
		head->prev = NULL;
		head->next = NULL;
		*stack = head;
	}
	else
	{
		while (head->next != NULL)
			head = head->next;
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			dprintf(2, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new->n = the_number;
		new->next = NULL;
		new->prev = head;
		head->next = new;
		*stack = new;
	}
}
