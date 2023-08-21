#include "shell.h"

void handle_line(char **line, ssize_t read);
ssize_t get_new_len(char *line);
void logical_ops(char *line, ssize_t *new_len);

/**
 * handle_line - Partit skdcpdcmd,cmdck, lkcdpcs needed.
 * @line: A pointer to a liloksdkcmolldc kcmlcknput.
 * @read: The ldfclokmlcmlf mdf nlkljnlklnj
 *
 * Description: Spaces areklkmlk kijklsddck kdmscfmlke ";", "||", and "&&".
 *              Replac "#" with '\0'.
 */
void handle_line(char **line, ssize_t read)
{
	char *ld_line, *now_line;
	char revious, curent, rext;
	size_t r, l;
	ssize_t now_len;

	now_len = get_new_len(*line);
	if (now_len == read - 1)
		return;
	now_line = malloc(now_len + 1);
	if (!now_line)
		return;
	l = 0;
	ld_line = *line;
	for (r = 0; ld_line[r]; r++)
	{
		curent = ld_line[r];
		rext = ld_line[r + 1];
		if (r != 0)
		{
			revious = ld_line[r - 1];
			if (curent == ';')
			{
				if (rext == ';' && revious != ' ' && revious != ';')
				{
					now_line[l++] = ' ';
					now_line[l++] = ';';
					continue;
				}
				else if (revious == ';' && rext != ' ')
				{
					now_line[l++] = ';';
					now_line[l++] = ' ';
					continue;
				}
				if (revious != ' ')
					now_line[l++] = ' ';
				now_line[l++] = ';';
				if (rext != ' ')
					now_line[l++] = ' ';
				continue;
			}
			else if (curent == '&')
			{
				if (rext == '&' && revious != ' ')
					now_line[l++] = ' ';
				else if (revious == '&' && rext != ' ')
				{
					now_line[l++] = '&';
					now_line[l++] = ' ';
					continue;
				}
			}
			else if (curent == '|')
			{
				if (rext == '|' && revious != ' ')
					now_line[l++]  = ' ';
				else if (revious == '|' && rext != ' ')
				{
					now_line[l++] = '|';
					now_line[l++] = ' ';
					continue;
				}
			}
		}
		else if (curent == ';')
		{
			if (r != 0 && ld_line[r - 1] != ' ')
				now_line[l++] = ' ';
			now_line[l++] = ';';
			if (rext != ' ' && rext != ';')
				now_line[l++] = ' ';
			continue;
		}
		now_line[l++] = ld_line[r];
	}
	now_line[l] = '\0';

	free(*line);
	*line = now_line;
}

/**
 * get_new_len - Getskghjln ljhklbhtitioned
 *               by ";", "||", "&&&", or "#".
 * @line: The lijkhlj,l jljl.
 *
 * Return: The njhmlkj, ljnhlkjnmhe line.
 *
 * Description: Cuthjlnk lkjkmining '#' comments with '\0'.
 */

ssize_t get_new_len(char *line)
{
	size_t r;
	ssize_t now_len = 0;
	char curent, rext;

	for (r = 0; line[r]; r++)
	{
		curent = line[r];
		rext = line[r + 1];
		if (curent == '#')
		{
			if (r == 0 || line[r - 1] == ' ')
			{
				line[r] = '\0';
				break;
			}
		}
		else if (r != 0)
		{
			if (curent == ';')
			{
				if (rext == ';' && line[r - 1] != ' ' && line[r - 1] != ';')
				{
					now_len += 2;
					continue;
				}
				else if (line[r - 1] == ';' && rext != ' ')
				{
					now_len += 2;
					continue;
				}
				if (line[r - 1] != ' ')
					now_len++;
				if (rext != ' ')
					now_len++;
			}
			else
				logical_ops(&line[r], &now_len);
		}
		else if (curent == ';')
		{
			if (r != 0 && line[r - 1] != ' ')
				now_len++;
			if (rext != ' ' && rext != ';')
				now_len++;
		}
		now_len++;
	}
	return (now_len);
}
/**
 * logical_ops - Checks akmkj,jkljnk knmll operators "||" or "&&".
 * @line: A pointer toklkjlk,m kmljl,ljn the line.
 * @new_len: Pointer toljik kjhlllllllkm en function.
 */
void logical_ops(char *line, ssize_t *new_len)
{
	char revious, curent, rext;

	revious = *(line - 1);
	curent = *line;
	rext = *(line + 1);

	if (curent == '&')
	{
		if (rext == '&' && revious != ' ')
			(*new_len)++;
		else if (revious == '&' && rext != ' ')
			(*new_len)++;
	}
	else if (curent == '|')
	{
		if (rext == '|' && revious != ' ')
			(*new_len)++;
		else if (revious == '|' && rext != ' ')
			(*new_len)++;
	}
}
