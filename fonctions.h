#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef MAX
#define MAX 10		// nombre max d'elements dans data (structure Elem)
#endif

typedef struct element Elem;
struct element 		// liste chainée de data contenant un nombre
{
	char data[MAX];
	Elem* next;
};

typedef struct list List;
struct list 		// structure gardant en mémoire la tete et queue de la liste
{
	Elem* head;
	Elem* tail;
};

void initialize (List **list);	//** car on modifie la valeur de la liste

void insert_empty_list (List *list, char *str);

void insert_begining_list (List *list, char *str);

void insert_end_list (List *list, char *str);

int insert_after_position (List *list, char *str, int p);

int remove_ (List *list, int p);

int compare (char *str1, char *str2);

int sort (List *list);

void display (List *list);

void destruct (List **list);	//** car on modifie la valeur de la liste

int size_list (List *list);

void remove_begining (List* list);

void remove_inside (List *list, int p);

void remove_ending (List *list);
