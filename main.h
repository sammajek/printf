#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int (*get_func(char c))(va_list);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(va_list args);
int handle_int(va_list args);
void itoa(int value, char *str, int base);
void reverse(char *str);

#endif /* MAIN_H */
