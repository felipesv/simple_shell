#include "simple_shell.h"
/**
 * main - main
 * @argc: number of arguments
 * @argv: arguments
 * @env: enviroment variables
 *
 * Return: is a void
 */
int main(int argc, char **argv, char **env)
{
	char *valuePrompt, **arguments, *valuePath;
	int *status_fork = NULL;
	(void)argc;

	do {
		valuePrompt = _prompt(isatty(STDIN_FILENO));
		if (valuePrompt == NULL)
		{
					freeDoublePointer(arguments);
		freePointer(valuePrompt);
		freePointer(valuePath);
			return (0);
		}

		arguments = _sortArguments(valuePrompt, argv[0]);
		valuePath = buildPath(arguments, argv[0], env);
		if (valuePath == NULL)
			_error(127, arguments, argv[0]);
		else
		{
			_process(status_fork, valuePath, arguments, env);
		}
		freeDoublePointer(arguments);
		freePointer(valuePrompt);
		freePointer(valuePath);
		arguments = NULL;
		valuePrompt = NULL;
		valuePath = NULL;

	} while (1);

	return (*status_fork);
}
