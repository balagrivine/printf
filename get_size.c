#include "main.h"

/**
 * get_size - claulates the size to cast the argument
 * @format: pointer to formatted string in which to print the argument
 * @i: pointer to an int which will be updated within the function
 *
 * Return: size
 */

int get_size(const char *format, int *i)
{
        int curr_pos = *i + 1;
        int size = 0;

        if (format[curr_pos] == 'l')
        {
                size = S_LONG;
        }

        else if (format[curr_pos] == 'h')
        {
                size = S_SHORT;
        }
        if (size == 0)
        {
                *i = curr_pos - 1;
        }
        else
                *i = curr_pos;
        return (size);
}
