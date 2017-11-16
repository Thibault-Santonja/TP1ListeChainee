
void initialize (List* list) {
	Elem* new_elem = malloc(sizeof (Elem));
	new_elem->data = malloc(sizeof ((char) * MAX));
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
	new_elem->next = list->NULL;
	list->tail = new_elem;

}


int insert_after_position (List *list, char *str, int p) {
	Elem* new_elem = malloc(sizeof (Elem));
	Elem* next_elem = list->head;
	int cmpt = 0;

	while (cmpt < p) {
		next_elem = next_elem->next;
		cmpt++;
	}

	new_elem->data = str;
	new_elem->next = next_elem->next;
	next_elem->next = new_elem; 
}


int remove (List *list, int p) {

}


int compare (char *str1, char *str2) {

}


int sort (List *list) {

}


void display (List *list) {

}


void destruct (List *list) {

}
