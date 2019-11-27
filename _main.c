#include "simple_shell.h"

int main (int argc, char **argv, char **env)
{
	char *valuePrompt, **arguments, *valuePath;
	int valueAccess, status_fork;
	pid_t child_process;
	(void)argc;

       do
       {
		valuePrompt = _prompt(isatty(STDIN_FILENO));
		if (valuePrompt == NULL)
			return (0);
		arguments = _sortArguments(valuePrompt, argv[0]);
		valuePath = buildPath(arguments, argv[0], env);

		if (valuePath == NULL)
			_error(127, arguments, argv[0]);
		else
		{
			valueAccess = access(valuePath, X_OK);
			if (valueAccess != 0)
				_error(126, arguments, argv[0]);
			else
			{
				child_process = fork();
				if (child_process == -1)
				{
					perror("Error");
					return (1);
				}
				if (child_process == 0)
				{
					if (execve(valuePath, arguments, env) == -1)
					{
						perror("Error");
						exit(127);
					}
				}
				else
				{
					wait(&status_fork);
				}
			}
		}

		freeDoublePointer(arguments);
		freePointer(valuePrompt);
		freePointer(valuePath);
		arguments = NULL;
		valuePrompt = NULL;
		valuePath = NULL;

       } while (1);

       return (status_fork);
}
