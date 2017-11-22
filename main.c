#include "fonctions.h"


int main()
{/*
	Elem* test = malloc (sizeof (Elem));
	test->data = malloc (sizeof (char) * MAX);

	test->data[1] = 'a';

	printf("2. \n");

	printf("test data : %c\n", test->data[1]);

	printf("3. \n");

	free(test->data);
	free(test);

	printf("4. \n");
*/

	int flag = 1;
	char* response = malloc (sizeof (char) * MAX);
	int place = 0;
	List* ma_liste = NULL;

	initialize (ma_liste);

	while (flag) {
		printf ("voulez vous ajouter un nombre en début de liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &flag);
		if (flag) {
			printf ("Saisissez votre nombre ?\n");
			scanf ("%s", response);
			insert_begining_list(ma_liste, response);
		}
		
		printf ("voulez vous ajouter un nombre en fin de liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &flag);
		if (flag) {
			printf ("Saisissez votre nombre ?\n");
			scanf ("%s", response);
			insert_end_list(ma_liste, response);
		}
		
		printf ("voulez vous ajouter un nombre à une certaine position de la liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &flag);
		if (flag) {
			printf ("Saisissez votre nombre ?\n");
			scanf ("%s", response);
			printf ("Où insérer votre nombre ?\n");
			scanf ("%d", &place);
			if (!(insert_after_position(ma_liste, response, place)))
				printf("error:insert_after_position\n");
		}
		
		printf ("voulez vous supprimer un nombre de la liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &flag);
		/*if (flag) {
			printf ("Où supprimer votre nombre ?\n");
			scanf ("%d", &place);
			if (!(remove_()))
				printf("error:remove\n");
		}*/

		printf ("voulez vous trier la liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &flag);
		/*if (flag)
			if (!(sort()))
				printf("error:sort\n");*/
	
		printf ("voulez vous afficher la liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &flag);
		if (flag)
			display(ma_liste);
	
		printf ("voulez vous détruire la liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &flag);
		/*if (flag)
			destruct(ma_liste);*/

		printf ("voulez vous continuer ? (oui : 1, non : 0)\n");
		scanf ("%d", &flag);
	}

	return 0;
}