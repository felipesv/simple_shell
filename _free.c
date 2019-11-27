#include "simple_shell.h"

void freeDoublePointer(char **pointer)
{
	int cnt = 0;

	if (pointer != NULL)
	{
		while (pointer[cnt] != NULL)
		{
			free(pointer[cnt]);
			cnt++;
		}
		free(pointer[cnt]);
		free(pointer);
	}
}


void freePointer(char *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
	}
}
