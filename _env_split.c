#include "simple_shell.h"

char *env_split(char *path_value, char *command, char *fileName)
{
	int lenCommand = 0, lenPath = 0, _mallocsize;
	char *valuePath = strtok(path_value, ":"), *pathDir;
	struct stat stat_var;

	lenCommand = lengthArray(command);
	lenPath = lengthArray(valuePath);
	_mallocsize = lenCommand + lenPath + 1;

	while (valuePath != NULL)
	{
		pathDir = malloc(sizeof(char) * (_mallocsize));
		if (pathDir == NULL)
			perror(fileName);

		_strcat(pathDir, valuePath);
		_strcat(pathDir, "/");
		_strcat(pathDir, command);
		*(pathDir + _mallocsize) = '\0';

		if (stat(pathDir, &stat_var) == 0)
			return (pathDir);

		free(pathDir);

		valuePath = strtok(NULL, ":");
	}

	return (NULL);
}
