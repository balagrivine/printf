#include "main.h"

/**
 * unsigned_octal - prints unsigned int in octal notation
 * @format: pointer to formatted string in which to print the output
 * @args: list of arguments to be printed
 * @width: gets the width
 * @size: size specifier
 * @flags: calculates active flags
 * @precision: gets precision
 *
 * Return: number of chars printed
 */

int unsigned_octal(va_list args, char buffer[], int size, int flags, int precision, int width)
{
        int i = BUFF_SIZE - 2;
        int j;
        unsigned long int num = va_arg(args, int);
        int num_chars = 0;
	unsigned long int int_num = num;
        num = convert_unsigned(num, size);

	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);

        if (num == 0)
        {
                buffer[i--] = '0';
        }
        buffer[BUFF_SIZE - 1] = '\0';

        while (num > 0)
        {
                buffer[i++] = '0' + (num % 8);
                num = num / 8;
                num_chars++;
        }
        i++;

        for (j = i - 1; j >= 0; j--)
        {
                _putchar(buffer[j]);
                num_chars++;
        }

	if (flags & F_HASH && int_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(args, buffer, flags, width, precision, size));
}
