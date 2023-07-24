#include "main.h"

/**
 * get_width - calculates the width for printing
 * format: pointer to formatted string in which to write the arguments
 * @i: pointer to an int which will be updated in the funcction
 * @args: list of arguments
 *
 * Return: width
 */

int get_width(const char *format, int *i, va_list args)
{
	int curr_pos;
	int width = 0;

	for (curr_pos = *i + 1; format[curr_pos] != '\0'; curr_pos++)
	{
		if (is_num(format[curr_pos]))
		{
			width *= 10;
			width += format[curr_pos] - '0';
		}
		else if (width == '*')
		{
			curr_pos++;
			width = va_arg(args, int);
			break;
		}
		else
			break;

	}
	*i = curr_pos - 1;

	return (width);
}

