#include "main.h"
/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: pointer to pointer to the last added node
 * @c: character literal
 *
 * Return: the address of new element or NULL otherwise
 */
list_t *addNode(list_t **head, char c)
{
	/* declare variables */
	list_t *newNode;


	/* initialize variables */
	newNode = NULL;


	/* confirm argument is a list */
	if (head == NULL)
		return (NULL);


	/* request memory allocation on heap */
	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
		return (NULL);


	newNode->letter = c;
	newNode->seenFlag = 0;
	newNode->duplicateFlag = 0;

	/* add new node to the beginning of the list */
	newNode->next = *head;
	*head = newNode;


	return (*head);
}
/**
 *
 *
 */
size_t listLen(const list_t *h)
{
	/* declare variables */
	size_t elmCount;

	/* initialize variables */
	elmCount = 0;

	/* count element in the linked list */
	while (h != NULL)
	{
		elmCount++;
		h = h->next;
	}

	return (elmCount);

}
/**
 *
 *
 */
void freeList(list_t *head)
{
	/* declare variables */
	list_t *currentNode;


	/* initialize variable */
	currentNode = NULL;

	if (head)
	{
		while (head != NULL)
		{
			currentNode = head;
			head = head->next;
			free(currentNode);
		}
		free(head);
	}
}
/**
 *
 *
 *
 *
 *
 */
char *DuplicateEncoder(const char *string)
{
	/* declare variables */
	list_t *head, *temp;
	char l, *newStringBuf;
	size_t idx, nodeCount;

	/* initialize variables */
	head = NULL;
	newStringBuf = NULL;
	idx = 0;
	nodeCount = 0;
	l = '\0';
	temp = NULL;

	/* build linked list of characters in original string */
	while (*(string + idx) != '\0')
	{
		l = *(string + idx);
		addNode(&head, l);
		idx++;
	}

	/* convert every character in the string to lower case*/


	/* add info to identify duplicate characters the linked list */
	/* put this in a function call it void tagDuplicates(char *, list_t **) */
	idx = 0;
	temp = head;
	while (*(string + idx) != '\0')
	{
		while (temp != NULL)
		{
			if (temp->letter == *(string + idx))
			{
				if (temp->duplicateFlag != 0)
					break;
				if (temp->seenFlag > 0)
					temp->seenFlag += 1;

				if (temp->seenFlag == 0)
					temp->seenFlag = 1;

				if (temp->seenFlag > 1)
					temp->duplicateFlag = 1;
				printf("temp->letter =%c\n", temp->letter);
				printf("*(string + idx) = %c\n", *(string + idx));
			}
			temp = temp->next;
		}
		temp = head;
		idx++;
	}

	/* put this in a function call it char *buildNewString(list_t *, char *) */
	nodeCount = listLen(head);

	newStringBuf = calloc(nodeCount + 1, sizeof(char));
	if (newStringBuf == NULL)
		return (NULL);

	temp = head;
	idx = 0;
	while (*string != '\0')
	{
		while (temp != NULL)
		{
			if (temp->letter == *string)
			{
				if (temp->duplicateFlag == 1)
					newStringBuf[idx] = ')';
				else
					newStringBuf[idx] = '(';
				break;
			}
			temp = temp->next;
		}
		/* reset to the head of linked list */
		temp = head;

		/* increment loop controls */
		idx++;
		string++;
	}
	newStringBuf[idx] = '\0';


	freeList(head);


	return (newStringBuf);
}
