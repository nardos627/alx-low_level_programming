#include <stdarg.h> /* va_* */
#include <stdio.h> /* printf */
#include "variadic_functions.h"

/**
 * print_strings - print varying amount of string
 * @seperator: delimiter
 * @n: amount of arguments in list
 */
void print_strings(const char *seperator, const unsigned int n, ...)
{
	va_list valist;
	unsigned int i;
	char *s;

	if (n > 0)
	{
		va_start(valist, n);
		for (i = 1; i <= n; i++)
		{
			s = va_arg(valist, char *);
			if (s == NULL)
				printf("(nil)");
			else
				printf("%s", s);

			if (i != n && seperator != NULL)
				printf("%s", seperator);
		}
		va_end(valist);
	}
	printf("\n");
}
