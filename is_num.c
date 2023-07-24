#include <stdio.h>
/**
 * in_num - checks whether the value input is a digit
 * @c: value to be checked
 *
 * Return: 0 if is digit else return -1
 */

int is_num(int c)
{
        if (c >= '0' && c <= '9')
        {
                return (0);
        }
        return (1);
}

