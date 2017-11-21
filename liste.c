#include "fonctions.h"

void initialize (List* list) {
	Elem* new_elem = malloc(sizeof (Elem));
	new_elem->data = malloc(sizeof (char) * MAX);
	new_elem->next = NULL;

	list->head = new_elem;
	list->tail = new_elem;
}


void insert_empty_list (List *list, char *str) {
	if (list->head == list->tail)
		list->head->data = str;

}


void insert_begining_list (List *list, char *str) {
	Elem* new_elem = malloc(sizeof (Elem));

	new_elem->data = str;
	new_elem->next = list->head;
	list->head = new_elem;
}


void insert_end_list (List *list, char *str) {
	Elem* new_elem = malloc(sizeof (Elem));
	Elem* next_elem = list->head;

	while (next_elem != NULL)
		next_elem = next_elem->next;

	next_elem->next = new_elem;

	new_elem->data = str;
	new_elem->next = NULL;
	list->tail = new_elem;

}


int insert_after_position (List *list, char *str, int p) {
	Elem* new_elem = malloc(sizeof (Elem));
	Elem* next_elem = list->head;
	int cmpt = 0;

	while (cmpt < p) {
		if (next_elem == NULL)
			return -1;

		next_elem = next_elem->next;
		cmpt++;
	}

	new_elem->data = str;
	new_elem->next = next_elem->next;
	next_elem->next = new_elem; 

	return 0;
}


int remove_ (List *list, int p) {
	Elem* next_elem = list->head;
	int cmpt = 0;

	while (cmpt < p) {
		if (next_elem == NULL)
			return -1;
		
		next_elem = next_elem->next;
		cmpt++;
	}

	next_elem->next = next_elem->next->next;
	free (next_elem->next->next);

	return 0;
}


int compare (char *str1, char *str2) {
	int i = 1;
	int res = 0;
	unsigned int mult = 1;

	for (; i <= MAX; i++, mult *= 10) 
		res = (str1 [MAX - i] - str2 [MAX - i]) * mult;

	if (res > 0)
		return 1;
	return 2;
}


int sort (List *list) {
	/* TODO */

	return 0;
}


void display (List *list) {
	/* TODO */
}


void destruct (List *list) {
	Elem* next_elem = list->head;
	Elem* elem_destroy;

	while (next_elem != NULL) {
		free (next_elem->data);
		elem_destroy = next_elem;
		next_elem = next_elem->next;
		free (elem_destroy);
	}

	free (list->head);
	free (list->tail);
	free (list);
}
