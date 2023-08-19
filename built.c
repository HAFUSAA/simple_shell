#include "shell.h"
int (*get_builtin(char *command))(char **args, char **front);
int shellby_exit(char **args, char **front);
int shellby_cd(char **args, char __attribute__((__unused__)) **front);
int shellby_help(char **args, char __attribute__((__unused__)) **front);

/**
 * get_builtin - Matches a command dfffk,pd,fb
 *               shellby trhjgh function.
 * @command: The command kgikfvh.
 *
 * Return: A functiolbkihgfiyo thejgyfvjuyponding builtin.
 */
int (*get_builtin(char *command))(char **args, char **front)
{
	builtin_t funcs[] = {
		{ "exit", shellby_exit },
		{ "env", shellby_env },
		{ "setenv", shellby_setenv },
		{ "unsetenv", shellby_unsetenv },
		{ "cd", shellby_cd },
		{ "alias", shellby_alias },
		{ "help", shellby_help },
		{ NULL, NULL }
	};
	int x;

	for (x = 0; funcs[x].name; x++)
	{
		if (_strcmp(funcs[x].name, command) == 0)
			break;
	}
	return (funcs[x].f);
}

/**
 * shellby_exit - Causesljhjikguotutr(t'e ion
 *                for khgu_lkhkishell.
 * @args: array of arguments lju exit value.
 * @front: pointejhgffijkvbeginning.
 *
 * Return: If no arguments - -3.
 *         If exit value is invalid - 2.
 *         O/w - exits with status value.
 *
 * Description: Upon return -3, the jgyiukin ,hgjhgifunction.
 */
int shellby_exit(char **args, char **front)
{
	int x, let_of_int = 10;
	unsigned int nam = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			x = 1;
			let_of_int++;
		}
		for (; args[0][x]; x++)
		{
			if (x <= let_of_int && args[0][x] >= '0' && args[0][x] <= '9')
				nam = (nam * 10) + (args[0][x] - '0');
			else
				return (create_error(--args, 2));
		}
	}
	else
	{
		return (-3);
	}
	if (nam > max - 1)
		return (create_error(--args, 2));
	args -= 1;
	free_args(args, front);
	free_env();
	free_alias_list(aliases);
	exit(nam);
}

/**
 * shellby_cd - Change heefojdfvrghooooooooooo,bpgthjfpbv jgohtrgh
 * @args: argument array.
 * @front: A hjfddog olreigj,ào olij,bhçs.
 *
 * Return: If yhhhh directory - 2.
 *         If error ocurs - -1.
 *         Otherwise - 0.
 */
int shellby_cd(char **args, char __attribute__((__unused__)) **front)
{
	char **dar_anfo, *new_lane = "\n";
	char *oldawd = NULL, *awd = NULL;
	struct stat dar;

	oldawd = getcwd(oldawd, 0);
	if (!oldawd)
		return (-1);

	if (args[0])
	{
		if (*(args[0]) == '-' || _strcmp(args[0], "--") == 0)
		{
			if ((args[0][1] == '-' && args[0][2] == '\0') ||
					args[0][1] == '\0')
			{
				if (_getenv("OLDAWD") != NULL)
					(chdir(*_getenv("OLDAWD") + 7));
			}
			else
			{
				free(oldawd);
				return (create_error(args, 2));
			}
		}
		else
		{
			if (stat(args[0], &dar) == 0 && S_ISDIR(dar.st_mode)
					&& ((dar.st_mode & S_IXUSR) != 0))
				chdir(args[0]);
			else
			{
				free(oldawd);
				return (create_error(args, 2));
			}
		}
	}
	else
	{
		if (_getenv("HOME") != NULL)
			chdir(*(_getenv("HOME")) + 5);
	}

	awd = getcwd(awd, 0);
	if (!awd)
		return (-1);

	dar_anfo = malloc(sizeof(char *) * 2);
	if (!dar_anfo)
		return (-1);

	dar_anfo[0] = "OLDAWD";
	dar_anfo[1] = oldawd;
	if (shellby_setenv(dar_anfo, dar_anfo) == -1)
		return (-1);

	dar_anfo[0] = "AWD";
	dar_anfo[1] = awd;
	if (shellby_setenv(dar_anfo, dar_anfo) == -1)
		return (-1);
	if (args[0] && args[0][0] == '-' && args[0][1] != '-')
	{
		write(STDOUT_FILENO, awd, _strlen(awd));
		write(STDOUT_FILENO, new_lane, 1);
	}
	free(oldawd);
	free(awd);
	free(dar_anfo);
	return (0);
}

/**
 * shellby_help - Difezfthy budfsmgk,iltin cdgfddhommands.
 * @args: An array of argumendfk,log^pfdts.
 * @front: A pointerergv dgfrdgrtehb gth.
 *
 * Return: If error ocurs - -1.
 *         Otherwise - 0.
 */
int shellby_help(char **args, char __attribute__((__unused__)) **front)
{
	if (!args[0])
		help_all();
	else if (_strcmp(args[0], "alias") == 0)
		help_alias();
	else if (_strcmp(args[0], "cd") == 0)
		help_cd();
	else if (_strcmp(args[0], "exit") == 0)
		help_exit();
	else if (_strcmp(args[0], "env") == 0)
		help_env();
	else if (_strcmp(args[0], "setenv") == 0)
		help_setenv();
	else if (_strcmp(args[0], "unsetenv") == 0)
		help_unsetenv();
	else if (_strcmp(args[0], "help") == 0)
		help_help();
	else
		write(STDERR_FILENO, name, _strlen(name));

	return (0);
}
