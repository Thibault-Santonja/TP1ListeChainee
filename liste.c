#include "fonctions.h"

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
	int size = size_list (list);	// taile de la liste

	if (size == 0 && p == 1) {		// liste vide
		insert_empty_list (list, str);
		return 1;
	}

	if (p == 0) {					// insertion au début
		insert_begining_list (list, str);
		return 1;
	}

	if (p == size) {				// insertion à la fin
		insert_end_list (list, str);
		return 1;
	}

	while (cmpt < p) {				// recherche de la bonne position
		if (next_elem == NULL)		// si on dépasse la fin de la liste on s'arrete
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
	int cmpt = 1;

	while (cmpt <= p) {		
		next_elem = next_elem->next;
		cmpt++;
	}

	temp = next_elem->next;
	next_elem->next = (next_elem->next)->next;
	free (temp);
}

int remove_ (List *list, int p) {	//"menu" de suppression
	Elem* next_elem = list->head;
	int size = size_list (list);

	if ((next_elem == NULL) || p > size) {			//erreur pas d'element, ou élément à supprimer inexistant
		printf("WARNING: position demandée trop grande !\n");
		return 0;
	}
	else if (size < 2 && p == 1) {		//suppression si un seul élément
		free (list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else if (p == 1)				//suppression du premier élément
		remove_begining (list);
	else if (p == size)				//suppression du dernier élément
		remove_ending (list);
	else if (p < size) 				//sinon suppression en milieu de liste
		remove_inside (list, p);
	else
		return 0;

	return 1;
}


int compare (char *str1, char *str2) {	//vérifie que str1 est plus grand que str2
	int size_number = 0;

	while ((*(str1 + size_number) != '\0') || (*(str2 + size_number) != '\0'))
		size_number++;		// cherche la taille du plus petit nombre

	if ((*(str1 + size_number) != '\0') && (*(str2 + size_number) == '\0'))
		return 1;			// si str2 est le plus petit

	if ((*(str1 + size_number) == '\0') && (*(str2 + size_number) != '\0'))
		return 2;			// si str1 est le plus petit
	
	if ((*(str1 + size_number) == '\0') && (*(str2 + size_number) == '\0'))
		for (int i = 0; i <= size_number; i++) {
			if (*(str1 + i) > *(str2 + i))
				return 1;	// si le chiffre de str1 est plus grand que str2
			if (*(str1 + i) < *(str2 + i))
				return 2;	// si le chiffre de str2 est plus grand que str1
		}

	return 2; //nombres égaux
}


void display (List *list) { //affiche la liste
	Elem* next_elem = list->head;
	int cmpt = 1;
	int i = 0;

	while (next_elem != NULL) {
		printf("\nposition %d : ", cmpt);

		for (i = 0; (*(next_elem->data + i) != '\0'); i++) 
			printf("%c", *(next_elem->data + i));

		next_elem = next_elem->next;
		cmpt++;
	}
	printf("\n");
}



void destruct (List **list) {	//supprime toute la liste
	if ((*list)->head != NULL) {	
		Elem* next_elem = (*list)->head;
		Elem* elem_destroy;

		while (next_elem != NULL) {
			elem_destroy = next_elem;
			next_elem = elem_destroy->next;
			// free (elem_destroy->data); déjà réalisé avec free (elem_destroy);
			free (elem_destroy);
		}

		free (*list);

		*list = NULL;
	}
}


int sort (List *list) {
	int size = size_list(list);

	if (size == 0)
	{
		printf("error:liste.c:sort:pas d'éléments à trier\n");
		return 0;
	}
	if (size == 1)
		return 1; //un seul elemn donc liste triée
	
	int pos = 0;
	Elem* max_elem = list->head;
	Elem* test_elem = max_elem->next;

	for (int i = 1; i <= size; i++) {
		max_elem = list->head;							// on réinitialise max_elem

		for (int k = 1; k < i; k++)
			max_elem = max_elem->next;					// on accéde à la suite de la liste
		test_elem = max_elem->next;						// on réinitialise test_elem

		for (int j = i; j < size; ++j)
		{
			if (compare(test_elem->data, max_elem->data) == 1) {	// on compare avec notre max
				max_elem = test_elem;
				pos = j;								// on garde en mémoire la position de max
			}
			test_elem = test_elem->next;
		}
		insert_begining_list(list, max_elem->data);		// insertion du plus grand au début
		remove_(list, (pos + 1));						// suppresion de l'actuel plus grand
	}
	return 1;
}

/*
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
*/