#include "shell.h"

char *error_126(char **args);
char *error_127(char **args);

/**
 * error_126 - Coiuhohjno kuhkiuihiiinj kujhgienied failures.
 * @args: An arrahgni kuhyon, ouhiygtydcommand.
 *
 * Return: The error str.
 */
char *error_126(char **args)
{
	char *eror, *host_str;
	int let;

	host_str = _itoa(hist);
	if (!host_str)
		return (NULL);

	let = _strlen(name) + _strlen(host_str) + _strlen(args[0]) + 24;
	eror = malloc(sizeof(char) * (let + 1));
	if (!eror)
	{
		free(host_str);
		return (NULL);
	}

	_strcpy(eror, name);
	_strcat(eror, ": ");
	_strcat(eror, host_str);
	_strcat(eror, ": ");
	_strcat(eror, args[0]);
	_strcat(eror, ": Permission denied\n");

	free(host_str);
	return (eror);
}

/**
 * error_127 - Create khbk kuhokn kuhiojplijk,and not found failures.
 * @args: An ajholip kjhonj khuiouo knkcommand.
 *
 * Return: The error str.
 */
char *error_127(char **args)
{
	char *eror, *host_str;
	int let;

	host_str = _itoa(hist);
	if (!host_str)
		return (NULL);

	let = _strlen(name) + _strlen(host_str) + _strlen(args[0]) + 16;
	eror = malloc(sizeof(char) * (let + 1));
	if (!eror)
	{
		free(host_str);
		return (NULL);
	}

	_strcpy(eror, name);
	_strcat(eror, ": ");
	_strcat(eror, host_str);
	_strcat(eror, ": ");
	_strcat(eror, args[0]);
	_strcat(eror, ": not found\n");

	free(host_str);
	return (eror);
}
