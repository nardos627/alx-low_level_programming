#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count the words from.
 *
 * Return: The number of words in @str.
 */
static int count_words(char *str)
{
	int count = 0, index = 0;

	while (str[index])
	{
		if (str[index] != ' ' &&
			(str[index + 1] == ' ' || !str[index + 1]))
			count++;
		index++;
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: If str is NULL or empty - NULL.
 *         Otherwise - a pointer to the array of words.
 */
char **strtow(char *str)
{
	char **words;
	int index = 0, w, len, word_count;

	if (!str || !*str)
		return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);

	while (index < word_count)
	{
		while (*str == ' ')
			str++;
		len = 0;
		while (*(str + len) != ' ' && *(str + len))
			len++;
		words[index] = malloc(sizeof(char) * (len + 1));
		if (!words[index])
		{
			while (--index >= 0)
				free(words[index]);
			free(words);
			return (NULL);
		}
		for (w = 0; w < len; w++)
			words[index][w] = *(str++);
		words[index][w] = '\0';
		index++;
	}
	words[index] = NULL;

	return (words);
}
