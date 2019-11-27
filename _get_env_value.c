#include "simple_shell.h"

char *get_env_value(char *nameVar, char **env)
{
	int cnt = 0;
	char *arguments, **cpyEnv = copyEnv(env);

	arguments = strtok(cpyEnv[cnt], "=");

	while (env[cnt])
	{
		if (_strcmp(arguments, nameVar) == 0)
		{
			arguments = strtok(NULL, "\n");
			return (arguments);
		}

		cnt++;
		arguments = strtok(cpyEnv[cnt], "=");
	}

	return (NULL);
}
