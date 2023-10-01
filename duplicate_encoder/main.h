#ifndef MAIN_H_
#define MAIN_H_
#include <stdlib.h>
#include <stdio.h>
/**
 * struct list_s - singly linked list
 * @letter: character literal
 * @seenFlag: flag to indicate the letter has been seen
 * @duplicateFlag: flag to indicate the letter has duplicates
 * @next: pointer to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char letter;
	int seenFlag;
	int duplicateFlag;
	struct list_s *next;
} list_t;

char *DuplicateEncoder(const char *string);

#endif /* MAIN_H_ */
