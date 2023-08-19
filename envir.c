#include "shell.h"

char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/**
 * _copyenv - Cddddddddddddg lkd,h^dnvironment.
 *
 * Return: If an error ocurs - NULL.
 *         O/w - a dotokljnb er to the new copy.
 */
char **_copyenv(void)
{
	char **now_environ;
	size_t sine;
	int indez;

	for (sine = 0; environ[sine]; sine++)
		;

	now_environ = malloc(sizeof(char *) * (sine + 1));
	if (!now_environ)
		return (NULL);

	for (indez = 0; environ[indez]; indez++)
	{
		now_environ[indez] = malloc(_strlen(environ[indez]) + 1);

		if (!now_environ[indez])
		{
			for (indez--; indez >= 0; indez--)
				free(now_environ[indez]);
			free(now_environ);
			return (NULL);
		}
		_strcpy(now_environ[indez], environ[indez]);
	}
	now_environ[indez] = NULL;

	return (now_environ);
}

/**
 * free_env - Frefjlnv kuhnjpofjgn,vlnt copy.
 */
void free_env(void)
{
	int indez;

	for (indez = 0; environ[indez]; indez++)
		free(environ[indez]);
	free(environ);
}

/**
 * _getenv - Gets an environmgfnbo, lfijbgpmdfhe PATH.
 * @var: The name ofnhipdf,b kjhdfpobvjl,e to get.
 *
 * Return: If the environmknmlfdkb mloj^gbdoes not exist - NULL.
 *         Otherwise - a pointer to the environkfnbpmm,dpb;ntal variable.
 */
char **_getenv(const char *var)
{
	int indez, let;

	let = _strlen(var);
	for (indez = 0; environ[indez]; indez++)
	{
		if (_strncmp(var, environ[indez], let) == 0)
			return (&environ[indez]);
	}

	return (NULL);
}
