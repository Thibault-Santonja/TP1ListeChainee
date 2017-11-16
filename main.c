#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


int main(int argc, char const *argv[])
{
	int flag = 1;
	int response = 0;
	int place = 0;

	while (flag) {
		printf ("voulez vous ajouter un nombre en début de liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &response);
		if (response) {
			printf ("Saisissez votre nombre ?\n");
			scanf ("%d", &response);
			insert_begining_list();
		}
		
		printf ("voulez vous ajouter un nombre en fin de liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &response);
		if (response) {
			printf ("Saisissez votre nombre ?\n");
			scanf ("%d", &response);
			insert_end_list();
		}
		
		printf ("voulez vous ajouter un nombre en début de liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &response);
		if (response) {
			printf ("Saisissez votre nombre ?\n");
			scanf ("%d", &response);
			printf ("Où insérer votre nombre ?\n");
			scanf ("%d", &place);
			if (!(insert_after_position()))
				printf("error:insert_after_position\n");
		}
		
		printf ("voulez vous supprimer un nombre de la liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &response);
		if (response) {
			printf ("Où supprimer votre nombre ?\n");
			scanf ("%d", &place);
			if (!(remove()))
				printf("error:remove\n");
		}

		printf ("voulez vous trier la liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &response);
		if (response)
			if (!(sort()))
				printf("error:sort\n");
	
		printf ("voulez vous afficher la liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &response);
		if (response)
			display();
	
		printf ("voulez vous détruire la liste ? (oui : 1, non : 0)\n");
		scanf ("%d", &response);
		if (response)
			destruct();

		printf ("voulez vous quitter le programme ? (oui : 1, non : 0)\n");
		scanf ("%d", &flag);
	}

	return 0;
}