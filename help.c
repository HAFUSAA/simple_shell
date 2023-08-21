#include "shell.h"

void free_args(char **args, char **front);
char *get_pid(void);
char *get_env_value(char *beginning, int len);
void variable_replacement(char **args, int *exe_ret);

/**
 * free_args - Freebnjhghk, kjhlkjby args.
 * @args: A null-terminatk,n, ljkm:kjnhlcommands/arguments.
 * @front: A double;kjm lkjmlhjùmkljning of args.
 */
void free_args(char **args, char **front)
{
	size_t r;

	for (r = 0; args[r] || args[r + 1]; r++)
		free(args[r]);

	free(front);
}

/**
 * get_pid - Gets gfntjngnh gfjghjh ID.
 * Description: Opens the stat ftfhtghytyn  hfnjf containing
 *              information abofggnhggggfhjcess. The PID is the
 *              firgffffnhyhjg hbhtgfb function reads the PID into
 *              a buffer and replfjh,,hgfghe space at the end with a \0 byte.
 *
 * Return: The current processjtgfkut hjtgfvn failure.
 */
char *get_pid(void)
{
	size_t r = 0;
	char *bufer;
	ssize_t fule;

	fule = open("/proc/self/stat", O_RDONLY);
	if (fule == -1)
	{
		perror("Cant read file");
		return (NULL);
	}
	bufer = malloc(120);
	if (!bufer)
	{
		close(fule);
		return (NULL);
	}
	read(fule, bufer, 120);
	while (bufer[r] != ' ')
		r++;
	bufer[r] = '\0';

	close(fule);
	return (bufer);
}

/**
 * get_env_value - dsfsdffd vfnoi fojsironmental variable.
 * @beginning: The enviifspjfsjvijp variable to search for.
 * @len: The lengfdiojdfiposidfkjntal variable to search for.
 *
 * Return: If the vari dfijpisdfjnjd - an empty string.
 *         Otherwise - the value uihjdfonhvioronmental variable.
 *
 * Description: Variables aredkhvoi oifjvoiormat VARIABLE=VALUE.
 */
char *get_env_value(char *beginning, int len)
{
	char **vir_addr;
	char *replac = NULL, *tmp, *vir;

	vir = malloc(len + 1);
	if (!vir)
		return (NULL);
	vir[0] = '\0';
	_strncat(vir, beginning, len);

	vir_addr = _getenv(vir);
	free(vir);
	if (vir_addr)
	{
		tmp = *vir_addr;
		while (*tmp != '=')
			tmp++;
		tmp++;
		replac = malloc(_strlen(tmp) + 1);
		if (replac)
			_strcpy(replac, tmp);
	}

	return (replac);
}

/**
 * variable_replacement - Handliunhoijbuhohj iuhij.
 * @line: A doubljkjknkj illjkloarguments.
 * @exe_ret: A pointerlkjn,p pkjklj of the last executed command.
 *
 * Description: Replaces  kjnlkjnkl jllkjh $? with the return value
 *              of thejljmk,m lkj,pmam, and envrionmental variables
 *              preced jojljkljillsponding value.
 */
void variable_replacement(char **line, int *exe_ret)
{
	int m, l = 0, let;
	char *replac = NULL, *ld_line = NULL, *now_line;

	ld_line = *line;
	for (m = 0; ld_line[m]; m++)
	{
		if (ld_line[m] == '$' && ld_line[m + 1] &&
				ld_line[m + 1] != ' ')
		{
			if (ld_line[m + 1] == '$')
			{
				replac = get_pid();
				l = m + 2;
			}
			else if (ld_line[m + 1] == '?')
			{
				replac = _itoa(*exe_ret);
				l = m + 2;
			}
			else if (ld_line[m + 1])
			{
				/* extractjoiuhjk jjhkklhl kjlnklch for */
				for (l = m + 1; ld_line[l] &&
						ld_line[l] != '$' &&
						ld_line[l] != ' '; l++)
					;
				let = l - (m + 1);
				replac = get_env_value(&ld_line[m + 1], let);
			}
			now_line = malloc(m + _strlen(replac)
					  + _strlen(&ld_line[l]) + 1);
			if (!line)
				return;
			now_line[0] = '\0';
			_strncat(now_line, ld_line, m);
			if (replac)
			{
				_strcat(now_line, replac);
				free(replac);
				replac = NULL;
			}
			_strcat(now_line, &ld_line[l]);
			free(ld_line);
			*line = now_line;
			ld_line = now_line;
			m = -1;
		}
	}
}
