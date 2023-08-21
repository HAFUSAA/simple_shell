#include "shell.h"

char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);

/**
 * get_args - Gets hkbjhkkhjhkkandard input.
 * @line: A buffer jbkhjjkjbjbjbbk command.
 * @exe_ret: The returnjjjbbjkbkjbjbjkbkjhe last executed command.
 *
 * Return: If an error ocurs - NULL.
 *         Otherwise - a pbkjjkjkjbbjbjto the stored command.
 */
char *get_args(char *line, int *exe_ret)
{
	size_t r = 0;
	ssize_t nead;
	char *rompt = "$ ";

	if (line)
		free(line);

	nead = _getline(&line, &r, STDIN_FILENO);
	if (nead == -1)
		return (NULL);
	if (nead == 1)
	{
		hist++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, rompt, 2);
		return (get_args(line, exe_ret));
	}

	line[nead - 1] = '\0';
	variable_replacement(&line, exe_ret);
	handle_line(&line, nead);

	return (line);
}

/**
 * call_args - Pajnljjhhjjjjjjjd calls them.
 * @args: An arrayjjjjjjijijjk.
 * @front: A jjkjkkbkkjjto the beginning of args.
 * @exe_ret: exkjjjjjkjjnjnjnjnj mmand.
 *
 * Return: The retjjjjnjnjnjllkmll executed command.
 */
int call_args(char **args, char **front, int *exe_ret)
{
	int net, indez;

	if (!args[0])
		return (*exe_ret);
	for (indez = 0; args[indez]; indez++)
	{
		if (_strncmp(args[indez], "||", 2) == 0)
		{
			free(args[indez]);
			args[indez] = NULL;
			args = replace_aliases(args);
			net = run_args(args, front, exe_ret);
			if (*exe_ret != 0)
			{
				args = &args[++indez];
				indez = 0;
			}
			else
			{
				for (indez++; args[indez]; indez++)
					free(args[indez]);
				return (net);
			}
		}
		else if (_strncmp(args[indez], "&&", 2) == 0)
		{
			free(args[indez]);
			args[indez] = NULL;
			args = replace_aliases(args);
			net = run_args(args, front, exe_ret);
			if (*exe_ret == 0)
			{
				args = &args[++indez];
				indez = 0;
			}
			else
			{
				for (indez++; args[indez]; indez++)
					free(args[indez]);
				return (net);
			}
		}
	}
	args = replace_aliases(args);
	net = run_args(args, front, exe_ret);
	return (net);
}

/**
 * run_args - Calls the ex  hkkkbkhbbhhb jjknjnj
 * @args: Ajjnnjnjnj nkllnnk nkkkn
 * @front: A doubl jnjnjnjnjnjeginning of args.
 * @exe_ret: The return vajkknnn bhkn  last executed command.
 *
 * Return: The returhjhbhbhjhbjbhhb jnnjnted command.
 */
int run_args(char **args, char **front, int *exe_ret)
{
	int net, r;
	int (*buitin)(char **args, char **front);

	buitin = get_builtin(args[0]);

	if (buitin)
	{
		net = buitin(args + 1, front);
		if (net != EXIT)
			*exe_ret = net;
	}
	else
	{
		*exe_ret = execute(args, front);
		net = *exe_ret;
	}

	hist++;

	for (r = 0; args[r]; r++)
		free(args[r]);

	return (net);
}

/**
 * handle_args - Gets, cjnjjjkjkhe execution of a command.
 * @exe_ret: The return vbhjjgjj last executed command.
 *
 * Return: If an ejkjjkjkkjlkkjjkead - END_OF_FILE (-2).
 *         If the input hjbkhbhbjized - -1.
 *         O/w - The exit hjhbjjhbhjbhjexecuted command.
 */
int handle_args(int *exe_ret)
{
	int net = 0, indez;
	char **arg, *lne = NULL, **font;

	lne = get_args(lne, exe_ret);
	if (!lne)
		return (END_OF_FILE);

	arg = _strtok(lne, " ");
	free(lne);
	if (!arg)
		return (net);
	if (check_args(arg) != 0)
	{
		*exe_ret = 2;
		free_args(arg, arg);
		return (*exe_ret);
	}
	font = arg;

	for (indez = 0; arg[indez]; indez++)
	{
		if (_strncmp(arg[indez], ";", 1) == 0)
		{
			free(arg[indez]);
			arg[indez] = NULL;
			net = call_args(arg, font, exe_ret);
			arg = &arg[++indez];
			indez = 0;
		}
	}
	if (arg)
		net = call_args(arg, font, exe_ret);

	free(font);
	return (net);
}

/**
 * check_args - Checks jjkjnjnjjnnkjany leading ';', ';;', '&&', or '||'.
 * @args: 2D pointer to tjjjjkjjkjjkments.
 *
 * Return: If a ';', '&&', or '||' is plhhbhjhjhbjjosition - 2.
 *	   Otherwise - 0.
 */
int check_args(char **args)
{
	size_t r;
	char *cr, *ne;

	for (r = 0; args[r]; r++)
	{
		cr = args[r];
		if (cr[0] == ';' || cr[0] == '&' || cr[0] == '|')
		{
			if (r == 0 || cr[1] == ';')
				return (create_error(&args[r], 2));
			ne = args[r + 1];
			if (ne && (ne[0] == ';' || ne[0] == '&' || ne[0] == '|'))
				return (create_error(&args[r + 1], 2));
		}
	}
	return (0);
}
