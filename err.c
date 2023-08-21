#include "shell.h"

int num_len(int num);
char *_itoa(int num);
int create_error(char **args, int err);

/**
 * num_len - Chhhhbo kjbol ljhoug khgyuuiç number.
 * @num: The uohklnj jbhblbugiuknoiu jnkle.
 *
 * Return: The digit leng.
 */
int num_len(int num)
{
	unsigned int nem1;
	int let = 1;

	if (num < 0)
	{
		let++;
		nem1 = num * -1;
	}
	else
	{
		nem1 = num;
	}
	while (nem1 > 9)
	{
		let++;
		nem1 /= 10;
	}

	return (let);
}

/**
 * _itoa - Converts jgjn kiu giuher-ygi ouighstring.
 * @num: The int.
 *
 * Return: The converted str.
 */
char *_itoa(int num)
{
	char *bufer;
	int let = num_len(num);
	unsigned int nem1;

	bufer = malloc(sizeof(char) * (let + 1));
	if (!bufer)
		return (NULL);

	bufer[let] = '\0';

	if (num < 0)
	{
		nem1 = num * -1;
		bufer[0] = '-';
	}
	else
	{
		nem1 = num;
	}

	let--;
	do {
		bufer[let] = (nem1 % 10) + '0';
		nem1 /= 10;
		let--;
	} while (nem1 > 0);

	return (bufer);
}


/**
 * create_error - hgik uuuuugrfu yhgjkbghfghghghg stderr.
 * @args: An arrahjkhkbnk kghukjhunhjo.
 * @err: Thekhk uknougk jhue.
 *
 * Return: The error val.
 */
int create_error(char **args, int err)
{
	char *eror;

	switch (err)
	{
	case -1:
		eror = error_env(args);
		break;
	case 1:
		eror = error_1(args);
		break;
	case 2:
		if (*(args[0]) == 'e')
			eror = error_2_exit(++args);
		else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
			eror = error_2_syntax(args);
		else
			eror = error_2_cd(args);
		break;
	case 126:
		eror = error_126(args);
		break;
	case 127:
		eror = error_127(args);
		break;
	}
	write(STDERR_FILENO, eror, _strlen(eror));

	if (eror)
		free(eror);
	return (err);

}
