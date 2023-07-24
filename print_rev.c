#include "main.h"

/**
 * print_reverse - prints a string in reverse
 * @args: list of arguments to be printed
 * @buffer: buffer array to handle print
 * @width: gets the width
 * @size: size specifier
 * @flags: calculates active flags
 * @precision: gets precision
 *
 * Return: number of characters printed
 */

int print_reverse(va_list args, char buffer[],
		int size, int width, int flags, int precision)
{
	char *string;
	int i;
	char j;
	int num_chars = 0;

	string = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(flags);

	if (string == NULL)
	{
		string = "(NULL)";
	}

	for (i = 0; string[i]; i++)
	{
		for (i = i - 1; i >= 0; i--)
		{
			j = string[i];
			write(1, &j, 1);
			num_chars++;
		}
	}
	return (num_chars);
}
