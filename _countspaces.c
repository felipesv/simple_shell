#include "simple_shell.h"
/**
 * countSpace - count the arguments
 * @prompt: prompt value
 *
 * Return: spaces counted
 */
int countSpace(char *prompt)
{
	int cnt = 0, size = 1;

	while (*(prompt + cnt))
	{
		if (*(prompt + cnt) == 32)
			size++;
		cnt++;
	}

	return (size);
}
