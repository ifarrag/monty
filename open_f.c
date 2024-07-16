#include "monty.h"
/**
 * open_f - open the file "read only"
 * @filename: argv[1]
 */
void open_f(char *filename)
{
	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
