#include "main.h"

/**
 * handle_char - Handles the %c conversion specifier.
 * @args: The argument list.
 * Return: The number of characters printed.
 */
int handle_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);

	return (1);
}

/**
 * handle_string - Handles the %s conversion specifier.
 * @args: The argument list.
 * Return: The number of characters printed.
 */
int handle_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (!str)
		str = "(null)";

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/**
 * handle_percent - Handles the %% conversion specifier.
 * @args: The argument list (unused).
 * Return: The number of characters printed.
 */
int handle_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}


/**
 * handle_int - Handles the %d and %i conversion specifiers.
 * @args: The argument list.
 * Return: The number of characters printed.
 */
int handle_int(va_list args)
{
	int n = va_arg(args, int);
	char buffer[50];
	int i = 0, count = 0;

	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		count++;
	}

	itoa(n, buffer, 10);

	while (buffer[i])
	{
		write(1, &buffer[i], 1);
		i++;
		count++;
	}
	return (count);
}

/**
 * itoa - Converts an integer to a string.
 * @value: The integer to convert.
 * @str: The buffer to store the string.
 * @base: The base to convert to.
 */
void itoa(int value, char *str, int base)
{
	char *digits = "0123456789abcdef";
	int i = 0, sign = value;

	if (sign < 0)
		value = -value;

	do {
		str[i++] = digits[value % base];
		value /= base;
	} while (value);

	if (sign < 0)
		str[i++] = '-';

	str[i] = '\0';
	reverse(str);
}

/**
 * reverse - Reverses a string.
 * @str: The string to reverse.
 */
void reverse(char *str)
{
	int i, j;
	char temp;

	for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
