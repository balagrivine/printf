#include "main.h"

/**
 * print_pointer - prints value of pointer variable
 * @args: list of arguments to be printed
 * @buffer: an array of characters
 * @width: gets the width
 * @size: size specifier
 * @flags: calculates active flags
 * @precision: gets precision;
 * Return: number of characters printed
 */

int print_pointer(va_list args, char buffer[], int width, int size, int flags, int precision)
{
        int num_chars = 0;
        unsigned long int num;
        int i = BUFF_SIZE - 2;
        int length = 2;
        void *address;
        char map_hex[] = "0123456789abcdef";

	UNUSED(width);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(precision);

        address = va_arg(args, void *);

        buffer[BUFF_SIZE - 1] = '\0';
        num = (unsigned long int)address;

        while (num > 0)
        {
                buffer[i--] = map_hex[num % 16];
                num /= 16;
                length++;
                num_chars++;
        }
        i++;
        return (num_chars);
}
