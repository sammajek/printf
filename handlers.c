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
