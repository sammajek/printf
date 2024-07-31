#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Character string composed of zero or more directives.
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	int (*func)(va_list);

	if (!format)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);

			func = get_func(format[i]);
			if (func != NULL)
				count += func(args);
			else
			{
				write(1, &format[i - 1], 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}

/**
 * get_func - Selects the correct function to perform the operation.
 * @c: The conversion specifier passed as argument.
 * Return: A pointer to the function that corresponds to the specifier.
 */
int (*get_func(char c))(va_list)
{
	if (c == 'c')
		return (handle_char);
	else if (c == 's')
		return (handle_string);
	else if (c == '%')
		return (handle_percent);
	else if (c == 'd' || c == 'i')
		return (handle_int);
	else
		return (NULL);
}
