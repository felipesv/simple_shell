#include "simple_shell.h"
/**
 * buildPath - build a valid path
 * @argum: argumens
 * @fileName: executable file name
 * @env: enviroment variables
 *
 * Return: pointer
 */
char *buildPath(char **argum, char *fileName, char **env)
{
	char *path_val = NULL, *pathEnv = NULL, **cpyEnv = copyEnv(env);
	struct stat stat_var;

	if (!stat(argum[0], &stat_var))
	{
		if ((argum[0][0] == '/') ||
		     (argum[0][0] == '.' && argum[0][1] == '/') ||
		     (argum[0][0] == '.' && argum[0][1] == '.'))
		{
			pathEnv = malloc(sizeof(char) * lengthArray(argum[0]) + 1);
			if (pathEnv == NULL)
				perror("Error");
			_strcpy(pathEnv, argum[0]);
			pathEnv[lengthArray(argum[0])] = '\0';
			freeDoublePointer(cpyEnv);
			return (pathEnv);
		}
	}

	path_val = get_env_value("PATH", cpyEnv);
	pathEnv = env_split(path_val, argum[0], fileName);

	freeDoublePointer(cpyEnv);

	return (pathEnv);
}
