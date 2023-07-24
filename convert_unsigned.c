#include "main.h"

/**
 * convert_unsigned - casts a number to a specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 *
 * Return: the cast number
 */

long int convert_unsigned(long unsigned int num, int size)
{
        if (size == S_LONG)
        {
                return (num);
        }
        else if (size == S_SHORT)
        {
                return ((unsigned short)num);
        }
        return ((unsigned int)num);

}
