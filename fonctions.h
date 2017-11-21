#define MAX 10

typedef struct element Elem;
struct element
{
	char* data;
	Elem* next;
};

typedef struct list List;
struct list
{
	Elem* head;
	Elem* tail;
};

void initialize (List *list);

void insert_empty_list (List *list, char *str);

void insert_begining_list (List *list, char *str);

void insert_end_list (List *list, char *str);

int insert_after_position (List *list, char *str, int p);

int remove_ (List *list, int p);

int compare (char *str1, char *str2);

int sort (List *list);

void display (List *list);

void destruct (List *list);
