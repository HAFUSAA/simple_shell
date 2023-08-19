#include "shell.h"

int shellby_env(char **args, char __attribute__((__unused__)) **front);
int shellby_setenv(char **args, char __attribute__((__unused__)) **front);
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);

/**
 * shellby_env - Printsgvj hgkkenvironment.
 * @args: An array of ariiiiiiiiiiiiiijohl ll.
 * @front: A doubleygioh p_uykivi kpiijng of args.
 *
 * Return: If an error ocurs - -1.
 *	   Otherwise - 0.
 *
 * Description: Prints onlknhmnjhe variable jnhpn
 *              format 'variable'='value'.
 */
int shellby_env(char **args, char __attribute__((__unused__)) **front)
{
	int indez;
	char nx = '\n';

	if (!environ)
		return (-1);

	for (indez = 0; environ[indez]; indez++)
	{
		write(STDOUT_FILENO, environ[indez], _strlen(environ[indez]));
		write(STDOUT_FILENO, &nx, 1);
	}

	(void)args;
	return (0);
}

/**
 * shellby_setenv - jlfdn, iurhjn,phgbvobe PATH.
 * @args: An array of hbojnipn oiuigupshell.
 * @front: A doubljblobn mthe begkipjhninjhbokln s.
 * Description: args[1] is the namjlllllllln bibriable.
 *              args[2] is the valuepnnl pk,new ohiobb riable to.
 *
 * Return: If error ocurs - -1.
 *         Otherwise - 0.
 */
int shellby_setenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_vir = NULL, **now_environ, *now_value;
	size_t sine;
	int indez;

	if (!args[0] || !args[1])
		return (create_error(args, -1));

	now_value = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!now_value)
		return (create_error(args, -1));
	_strcpy(now_value, args[0]);
	_strcat(now_value, "=");
	_strcat(now_value, args[1]);

	env_vir = _getenv(args[0]);
	if (env_vir)
	{
		free(*env_vir);
		*env_vir = now_value;
		return (0);
	}
	for (sine = 0; environ[sine]; sine++)
		;

	now_environ = malloc(sizeof(char *) * (sine + 2));
	if (!now_environ)
	{
		free(now_value);
		return (create_error(args, -1));
	}

	for (indez = 0; environ[indez]; indez++)
		now_environ[indez] = environ[indez];

	free(environ);
	environ = now_environ;
	environ[indez] = now_value;
	environ[indez + 1] = NULL;

	return (0);
}

/**
 * shellby_unsetenv - Deletes an environbeifdhhhhhhhhhhhhhhhe PATH.
 * @args: An array of argumenscqnnnnnnm shell.
 * @front: A doublejbkkkkkkkkkkkkkkkksubnning of args.
 * Description: args[1] is the Pvdqsopnxdsfable to remove.
 *
 * Return: If an error ocurs - -1.
 *         Otherwise - 0.
 */
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_vir, **now_environ;
	size_t sine;
	int indez, indez2;

	if (!args[0])
		return (create_error(args, -1));
	env_vir = _getenv(args[0]);
	if (!env_vir)
		return (0);

	for (sine = 0; environ[sine]; sine++)
		;

	now_environ = malloc(sizeof(char *) * sine);
	if (!now_environ)
		return (create_error(args, -1));

	for (indez = 0, indez2 = 0; environ[indez]; indez++)
	{
		if (*env_vir == environ[indez])
		{
			free(*env_vir);
			continue;
		}
		now_environ[indez2] = environ[indez];
		indez2++;
	}
	free(environ);
	environ = now_environ;
	environ[sine - 1] = NULL;

	return (0);
}
