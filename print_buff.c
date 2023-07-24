#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/**
 * print_buffer - prints
 * @buffer: an array of strings that hold characters to be printed
 * @buff_index: pointer to an integer that is used to keep track of current index in buffer array
 *
 * Return: nothing
 */

void print_buffer(char buffer[], int *buff_index)
{
        int i;

        if (*buff_index > 0)
        {
                for (i = 0; i < *buff_index; i++)
                {
                                _putchar(buffer[i]);
                }

        }
        *buff_index = 0;
}
