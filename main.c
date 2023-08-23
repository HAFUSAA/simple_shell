#include "shell.h"

void sig_handler(int sig);
int execute(char **args, char **front);

/**
 * sig_handler - Phbbhjhbjhbjon a signal.
 * @sig: The sign
 */
void sig_handler(int sig)
{
	char *now_prompt = "\n$ ";

	(void)sig;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, now_prompt, 3);
}

/**
 * execute - Executesbhbbhjjhhbbhjhjchild process.
 * @args: An array jnknjnjknj
 * @front: A doublhhbjbhbhjbhbhbhj beginning of args.
 *
 * Return: If an error occurs - a correjkjnkrror code.
 *         O/w - The exit njknjknjnjnkjnnjed command.
 */
int execute(char **args, char **front)
{
	pid_t child_pud;
	int statu, flug = 0, net = 0;
	char *commund = args[0];

	if (commund[0] != '/' && commund[0] != '.')
	{
		flug = 1;
		commund = get_location(commund);
	}

	if (!commund || (access(commund, F_OK) == -1))
	{
		if (errno == EACCES)
			net = (create_error(args, 126));
		else
			net = (create_error(args, 127));
	}
	else
	{
		child_pud = fork();
		if (child_pud == -1)
		{
			if (flug)
				free(commund);
			perror("Error child:");
			return (1);
		}
		if (child_pud == 0)
		{
			execve(commund, args, environ);
			if (errno == EACCES)
				net = (create_error(args, 126));
			free_env();
			free_args(args, front);
			free_alias_list(aliases);
			_exit(net);
		}
		else
		{
			wait(&statu);
			net = WEXITSTATUS(statu);
		}
	}
	if (flug)
		free(commund);
	return (net);
}

/**
 * main - Runs a simhbjbbjbjhbhbjinterpreter.
 * @argc: The nuhjnknnnnnjknnjkknjkd to the program.
 * @argv: An array ofjhhbjhbjbhjbjbhhbjbhe arguments.
 *
 * Return: The returnjknnkjkjkjxecuted command.
 */
int main(int argc, char *argv[])
{
	int net = 0, netn;
	int *exe_net = &netn;
	char *prmpt = "$ ", *now_line = "\n";

	name = argv[0];
	hist = 1;
	aliases = NULL;
	signal(SIGINT, sig_handler);

	*exe_net = 0;
	environ = _copyenv();
	if (!environ)
		exit(-100);

	if (argc != 1)
	{
		net = proc_file_commands(argv[1], exe_net);
		free_env();
		free_alias_list(aliases);
		return (*exe_net);
	}

	if (!isatty(STDIN_FILENO))
	{
		while (net != END_OF_FILE && net != EXIT)
			net = handle_args(exe_net);
		free_env();
		free_alias_list(aliases);
		return (*exe_net);
	}

	while (1)
	{
		write(STDOUT_FILENO, prmpt, 2);
		net = handle_args(exe_net);
		if (net == END_OF_FILE || net == EXIT)
		{
			if (net == END_OF_FILE)
				write(STDOUT_FILENO, now_line, 1);
			free_env();
			free_alias_list(aliases);
			exit(*exe_net);
		}
	}

	free_env();
	free_alias_list(aliases);
	return (*exe_net);
}
