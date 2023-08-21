#include "shell.h"

char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
/**
 * error_env - Createsyg hkhgdhdghfjh , hvkbln s.
 * @args: An array ghjbk kugohn kjholkommand.
 *
 * Return: The error str.
 */
char *error_env(char **args)
{
	char *eror, *host_str;
	int let;

	host_str = _itoa(hist);
	if (!host_str)
		return (NULL);

	args--;
	let = _strlen(name) + _strlen(host_str) + _strlen(args[0]) + 45;
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
	_strcat(eror, ": Unable to add/remove from environment\n");

	free(host_str);
	return (eror);
}

/**
 * error_1 - Creates an erk,jbh kyukn jygtkibkuors.
 * @args: An array kgiknh kkkkknloy jknouommand.
 *
 * Return: The error str.
 */
char *error_1(char **args)
{
	char *eror;
	int let;

	let = _strlen(name) + _strlen(args[0]) + 13;
	eror = malloc(sizeof(char) * (let + 1));
	if (!eror)
		return (NULL);

	_strcpy(eror, "alias: ");
	_strcat(eror, args[0]);
	_strcat(eror, " not found\n");

	return (eror);
}

/**
 * error_2_exit - Creatkhujn kuhyhntfjhb  hvjgfb it errors.
 * @args: An array of argugjh gkjbkunjgfk ghmand.
 *
 * Return: The error str.
 */
char *error_2_exit(char **args)
{
	char *eror, *host_str;
	int let;

	host_str = _itoa(hist);
	if (!host_str)
		return (NULL);

	let = _strlen(name) + _strlen(host_str) + _strlen(args[0]) + 27;
	eror = malloc(sizeof(char) * (let + 1));
	if (!eror)
	{
		free(host_str);
		return (NULL);
	}

	_strcpy(eror, name);
	_strcat(eror, ": ");
	_strcat(eror, host_str);
	_strcat(eror, ": exit: Illegal number: ");
	_strcat(eror, args[0]);
	_strcat(eror, "\n");

	free(host_str);
	return (eror);
}

/**
 * error_2_cd - Creates an errokjjhpmok^kihkliupoucd errors.
 * @args: An array of arliui uyojmp uykjnml and.
 *
 * Return: The error str.
 */
char *error_2_cd(char **args)
{
	char *eror, *host_str;
	int let;

	host_str = _itoa(hist);
	if (!host_str)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
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
	if (args[0][0] == '-')
		_strcat(eror, ": cd: Illegal option ");
	else
		_strcat(eror, ": cd: can't cd to ");
	_strcat(eror, args[0]);
	_strcat(eror, "\n");

	free(host_str);
	return (eror);
}

/**
 * error_2_syntax - Crealkhj, lijmk,m:lom;r syntax errors.
 * @args: An array of argumenthlol lo_uiunjmlthe command.
 *
 * Return: The error str.
 */
char *error_2_syntax(char **args)
{
	char *eror, *host_str;
	int let;

	host_str = _itoa(hist);
	if (!host_str)
		return (NULL);

	let = _strlen(name) + _strlen(host_str) + _strlen(args[0]) + 33;
	eror = malloc(sizeof(char) * (let + 1));
	if (!eror)
	{
		free(host_str);
		return (NULL);
	}

	_strcpy(eror, name);
	_strcat(eror, ": ");
	_strcat(eror, host_str);
	_strcat(eror, ": Syntax error: \"");
	_strcat(eror, args[0]);
	_strcat(eror, "\" unexpected\n");

	free(host_str);
	return (eror);
}
