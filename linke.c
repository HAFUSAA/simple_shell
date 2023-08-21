#include "shell.h"

alias_t *add_alias_end(alias_t **head, char *name, char *value);
void free_alias_list(alias_t *head);
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

/**
 * add_alias_end - Adhjjjjjjjjjjjjjjjjjjjjf a alias_t linked list.
 * @head: A pointjkkkkkkkkkkbjjbkkbkbkjbjt_t list.
 * @name: The name of bjbbbhjhbbkbkjbkbkjbjbjk added.
 * @value: The value ofbhjbhbhbhjbhjhjbbjkbjded.
 *
 * Return: If an error ocus - NULL.
 *         Otherwise - a pokjjkkjinter to the new node.
 */
alias_t *add_alias_end(alias_t **head, char *name, char *value)
{
	alias_t *now_node = malloc(sizeof(alias_t));
	alias_t *lst;

	if (!now_node)
		return (NULL);

	now_node->next = NULL;
	now_node->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (!now_node->name)
	{
		free(now_node);
		return (NULL);
	}
	now_node->value = value;
	_strcpy(now_node->name, name);

	if (*head)
	{
		lst = *head;
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = now_node;
	}
	else
		*head = now_node;

	return (now_node);
}

/**
 * add_node_end - Adds a nodhbhjbbhjbhbhjbhjbhst_t linked list.
 * @head: A pointer to thehbjhbjjbhjbhbhjbhjlist.
 * @dir: The directory jkjjnjnnnj to contain.
 *
 * Return: If an error ocurs - NULL.
 *         Otherwise - a poilkjlkjnter to the new node.
 */
list_t *add_node_end(list_t **head, char *dir)
{
	list_t *now_node = malloc(sizeof(list_t));
	list_t *lst;

	if (!now_node)
		return (NULL);

	now_node->dir = dir;
	now_node->next = NULL;

	if (*head)
	{
		lst = *head;
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = now_node;
	}
	else
		*head = now_node;

	return (now_node);
}

/**
 * free_alias_list - Freeshhbjjbhbhjbhjbhjt linked list.
 * @head: THe head of the jnkjjnnjnj
 */
void free_alias_list(alias_t *head)
{
	alias_t *nxt;

	while (head)
	{
		nxt = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = nxt;
	}
}

/**
 * free_list - Freeggvggvggghed list.
 * @head: The heaghhgggght_t list.
 */
void free_list(list_t *head)
{
	list_t *nxt;

	while (head)
	{
		nxt = head->next;
		free(head->dir);
		free(head);
		head = nxt;
	}
}
