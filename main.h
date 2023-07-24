#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(X) (void)(X)
#define BUFF_SIZE 1024

#define S_LONG 2
#define S_SHORT 1

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

int get_size(const char *format, int *i);
int get_precision(const char *format, int *i, va_list args);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int _putchar(char c);
int _printf(const char *format, ...);
int binary(va_list args, char buffer[], int flags, int width, int precission, int size);
int print_int(int value);
void print_buffer(char buffer[], int *buff_ind);
int is_num(int c);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
long int convert_unsigned(long unsigned int num, int size);
int write_unsgnd(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_num(va_list args, char buffer[], int flags, int width, int precision, int size);
long int convert_size(long int num, int size);
int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);
int write_num(int ind, char buffer[], int flags, int width, int prec, int length, char padd, char extra_c);
int unsigned_octal(va_list args, char buffer[], int size, int flags, int precision, int width);
int unsigned_hexa_lower(va_list args, char buffer[], int width, int flags, int precision, int size);
int unsigned_hexa_upper(va_list args, char buffer[], int width, int flags, int precision, int size);
int print_reverse(va_list args, char buffer[], int size, int width, int flags, int precision);
int get_width(const char *format, int *i, va_list args);
int get_flags(const char *format, int *i);
int rot_string(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_pointer(va_list args, char buffer[], int width, int size, int flags, int precision);

/**
 * struct fmt - represents format spec and associated function
 * @fmt: a character representimg the format specified
 * @fctn: function pointer that corressponds to the associated print function
 */
struct fmt{
        char fmt;
        int (*fctn)(va_list, char[], int, int, int, int);
};
/**
* typedef struct fmt fmt_t - reps format spec and associated functions
* @fmt: character representing the format specified
* @fm_t: new defined typedef data type
*/
typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
#endif
