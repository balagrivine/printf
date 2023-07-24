#include "main.h"

/**
 * rot_string - rotates a string 13 times
 * @buffer: buffer array to ahndle print
 * @args: list of arguments to be printed
 * @width: gets the width
 * @size: size specifier
 * @flags: calculates active flags
 * @precision: gets precision
 *
 * Return: number of characters printed
 */

int rot_string(va_list args, char buffer[], int flags, int width, int precision, int size)
{
        unsigned int i, j;
        char norm[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyxabcdetghijklm";
        char *string;
        char x;
        int num_chars;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);


        string = va_arg(args, char *);

        if (string == NULL)
                string = "(NULL)";

        for (i = 0; string[i]; i++)
        {
                for (j = 0; norm[j]; j++)
                {
                        if (string[i] == norm[j])
                        {
                                x = rot[j];
                                write(1, &x, 1);
                                num_chars++;
                                break;
                        }

                        if (!norm[j])
                        {
                                x = string[i];
                                write(1, &x, 1);
                                num_chars++;
                        }
                }
        }
        return (num_chars);

}
