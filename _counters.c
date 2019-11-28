#include "simple_shell.h"
/**
 * countArguments - count arguments
 * @arg: arguments to count
 *
 * Return: return string cocatenated
 */
int countArguments(char **arg)
{
	int cnt = 0;

	while (arg[cnt] != NULL)
		cnt++;

	return (cnt);
}
/**
 * lengthArray - count length
 * @array: arguments to count
 *
 * Return: return string cocatenated
 */
int lengthArray(char *array)
{
	int length = 0;

	while (array != NULL && array[length] != '\0')
	{
		length++;
	}

	return (length);
}
