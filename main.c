#include "fonctions.h"

void menu () {
	int flag = 1;
	char* response = malloc (sizeof (char) * MAX);
	int place = 0;
	int choix = 0;
	List* ma_liste = NULL;

	initialize (&ma_liste);
	
	while (flag) {
		choix = 0;	//RAZ du choix
		while ((choix < 1) || (choix > 7))	//vérification qu'un choix valide a été fait
		{
			printf("que voulez vous faire ?\n");
			printf ("1: voulez vous ajouter un nombre en début de liste ?\n");
			printf ("2: voulez vous ajouter un nombre en fin de liste ?\n");
			printf ("3: voulez vous ajouter un nombre à une certaine position de la liste ?\n");
			printf ("4: voulez vous supprimer un nombre de la liste ?\n");
			printf ("5: voulez vous trier la liste ?\n");
			printf ("6: voulez vous afficher la liste ?\n");
			printf ("7: voulez vous détruire la liste ?\n");
			//choix = getchar ();
			scanf("%d", &choix);
			//printf("%d\n", choix);
		}
		switch (choix)
		{
			case 1 :
				printf ("Saisissez votre nombre ?\n");
				scanf ("%s", response);
				insert_begining_list(ma_liste, response);
				break;

			case 2 :
				printf ("Saisissez votre nombre ?\n");
				scanf ("%s", response);
				insert_end_list(ma_liste, response);
				break;
			
			case 3 :
				printf ("Saisissez votre nombre ?\n");
				scanf ("%s", response);
				printf ("Où insérer votre nombre ?\n");
				scanf ("%d", &place);
				if (!insert_after_position(ma_liste, response, place))
					printf("error:insert_after_position\n");
				break;
			
			case 4 :
					printf ("Où supprimer votre nombre ?\n");
					scanf ("%d", &place);
					if (!(remove_(ma_liste, place)))
						printf("error:remove\n");
				break;

			case 5 :
				/* if (!(sort()))
				printf("error:sort\n");*/
				break;

			case 6 :
				display(ma_liste);
				break;

			case 7 :
				/* destruct(ma_liste);*/
				break;
		}
		printf ("voulez vous continuer ? (oui : 1, non : 0)\n");
		scanf ("%d", &flag);
	}
}

int main()
{
	menu ();

	return 0;
}
