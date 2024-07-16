#include "monty.h"
int the_number;
int the_N_check;
char *the_code;
/**
 * check_line - search for opcode
 * @lineStr: line to check
 */
void check_line(char *lineStr)
{
	int i = 0, n = 0, x = 0;
	char *ptr_code = NULL;
	char *ptr_int = NULL;
	int number = 0;

	the_N_check = -1;
	for (i = 0; lineStr[i] != 10 && lineStr[i] != 0; i++)
	{
		if (lineStr[i] >= 97 && lineStr[i] <= 122 && n == 0)
		{
			n = i;
			while (lineStr[n] >= 97 && lineStr[n] <= 122)
			{
				n++;
				x++;
			}
			ptr_code = malloc(sizeof(char) * (x + 1));
			n = 0;
			while (lineStr[i] >= 97 && lineStr[i] <= 122)
			{
				ptr_code[n] = lineStr[i];
				i++;
				n++;
			}
			ptr_code[n] = '\0';
			n = -1;
		}
		if (lineStr[i] >= 48 && lineStr[i] <= 57 && n == -1)
		{
			n = i;
			x = 0;
			while (lineStr[n] >= 48 && lineStr[n] <= 57)
			{
				n++;
				x++;
			}
			ptr_int = malloc(sizeof(char) * (x + 1));
			n = 0;
			while (lineStr[i] >= 48 && lineStr[i] <= 57)
			{
				ptr_int[n] = lineStr[i];
				i++;
				n++;
			}
			ptr_int[n] = '\0';
			number = atoi(ptr_int);
			n = -2;
			the_N_check = 0;
		}
	}
	if (the_N_check == 0)
		free(ptr_int);
	the_code = ptr_code;
	the_number = number;
}
