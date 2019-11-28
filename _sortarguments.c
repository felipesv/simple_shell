#include "simple_shell.h"
/**
 * _sortArguments - execute all the commands
 * @prompt: prompt
 * @fileName: executable file name
 *
 * Return: pointer
 */
char **_sortArguments(char *prompt, char *fileName)
{
	char *arguments, **argum;
	int cnt = 0, sizeArgum;
	(void)fileName;

	sizeArgum = countSpace(prompt);
	argum = malloc(sizeof(char *) * ++sizeArgum);
	if (argum == NULL)
		perror("Error");

	arguments = strtok(prompt, " \t\n\r");
	while (arguments != NULL)
	{
		argum[cnt] = malloc(sizeof(char) * (lengthArray(arguments) + 1));
		_strcpy(argum[cnt], arguments);
		arguments = strtok(NULL, " \t\n\r");
		cnt++;
	}
/*	free(arguments);*/
	argum[cnt] = NULL;

	return (argum);
}
