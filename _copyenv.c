#include "simple_shell.h"
/**
 * copyEnv - create a copy from env
 * @env: enviroments variables
 *
 * Return: return **pointer
 */
char **copyEnv(char **env)
{
	int cntArg = countArguments(env);
	int cnt = 0, cntDinamyc = 0;
	char **cpyEnv = malloc(sizeof(char *) * (cntArg + 1));

	if (cpyEnv == NULL)
		perror("Error");

	while (env[cnt] != NULL)
	{
		cntDinamyc = lengthArray(env[cnt]);
		cpyEnv[cnt] = malloc(sizeof(char) * (cntDinamyc + 1));

		if (cpyEnv[cnt] == NULL)
		{
			cnt--;
			while (cnt >= 0)
			{
				free(cpyEnv[cnt]);
			}
			free(cpyEnv);
			perror("Error");
		}


		_strcpy(cpyEnv[cnt], env[cnt]);
		cnt++;
	}

	cpyEnv[cnt] = NULL;

	return (cpyEnv);
}
