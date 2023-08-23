#include "shell.h"

char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/**
 * _strchr - Locates a charagvgvgvgvvggvjgvjg.
 * @s: The string to be searchvhvuhyvjhvj
 * @c: The character to be hjhjhjhbkhbkh
 *
 * Return: If c is found - a poijhjuioijojoo^pirst occurence.
 *         If c is not found - NULL.
 */
char *_strchr(char *s, char c)
{
	int indez;

	for (indez = 0; s[indez]; indez++)
	{
		if (s[indez] == c)
			return (s + indez);
	}

	return (NULL);
}

/**
 * _strspn - Gets the lenghbbbkjbjkbjkbjkbjkjsubstring.
 * @s: The sjjkjjllnkmkm
 * @accept: The prefix hhbhbjjbjlbjlbo be measured.
 *
 * Return: The numberhbhhjhjvhkhich
 *         consistbh bhljjkjpms from accept.
 */
int _strspn(char *s, char *accept)
{
	int bites = 0;
	int indez;

	while (*s)
	{
		for (indez = 0; accept[indez]; indez++)
		{
			if (*s == accept[indez])
			{
				bites++;
				break;
			}
		}
		s++;
	}
	return (bites);
}

/**
 * _strcmp - Comparesvhhhbkjngs.
 * @s1: The firsnjkjljnjjlbe compared.
 * @s2: The bhbhkbjbjbjto be compared.
 *
 * Return: Positive uhuhhhijkierence if s1 > s2
 *         0 if s1 = s2
 *         Negatjnhjnhjlnkij^prence if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - Comparehjbkbkjkjjjlngs.
 * @s1: Pointerjnjnnlk kjl
 * @s2: Pointejkkjlllllllnkg.
 * @n: The filjnnpopik the strings to compare.
 *
 * Return: Less than 0 if s1 jlj,impomorter than s2.
 *         0 if s1 and s2 match.
 *         Greater than 0 if s1 isuoijijpkor than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t l;

	for (l = 0; s1[l] && s2[l] && l < n; l++)
	{
		if (s1[l] > s2[l])
			return (s1[l] - s2[l]);
		else if (s1[l] < s2[l])
			return (s1[l] - s2[l]);
	}
	if (l == n)
		return (0);
	else
		return (-15);
}
