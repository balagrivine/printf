#include <stdio.h>
#include "main.h"

/**
 * print_int - prints integer
 * @value: number to be printed
 *
 * Retrn: number of char printed
 */

int print_int(int value)
{
        int num_chars = 0;
        int i, j;
        char buffer[32];/*an array of strings that stores the string rep of the integer*/

        if (value < 0)
        {
                _putchar('-');
                value = -value;
                num_chars++;
        }

        i = 0;
        while (value > 0)
        {
                buffer[i++] = '0' + (value % 10);
                value /= 10;
                num_chars++;
        }

        for (j = (i - 1); j >= 0; j--)
        {
                _putchar(buffer[j]);
                num_chars++;
        }
        return (num_chars);


}
