#include "simple_shell.h"
/**
 * _prompt - get the prompt
 * @isattyStatus: issaty status
 *
 * Return: prompt
 */
char *_prompt(int isattyStatus)
{
	char *get_prompt = NULL;
	int len = 0;
	size_t size_buffer = 0;

	do {
		if (isattyStatus)
			write(STDOUT_FILENO, "$ ", 2);

		len = getline(&get_prompt, &size_buffer, stdin);
		exitValidation(get_prompt);
		if (len == -1)
		{
			free(get_prompt);
			if (isattyStatus)
				_putchar('\n');
			return (NULL);
		}
	} while (len == 1);
	*(get_prompt + (--len)) = '\0';

	return (get_prompt);

}
