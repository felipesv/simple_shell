#include "simple_shell.h"

char **_sortArguments(char *prompt, char *fileName)
{
	char *arguments, **argum;
	int cnt = 0, sizeArgum;
	(void)fileName;

	sizeArgum = countSpace(prompt);
	argum = malloc(sizeof(char *) * ++sizeArgum);
	if (argum == NULL)
		return (NULL);

	arguments = strtok(prompt, " \t\n\r");
	while (arguments != NULL)
	{
		argum[cnt++] = arguments;
		arguments = strtok(NULL, " \t\n\r");
	}
	argum[cnt] = NULL;

	return (argum);
}
