#include <stdio.h>
#include "main.h"

/**
 * print_num - prints integer
 * @args: list of arguments to be printed
 * @buffer: an array of characters
 * @flags: calculates active flags
 * @width: gets the width
 * precision: gets precision
 * @size: size specifier
 *
 * Retrn: number of char printed
 */

int print_num(va_list args, char buffer[], int flags, int width, int precision, int size)
{
        int num_chars = 0;
        int i = BUFF_SIZE - 2;
        int is_negative = 0;
        long int value = va_arg(args, long int);
        unsigned long int num;

        value = convert_size(value, size);

        if (value < 0)
        {
                num = (unsigned long int)((-1) * value);
                is_negative = 1;
                num_chars++;
        }
        if (value == 0)
                buffer[i--] = '0';
        buffer[BUFF_SIZE - 1] = '\0';
        num = (unsigned long int)value;

        i = 0;
        while (num > 0)
        {
                buffer[i--] = '0' + (num % 10);
                num /= 10;
                num_chars++;
        }
        i++;

        return (write_number(is_negative, i, buffer, flags, width, precision, size));

}
