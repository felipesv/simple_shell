#include "simple_shell.h"
/**
 * _process - process child and parent
 * @status_fork: status fork
 * @valuePath: path
 * @arguments: arguments
 * @env: enviroments variables
 *
 * Return: void
 */
void _process(int *status_fork, char *valuePath, char **arguments, char **env)
{
	pid_t child_process;

	child_process = fork();
	if (child_process == -1)
	{
		perror("Error");
		exit(1);
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
		wait(status_fork);
	}
}
