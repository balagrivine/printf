#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
 * _printf - a function that produces output according to a format
 * @format: character string to be printed as output
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
        va_list args;

        int num_chars = 0;
        char c;
        char *string;
        int num;
        int buff_ind = 0;
        char buffer[BUFF_SIZE];
        int printed = 0;/*no of chars printed by each conversio specifier*/

        va_start(args, format);

        while (*format)
        {
                if (*format == '%')
                {
                        format++;
                        if (*format == 'c')
                        {
                                c = va_arg(args, int);
                                buffer[buff_ind++] = c;
                                if (buff_ind == BUFF_SIZE)
                                {
                                        print_buffer(buffer, &buff_ind);
                                        num_chars += buff_ind;
                                }
                        }
                        else if (*format == 's')
                        {
                                string = va_arg(args, char*);
                                while (*string)
                                {
                                        buffer[buff_ind++] = *string;
                                        string++;
                                        if (buff_ind == BUFF_SIZE)
                                        {

                                                print_buffer(buffer, &buff_ind);
                                                num_chars += buff_ind;
                                        }
                                }
                                        /*_putchar(string);*/
                        }
                        else if (*format == '%')
                        {
                                /*pcnt = va_arg(args, int);*/
                                buffer[buff_ind++] = '%';
                                if (buff_ind == BUFF_SIZE)
                                {
                                        print_buffer(buffer, &buff_ind);
                                        num_chars += buff_ind;
                                }
                        }
                        else if (*format == 'd' || *format == 'i')
                        {
                                num = va_arg(args, int);
                                printed = print_int(num);
                                num_chars += printed;
                        }

                }
                else
                {
                        buffer[buff_ind++] = *format;
                        if (buff_ind == BUFF_SIZE)
                        {
                                print_buffer(buffer, &buff_ind);
                                num_chars += buff_ind;
                        }
                        /*num_chars++;*/
                }
                format++;
        }
        print_buffer(buffer, &buff_ind);
        num_chars += buff_ind;

        va_end(args);
        return (num_chars);
}
