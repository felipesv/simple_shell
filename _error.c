#include "simple_shell.h"
/**
 * _error - error message
 * @status: status fail
 * @arguments: arguments to show
 * @fileName: executable file name
 *
 * Return: is a void
 */
void _error(int status, char **arguments, char *fileName)
{
	int cntArg = countArguments(arguments);

	write(STDERR_FILENO, fileName, lengthArray(fileName));
	write(STDERR_FILENO, ": ", 2);
	_print_numbers_recursion(cntArg);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, arguments[0], lengthArray(arguments[0]));
	write(STDERR_FILENO, ": ", 2);

	if (status == 127)
		write(STDERR_FILENO, "not found\n", 10);
	if (status == 126)
		write(STDERR_FILENO, "Permission denied\n", 18);
}
