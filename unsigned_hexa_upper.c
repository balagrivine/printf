#include "main.h"

/**
 * unsigned_hexa_upper - prints an unsigned number in upper case hexadecimal
 * buffer: an array of strings
 * @args: list of arguments to be printed
 * @width: gets the width
 * @size: size specifier
 * @flags: calculates active flags
 * @precision: gets precision
 * Return: numebr of characters printed
 */

int unsigned_hexa_upper(va_list args, char buffer[], int width, int flags, int precision, int size)
{
        int i = BUFF_SIZE - 2;
        int j;
        unsigned long int num = va_arg(args, int);
        int num_chars;
        char map_hex[] = {"123456789ABCDEF"};
        num = convert_unsigned(num, size);

	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);

        if (num == 0)
        {
                buffer[i--] = '0';
        }
        buffer[BUFF_SIZE - 1] = '\0';

        num_chars = 0;
        while (num > 0)
        {
                buffer[i++] = map_hex[num % 16];
                num /= 16;
                num_chars++;

        }
        i++;

        for (j = i - 1; j >= 0; j--)
        {
                _putchar(buffer[j]);
                num_chars++;

        }
        return (num_chars);
}
