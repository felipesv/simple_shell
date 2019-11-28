#include "simple_shell.h"
/**
 * freeDoublePointer - free a double pointer
 * @pointer: pointer to free
 *
 * Return: is a void
 */
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
/**
 * freePointer - free a pointer
 * @pointer: pointer to free
 *
 * Return: is a void
 */
void freePointer(char *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
	}
}
