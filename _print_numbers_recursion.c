#include "simple_shell.h"
/**
 * _print_numbers_recursion - print a number
 * @number: number to print
 *
 * Return: count
 */
int _print_numbers_recursion(int number)
{
	int new_number = number / 10;
	int prt_number = number % 10;
	int cnt = 0;

	if (new_number != 0)
	{
		cnt += _print_numbers_recursion(new_number);
		cnt++;
		_putchar('0' + prt_number);
	}
	else
	{
		cnt++;
		_putchar('0' + number);
	}

	return (cnt);
}
