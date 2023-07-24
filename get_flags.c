#include "main.h"

/**
 * get_flafs - calculates active flags
 * @format: pointer to a formatted string in which to print the arguments
 * @i: pointer to an integer that will be updated within the function
 *
 * Return: flags
 */

int get_flags(char *format, int *i)
{
        int curr_pos;
        int flags = 0;
        int j;
        char FLAGS_REP[] = {'-', '+', '0', '#', ' ', '\0'};
        int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE};

        for (curr_pos = *i + 1; format[curr_pos] != '\0'; curr_pos++)
        {
                for (j = 0; FLAGS_REP[j]; j++)
                {
                        if (format[curr_pos] == FLAGS_REP[j])
                        {
                                flags |= FLAGS_ARR[j];
                                break;
                        }

                        if (FLAGS_REP[j] == 0)
                        {
                                break;
                        }
                }
        }
        *i = curr_pos - 1;
        return (flags);
}
