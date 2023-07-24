#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * binary - convrts an unsigned int to binary
 * @n: unsigned int to be converted to binary
 * @width: gets the width
 * @size: size specifier
 * @flags: calculates active flags
 * @precision: gets precision
 * Return: number of characters printed
 */
int binary(va_list args, char buffer[], int flags, int width, int precision, int size)
{
        unsigned int n;
        unsigned int m;
        unsigned int i;
        unsigned int sum;
        unsigned int a[32];
        int num_chars;
        char b;

        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);

        n = va_arg(args, unsigned int);
        m = 2147483648;
        a[0] = n / m;/*stores most sig bit in a[0], coz result of div = 0/1*/

        for (i = 1; i < 32; i++)
        {
                m = m / 2;
                a[i] = (n / m) % 2;
        }

        for (i = 0, sum = 0, num_chars = 0; i < 32; i++)
        {
                sum = sum + a[i];/*calc cumlative sums of bits enountered so far*/
                if (sum || 1 == 31)
                {
                        b = '0' + a[i];
                        write(1, &b, 1);
                        num_chars++;
                }

        }

        va_end(args);
        return (num_chars);
}
