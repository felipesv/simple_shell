#include "simple_shell.h"
/**
 * get_env_value - get value from enviroment variable
 * @nameVar: name var
 * @env: enviroment variables
 *
 * Return: return **pointer
 */
char *get_env_value(char *nameVar, char **env)
{
	int cnt = 0;
	char *arguments;

	arguments = strtok(env[cnt], "=");

	while (env[cnt])
	{
		if (_strcmp(arguments, nameVar) == 0)
		{
			arguments = strtok(NULL, "\n");
			return (arguments);
		}

		cnt++;
		arguments = strtok(env[cnt], "=");
	}

	return (NULL);
}
