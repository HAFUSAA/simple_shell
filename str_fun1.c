#include "shell.h"

int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);

/**
 * _strlen - Retggvhggvhgvhof a string.
 * @s: A pgvjghggvvracters string.
 *
 * Return: Thehjbgvjgvhj,hjter string.
 */
int _strlen(const char *s)
{
	int leng = 0;

	if (!s)
		return (leng);
	for (leng = 0; s[leng]; leng++)
		;
	return (leng);
}

/**
 * _strcpy - Copies the sgvgvhgvhghghrc, including the
 *           terminatinghgvvgvgvjo the buffer pointed by des.
 * @dest: Pointer to bhbjbhjbhbjbhubkbjion of copied string.
 * @src: Pointer to the gvgvvjghbvjhvjce string.
 *
 * Return: Pointerjnhb .
 */
char *_strcpy(char *dest, const char *src)
{
	size_t l;

	for (l = 0; src[l] != '\0'; l++)
		dest[l] = src[l];
	dest[l] = '\0';
	return (dest);
}

/**
 * _strcat - Concantenateskjjjkbkjbkhbhjbjlk two strings.
 * @dest: Pointer to destinabhkbkhbhbkjbkj
 * @src: Pointer to source stribhkkbhbkkjbk.
 *
 * Return: Pointer to destinabkhbhhbbhjbh.
 */
char *_strcat(char *dest, const char *src)
{
	char *destTem;
	const char *srcTem;

	destTem = dest;
	srcTem =  src;

	while (*destTem != '\0')
		destTem++;

	while (*srcTem != '\0')
		*destTem++ = *srcTem++;
	*destTem = '\0';
	return (dest);
}

/**
 * _strncat - Concantenatesgvgvvgjvhjvhjvhjere n number
 *            of bytes are cogvjgvvgvgvhhjce.
 * @dest: Pointer to desthvjhjvjgvj.
 * @src: Pointer to hbjhjbbhjbhkbkj
 * @n: n bytes to hbhbbkhkbjbjbjb
 *
 * Return: Pointebhkhbbhbkjjbk string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_let = _strlen(dest);
	size_t l;

	for (l = 0; l < n && src[l] != '\0'; l++)
		dest[dest_let + l] = src[l];
	dest[dest_let + l] = '\0';

	return (dest);
}
