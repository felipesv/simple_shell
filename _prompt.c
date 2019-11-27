#include "simple_shell.h"

char *_prompt(int isattyStatus)
{
	char *get_prompt;
	int len;
	size_t size_buffer = 0;

	if (isattyStatus)
		write(STDOUT_FILENO, "$ ", 2);

	len = getline(&get_prompt, &size_buffer, stdin);
	if (len == -1)
	{
		free(get_prompt);
		if(isattyStatus)
			_putchar('\n');
		return (NULL);
	}
	*(get_prompt + (--len)) = '\0';

	return (get_prompt);

}
