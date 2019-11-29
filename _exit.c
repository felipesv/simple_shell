#include "simple_shell.h"
/**
 * exitValidation - check if the command is exit
 * @prompt: prompt value
 *
 * Return: is a void
 */
void exitValidation(char *prompt)
{
	char *_exit = "exit\n";

	if (_strcmp(_exit, prompt) == 0)
	{
		free(prompt);
		exit(0);
	}
}
