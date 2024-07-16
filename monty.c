#include "monty.h"
FILE *fd;
int the_number;
int the_N_check;
char *the_code = NULL;

/**
 * main - monty main
 * @ac: cmd ars count
 * @av: array of strings null termenated comd L args
 * Return: (0)Success
 */
int main(int ac, char **av)
{
	size_t n = 0;
	int lines = 1, i = 0, done = 0;
	char *lineStr;
	stack_t *head = NULL;
	stack_t *temp = NULL;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_f(av[1]);
	while (getline(&lineStr, &n, fd) != -1)
	{
		check_line(lineStr);
		if (the_code != NULL)
		{
			for (i = 0; ops[i].opcode != NULL; i++)
			{
				if (strcmp(ops[i].opcode, the_code) == 0)
				{
					ops[i].f(&head, lines);
					done = 1;
				}
			}
			if (done == 0)
			{
				dprintf(2, "L%d: unknown instruction <opcode>\n", lines);
				free(the_code);
				fclose(fd);
				exit(EXIT_FAILURE);
			}
			free(the_code);
			lines++;
		}
	}
	free(lineStr);
	while (head->prev != NULL)
		head = head->prev;
	temp = head;
	while (temp != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	fclose(fd);
}
