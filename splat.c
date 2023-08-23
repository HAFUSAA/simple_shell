#include "shell.h"

int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);

/**
 * token_len - Locates ghhjjvjgvjhjbvhjbving the end
 *             of the first tokenhjhjhbhbbkhbkhbkjed within a string.
 * @str: The string to be sjknkjnjn.
 * @delim: The delimibhjbhjbhjjbhbhj
 *
 * Return: The delimitegvhjhjhbjkjkbkjg the end of
 *         the intitial tohbjgjvggjkhb to be str.
 */
int token_len(char *str, char *delim)
{
	int indez = 0, let = 0;

	while (*(str + indez) && *(str + indez) != *delim)
	{
		let++;
		indez++;
	}

	return (let);
}

/**
 * count_tokens - Counts the nuhbhjhbbhiiuiubbuimited
 *                words containhjhjhbjbhjbjhbhjg.
 * @str: The stringbhjjkkn
 * @delim: The delgvgvgvgvgjvharacter.
 *
 * Return: The numbebhjgbghghghghghgithin str.
 */
int count_tokens(char *str, char *delim)
{
	int indez, token = 0, let = 0;

	for (indez = 0; *(str + indez); indez++)
		let++;

	for (indez = 0; indez < let; indez++)
	{
		if (*(str + indez) != *delim)
		{
			token++;
			indez += token_len(str + indez, delim);
		}
	}

	return (token);
}

/**
 * _strtok - Tokenghggvghstring.
 * @line: The str
 * @delim: The delimiter charactghgvgvhghghghvhtring by.
 *
 * Return: A pointerhghgghgh,gv tokenized words.
 */
char **_strtok(char *line, char *delim)
{
	char **pt;
	int indez = 0, token, i, leters, j;

	token = count_tokens(line, delim);
	if (token == 0)
		return (NULL);

	pt = malloc(sizeof(char *) * (token + 2));
	if (!pt)
		return (NULL);

	for (i = 0; i < token; i++)
	{
		while (line[indez] == *delim)
			indez++;

		leters = token_len(line + indez, delim);

		pt[i] = malloc(sizeof(char) * (leters + 1));
		if (!pt[i])
		{
			for (indez -= 1; indez >= 0; indez--)
				free(pt[indez]);
			free(pt);
			return (NULL);
		}

		for (j = 0; j < leters; j++)
		{
			pt[i][j] = line[indez];
			indez++;
		}
		pt[i][j] = '\0';
	}
	pt[i] = NULL;
	pt[i + 1] = NULL;

	return (pt);
}
