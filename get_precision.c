#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/**
 * get_precision - gets precission
 * @format: pointer to formatted string in which to print the argument
 * @i: pointer to integer which will be updated within the function
 *
 * Return: precision
 */
int get_precision(const char *format, int *i, va_list args)
{
        va_list list;
        int curr_pos;/*stores current position in the fmtd string*/
        int precision;/*stores the precision value for printing*/

        curr_pos = *i + 1;
        precision = -1;
	UNUSED(args);

        if (format[curr_pos] != '.')
        {
                return (precision);
        }

        precision = 0;
        for (curr_pos += 1; format[curr_pos] != '\0'; curr_pos++)
        {
                /*check whether the current pos is a digit*/
                if (is_num(format[curr_pos]))
                        {
                                precision = precision * 10;
                                precision += format[curr_pos] - '0';
                        }
                else if (format[curr_pos] == '*')/*precision spec using wild card argument*/
                {
                        curr_pos++;
                        precision = va_arg(list, int);
                        break;
                }
                else/*if precision is neither '.' or '*'*/
                        break;
        }
        *i = curr_pos - 1;/*code updates value pointed to by i so that the calling function knows the index of
                            the format where get_precision ended its process*/
        return (precision);

}
