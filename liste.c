
void initialize (List* list) {
	Elem* new_elem = malloc(sizeof (Elem));
	new_elem->data = malloc(sizeof ((char) * MAX));
	new_elem->next = NULL;

	list->head = new_elem;
	list->tail = new_elem;
}


void insert_empty_list (List *list, char *str) {

}


void insert_begining_list (List *list, char *str) {

}


void insert_end_list (List *list, char *str) {

}


int insert_after_position (List *list, char *str, int p) {

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
