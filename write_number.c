#include "main.h"

/**
 * write_number - Prints a number with optional formatting
 * @is_negative: Flag indicating whether the number is negative.
 * @ind: Current index in the buffer where the number starts.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[],
                 int flags, int width, int precision, int size)
{
    int length = BUFF_SIZE - ind - 1;
    char padd = ' ', extra_ch = 0;
    UNUSED(size);

    if ((flags & F_ZERO) && !(flags & F_MINUS))
        padd = '0';


    if (is_negative)
        extra_ch = '-';
    else if (flags & F_PLUS)
        extra_ch = '+';
    else if (flags & F_SPACE)
        extra_ch = ' ';


    return write_num(ind, buffer, flags, width, precision,
                     length, padd, extra_ch);
}
