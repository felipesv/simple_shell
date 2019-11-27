#include "simple_shell.h"

char *buildPath(char **argum, char *fileName, char **env)
{
	char *path_val = NULL, *pathEnv = NULL, **cpyEnv = copyEnv(env);
	struct stat stat_var;

	if (!stat(argum[0], &stat_var))
	{
		if ( (argum[0][0] == '/') ||
		     (argum[0][0] == '.' && argum[0][1] == '/') ||
		     (argum[0][0] == '.' && argum[0][1] == '.'))
			return (argum[0]);
	}

	path_val = get_env_value("PATH", cpyEnv);
	pathEnv = env_split(path_val, argum[0], fileName);

	freeDoublePointer(cpyEnv);

	return (pathEnv);
}
