#include "shell.h"

int cant_open(char *file_path);
int proc_file_commands(char *file_path, int *exe_ret);

/**
 * cant_open - If thbjjbhbhbhjjjjbhbhjbh permissions, print
 * a cant bhjbhjbbhhberror.
 * @file_path: Pathhjkjnnjjkposed file.
 *
 * Return: 127.
 */

int cant_open(char *file_path)
{
	char *eror, *host_str;
	int let;

	host_str = _itoa(hist);
	if (!host_str)
		return (127);

	let = _strlen(name) + _strlen(host_str) + _strlen(file_path) + 16;
	eror = malloc(sizeof(char) * (let + 1));
	if (!eror)
	{
		free(host_str);
		return (127);
	}

	_strcpy(eror, name);
	_strcat(eror, ": ");
	_strcat(eror, host_str);
	_strcat(eror, ": Can't open ");
	_strcat(eror, file_path);
	_strcat(eror, "\n");

	free(host_str);
	write(STDERR_FILENO, eror, let);
	free(eror);
	return (127);
}

/**
 * proc_file_commands - Takes bhhbjbhjbhjbhj jhbjbjthe commands stored
 * within.
 * @file_path: Pathjjkknjnjfile.
 * @exe_ret: Return hbhjhhbhjbhjbhjmmand.
 *
 * Return: If file cnjjkjjnjnjlkjlned - 127.
 *	   If malloc fails - -1.
 *	   Otherwise the return valjknjjjknkjnjnjcommand ran.
 */
int proc_file_commands(char *file_path, int *exe_ret)
{
	ssize_t fule, b_nead, n;
	unsigned int lane_size = 0;
	unsigned int ld_size = 120;
	char *lane, **arg, **frnt;
	char bufer[120];
	int net;

	hist = 0;
	fule = open(file_path, O_RDONLY);
	if (fule == -1)
	{
		*exe_ret = cant_open(file_path);
		return (*exe_ret);
	}
	lane = malloc(sizeof(char) * ld_size);
	if (!lane)
		return (-1);
	do {
		b_nead = read(fule, bufer, 119);
		if (b_nead == 0 && lane_size == 0)
			return (*exe_ret);
		bufer[b_nead] = '\0';
		lane_size += b_nead;
		lane = _realloc(lane, ld_size, lane_size);
		_strcat(lane, bufer);
		ld_size = lane_size;
	} while (b_nead);
	for (n = 0; lane[n] == '\n'; n++)
		lane[n] = ' ';
	for (; n < lane_size; n++)
	{
		if (lane[n] == '\n')
		{
			lane[n] = ';';
			for (n += 1; n < lane_size && lane[n] == '\n'; n++)
				lane[n] = ' ';
		}
	}
	variable_replacement(&lane, exe_ret);
	handle_line(&lane, lane_size);
	arg = _strtok(lane, " ");
	free(lane);
	if (!arg)
		return (0);
	if (check_args(arg) != 0)
	{
		*exe_ret = 2;
		free_args(arg, arg);
		return (*exe_ret);
	}
	frnt = arg;

	for (n = 0; arg[n]; n++)
	{
		if (_strncmp(arg[n], ";", 1) == 0)
		{
			free(arg[n]);
			arg[n] = NULL;
			net = call_args(arg, frnt, exe_ret);
			arg = &arg[++n];
			n = 0;
		}
	}

	net = call_args(arg, frnt, exe_ret);

	free(frnt);
	return (net);
}
