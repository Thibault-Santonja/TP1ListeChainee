#include "fonctions.h"
//#include "quicksort.c"

void initialize (List** list) {	// création d'une structure avec les pointeurs sur la tete et la queue de la liste
	(*list) = malloc(sizeof (List));
	(*list)->head = NULL;		// pas d'éléments donc initialisation à NULL
	(*list)->tail = NULL;
}


void insert_empty_list (List* list, char *str) {	//insertion dans une liste vide
	Elem* new_elem = malloc (sizeof (Elem));
	strcpy(new_elem->data, str);
	list->head = new_elem;							// seul élément de la liste donc la tete et la queue pointent sur cet élement
	list->tail = new_elem;
}


void insert_begining_list (List *list, char *str) {		// insertion en début de liste
	if (list->head == NULL)							// test si la liste est vide
		insert_empty_list(list, str);
	else {
		Elem* new_elem = malloc (sizeof (Elem));
		strcpy (new_elem->data, str);

		new_elem->next = list->head;
		list->head = new_elem;
	}
}

void insert_end_list (List *list, char *str) {		// insertion en fin de liste
	if (list->tail == NULL)						// test si la liste est vide
		insert_empty_list(list, str);
	else {
		Elem* tmp = list->tail;
		Elem* new_elem = malloc (sizeof (Elem));
		strcpy (new_elem->data, str);

		new_elem->next = NULL;
		tmp->next = new_elem;
		list->tail = new_elem;
	}
}

int size_list (List *list) {		// renvoie la taille de la liste
	int cmpt = 0;
	Elem* next_elem = list->head;

	while (next_elem != NULL) {
		next_elem = next_elem->next;
		cmpt++;
	}

	return cmpt;
}

int insert_after_position (List *list, char *str, int p) {	// insertion de str après la position p
	Elem* new_elem = malloc(sizeof (Elem));
	Elem* next_elem = list->head;
	int cmpt = 0;
	int size = size_list (list);

	if (size == 0) {
		insert_empty_list (list, str);
		return 1;
	}

	if (p == 0) {
		insert_begining_list (list, str);
		return 1;
	}

	if (p == size) {
		insert_end_list (list, str);
		return 1;
	}

	while (cmpt < p) {
		if (next_elem == NULL)
			return 0;

		next_elem = next_elem->next;
		cmpt++;
	}


	strcpy(new_elem->data, str);
	new_elem->next = next_elem->next;
	next_elem->next = new_elem; 

	return 1;
}

void remove_begining (List* list) {	//suppression début de liste
	Elem* next_elem = list->head;
	Elem* temp = NULL;

	temp = next_elem->next;
	free(list->head);
	list->head = temp;
}

void remove_ending (List *list) {	//suppression fin de liste
	Elem* next_elem = list->head;
	Elem* temp = NULL;

	while (next_elem->next != NULL) {
		temp = next_elem;
		next_elem = next_elem->next;
	}

	temp->next = NULL;
	list->tail = temp;
	free (next_elem);
}

void remove_inside (List *list, int p) {	//suppression dans la liste
	Elem* next_elem = list->head;
	Elem* temp = NULL;
	int cmpt = 0;

	while (cmpt < p) {		
		next_elem = next_elem->next;
		cmpt++;
	}

	temp = next_elem->next;
	next_elem->next = (next_elem->next)->next;
	free (temp);
}

int remove_ (List *list, int p) {	//"menu" de suppression
	Elem* next_elem = list->head;

	if ((next_elem == NULL) || p > size_list(list))			//erreur pas d'element, ou élément à supprimer inexistant
		return 0;
	else if (size_list < 2) {		//suppression si un seul élément
		free (list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else if (p == 0)				//suppression du premier élément
		remove_begining (list);
	else if (p == size_list (list))	//suppression du dernier élément
		remove_ending (list);
	else 							//sinon suppression en milieu de liste
		remove_inside (list, p);

	return 1;
}


int compare (char *str1, char *str2) {	//vérifie que str1 est plus grand que str2
	int i = 1;
	int res = 0;
	unsigned int mult = 1;

	for (; i <= MAX; i++, mult *= 10) 
		res = (str1 [MAX - i] - str2 [MAX - i]) * mult;

	if (res > 0)
		return 1;
	return 0;
}


void display (List *list) { //affiche la liste
	Elem* next_elem = list->head;
	int cmpt = 1;

	while (next_elem != NULL) {
		printf("position %d : %d\n", cmpt, next_elem->data[cmpt - 1]);
		next_elem = next_elem->next;
		cmpt++;
	}
}


void destruct (List *list) {	//supprime toute la liste

	/* TO DO */

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



int element_seul (List list)
{
    Elem elem = list.tete;
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


char* read_nb (Elem elem)
{
    char* nb = "";
    while (elem.data != 0 && elem.next != NULL)
    {
        nb += elem.data;
    }
    return nb;
}



char* nb_suivant (Elem elem)
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


int concatener(List liste1, List liste2)
{
    liste1.tail = liste2.tete;
}


List sort (List *list) //--------------------------------------------------------------------------------------
{
    if (Elem_seul (list) == 1)
        return list;
    else
    {

        List superieurs;
        initialize(superieurs);
        insert_empty_list(superieurs, list.tete.data); // /!\ si pivot prend plusieurs cases !
        // superieurs = pivot; Comment l'initialiser ?
        List inferieurs;
        initialize(inferieurs);
        Elem pivot = list.head;
        char * valeur_pivot;
        Elem nb_a_comparer = list.head;
        while (nb_a_comparer.tete != list.queue)
        {
            nb_a_comparer = nb_suiv (nb_a_comparer);
            if (compare (nb_a_comparer, valeur_pivot) >= 0)
                insert_nb(nb_a_comparer, superieurs); // nb_a_comparer est un char*, on doit inserer des Elems...
            else
                insert_nb(nb_a_comparer, inferieurs);
        }
    }
    List liste_triee;

    liste_triee = sort (inferieurs);
    concatener (liste_triee, superieurs);
    list = liste_triee;


	return 0;
} //---------------------------------------------------------------------------------------------------------------------------
