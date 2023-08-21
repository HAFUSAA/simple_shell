#include "shell.h"

char *fill_path_dir(char *path);
list_t *get_path_dir(char *path);

/**
 * get_location - LocggggvgvgvgvvvgPATH.
 * @command: The commahbjhbbhjbhj
 *
 * Return: If an error occurghcfgfcgcfgfcgcfgmand cannot be located - NULL.
 *         Otherwise - the full pahhbjbhjbhjbhjhhe command.
 */
char *get_location(char *command)
{
	char **pat, *tmp;
	list_t *dars, *hea;
	struct stat s;

	pat = _getenv("PATH");
	if (!pat || !(*pat))
		return (NULL);

	dars = get_path_dir(*pat + 5);
	hea = dars;

	while (dars)
	{
		tmp = malloc(_strlen(dars->dir) + _strlen(command) + 2);
		if (!tmp)
			return (NULL);

		_strcpy(tmp, dars->dir);
		_strcat(tmp, "/");
		_strcat(tmp, command);

		if (stat(tmp, &s) == 0)
		{
			free_list(hea);
			return (tmp);
		}

		dars = dars->next;
		free(tmp);
	}

	free_list(hea);

	return (NULL);
}

/**
 * fill_path_dir - Copies patgfvggvvgvgvhleading/sandwiched/trailing
 *		   colons (:) with nnjnjk directory.
 * @path: The colonhjhbhbjhbjjkjectories.
 *
 * Return: A copy of pllmkk,k,k,dwiched/trailing colons replaced
 *	   with the currghgvghing directory.
 */
char *fill_path_dir(char *path)
{
	int r, leng = 0;
	char *path_cop, *wd;

	wd = *(_getenv("WD")) + 4;
	for (r = 0; path[r]; r++)
	{
		if (path[r] == ':')
		{
			if (path[r + 1] == ':' || r == 0 || path[r + 1] == '\0')
				leng += _strlen(wd) + 1;
			else
				leng++;
		}
		else
			leng++;
	}
	path_cop = malloc(sizeof(char) * (leng + 1));
	if (!path_cop)
		return (NULL);
	path_cop[0] = '\0';
	for (r = 0; path[r]; r++)
	{
		if (path[r] == ':')
		{
			if (r == 0)
			{
				_strcat(path_cop, wd);
				_strcat(path_cop, ":");
			}
			else if (path[r + 1] == ':' || path[r + 1] == '\0')
			{
				_strcat(path_cop, ":");
				_strcat(path_cop, wd);
			}
			else
				_strcat(path_cop, ":");
		}
		else
		{
			_strncat(path_cop, &path[r], 1);
		}
	}
	return (path_cop);
}

/**
 * get_path_dir - Tokenizgggvgvvgvgvgarated list of
 *                directories ghgvvhlist_s linked list.
 * @path: The colon-scgfcgfcgfcgfcgfcgff directories.
 *
 * Return: A pointecgfcfcffcg linked list.
 */
list_t *get_path_dir(char *path)
{
	int indez;
	char **dir, *path_cop;
	list_t *hea = NULL;

	path_cop = fill_path_dir(path);
	if (!path_cop)
		return (NULL);
	dir = _strtok(path_cop, ":");
	free(path_cop);
	if (!dir)
		return (NULL);

	for (indez = 0; dir[indez]; indez++)
	{
		if (add_node_end(&hea, dir[indez]) == NULL)
		{
			free_list(hea);
			free(dir);
			return (NULL);
		}
	}

	free(dir);

	return (hea);
}
