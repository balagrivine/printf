#include "main.h"
#include <stdarg.h>

/**
 * print_unsigned - prints an unsigned integer
 * @num: number to be printed as an unsigned int
 *@size: size specifier
 *
 * Return: num of chars printed
 */

int print_unsigned(va_list args, char buffer[], int size)
{

        unsigned long int num = va_arg(args, unsigned long int);
        int num_chars = 0;
        int i;

        i = BUFF_SIZE - 2;

        num = convert_unsigned(num, size);

        if (num == 0)
        {
                buffer[i--] = '0';
        }
        buffer[BUFF_SIZE] = '\0';

        while (num > 0)
        {
                buffer[i--] = '0' + num % 10;
                num /= 10;
                num_chars++;
        }
        i++;

        return (num_chars);
}
