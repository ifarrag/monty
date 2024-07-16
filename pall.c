#include "monty.h"
/**
 * pall - print the stack value from top
 * @stack: the top
 * @line_number: the line check
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (head != NULL)
	{
		while (head->next != NULL)
			head = head->next;
		if (head->prev != NULL)
		{
			while (head->prev != NULL)
			{
				printf("%d\n", head->n);
				head = head->prev;
			}
			printf("%d\n", head->n);
		}
		else
		{
			printf("%d\n", head->n);
		}
	}
}
