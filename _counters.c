#include "simple_shell.h"

int countArguments(char **arg)
{
	int cnt = 0;

	while (arg[cnt] != NULL)
		cnt++;

	return (cnt);
}

int lengthArray(char *array)
{
	int length = 0;

	while (array[length] != '\0')
	{
		length++;
	}

	return (length);
}
