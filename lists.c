#include "shell.h"

/**
 * add_to_list - Adds a new node at the beginning of a list
 * @head: Double pointer to the head of the list
 * @str: String to be added to the list
 *
 * Return: Address of the new element, or NULL if it failed
 */
list_t *add_to_list(list_t **head, const char *str)
{
	list_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	/* Initialize the new node */
	new_node->str = _strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	/* Update the next pointer of the new node */
	new_node->next = *head;

	/* Update the head to point to the new node */
	*head = new_node;

	return (new_node);
}

/**
 * add_to_list_end - Adds a new node at the end of a list
 * @head: Double pointer to the head of the list
 * @str: String to be added to the list
 *
 * Return: Address of the new element, or NULL if it failed
 */
list_t *add_to_list_end(list_t **head, const char *str)
{
	list_t *new_node, *last_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	/* Initialize the new node */
	new_node->str = _strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;

	if (!*head)
	{
		/* If the list is empty, make the new node the head */
		*head = new_node;
	}
	else
	{
		/* Otherwise, traverse the list to find the last node */
		last_node = *head;
		while (last_node->next)
			last_node = last_node->next;

		/* Append the new node to the end of the list */
		last_node->next = new_node;
	}

	return (new_node);
}

/**
 * print_list - Prints all the elements of a list
 * @head: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_list(const list_t *head)
{
	size_t count = 0;

	/* Traverse the list and print each node */
	while (head)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		count++;
	}

	return (count);
}

/**
 * free_list - Frees all the elements of a list
 * @head: Double pointer to the head of the list
 *
 * Return: void
 */
void free_list(list_t **head)
{
	list_t *current, *next;

	/* Traverse the list and free each node */
	current = *head;
	while (current)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}

	/* Update the head pointer to NULL */
	*head = NULL;
}
