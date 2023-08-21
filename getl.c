#include "shell.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/**
 * _realloc - kbln j;gljlhmikfgjy hjgfjhghgjhn,bv ,gfkkgnfree.
 * @ptr: A pointer tojkgk hkjghkfj gkgreuy bfhgtgjhcfd.
 * @old_size: jkkkkjhlllt jgh,gkkljmpjl for ptr.
 * @new_size: The size in bytes lm hklihvggg ,hgry block.
 *
 * Return: If new_size == old_size - ptr.
 *         If new_size == 0 ankjljbhklnjl NULL - NULL.
 *         Otherwise - a pointer to the reallocatemùljkhljk.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mum;
	char *ptr_cpy, *filer;
	unsigned int indez;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		mum = malloc(new_size);
		if (mum == NULL)
			return (NULL);

		return (mum);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_cpy = ptr;
	mum = malloc(sizeof(*ptr_cpy) * new_size);
	if (mum == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filer = mum;

	for (indez = 0; indez < old_size && indez < new_size; indez++)
		filer[indez] = *ptr_cpy++;

	free(ptr);
	return (mum);
}

/**
 * assign_lineptr - hkggjlou kuglg gkgbkjetline.
 * @lineptr: A buffjkhlk liikj khghgnh,jut string.
 * @n: khjlk kiln jkjl.
 * @buffer: The strinklhjm j;hlnjmimo lineptr.
 * @b: The sizelkjhm jkhlokr.
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - Read jlkjghkn stream.
 * @lineptr: A bulkhlkjhg bjkhlre the input.
 * @n: The simkjlkj jkhkjl
 * @stream: Thkhl jhkljjjjjol read from.
 *
 * Return: The number read.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t inpat;
	ssize_t net;
	char b = 'x', *bufer;
	int l;

	if (inpat == 0)
		fflush(stream);
	else
		return (-1);
	inpat = 0;

	bufer = malloc(sizeof(char) * 120);
	if (!bufer)
		return (-1);

	while (b != '\n')
	{
		l = read(STDIN_FILENO, &b, 1);
		if (l == -1 || (l == 0 && inpat == 0))
		{
			free(bufer);
			return (-1);
		}
		if (l == 0 && inpat != 0)
		{
			inpat++;
			break;
		}

		if (inpat >= 120)
			bufer = _realloc(bufer, inpat, inpat + 1);

		bufer[inpat] = b;
		inpat++;
	}
	bufer[inpat] = '\0';

	assign_lineptr(lineptr, n, bufer, inpat);

	net = inpat;
	if (l != 0)
		inpat = 0;
	return (net);
}
