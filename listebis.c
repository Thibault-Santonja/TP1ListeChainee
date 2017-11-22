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

	next_elem->next = next_elem->next->next; // -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ T'es sur de toi ??? -_-_-_-
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
	return 0;
}


//----------------------------------------------------------

int element_seul (struct List list)
{
    struct element elem = list.tete;
    while (elem.data != 0)
    {
        if (elem.suiv == NULL)
            return 1;
        elem = elem.suiv;
    }
    if (elem.suiv == NULL)
        return 1;
    return 0;
}


char* read_nb (struct element elem)
{
    char* nb = "";
    while (elem.data != 0 && elem.next != NULL)
    {
        nb += elem.data;
    }
    return nb;
}



char* nb_suivant (struct element elem)
{
    char * nb = "";
    while (elem.data != 0)
        elem = elem.next;
    elem = elem.next; // elem est sur la premiere valeur a prendre en compte
    while(elem.data != 0 && elem.next != NULL )
    {
        nb += elem.data;
    }
    return nb;
}


int concatener(struct List liste1, struct List liste2)
{
    liste1.tail = liste2.tete;
}


struct List sort (List *list) --------------------------------------------------------------------------------------
{
    if (element_seul (list) == 1)
        return list;
    else
    {

        List superieurs;
        initialize(superieurs);
        insert_empty_list(superieurs, list.tete.data); // /!\ si pivot prend plusieurs cases !
        // superieurs = pivot; Comment l'initialiser ?
        List inferieurs;
        initialize(inferieurs);
        struct Elem pivot = list.head;
        char * valeur_pivot;
        struct Elem nb_a_comparer = list.head;
        while (nb_a_comparer.tete != list.queue)
        {
            nb_a_comparer = nb_suiv (nb_a_comparer);
            if (compare (nb_a_comparer, valeur_pivot) >= 0)
                insert_nb(nb_a_comparer, superieurs); // nb_a_comparer est un char*, on doit inserer des elements...
            else
                insert_nb(nb_a_comparer, inferieurs);
        }
    }
    struct List liste_triee;

    liste_triee = sort (inferieurs);
    concatener (liste_triee, superieurs);
    list = liste_triee;


	return 0;
} //---------------------------------------------------------------------------------------------------------------------------


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