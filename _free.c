#include "simple_shell.h"

void frees(char *prompt, char **arguments)
{

	(void)arguments;

	free(prompt);

/*	while(arguments[cnt] != NULL)
	{
		free(arguments[cnt]);
	}

	free(arguments);*/
}
