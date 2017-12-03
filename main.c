#include "fonctions.h"

static void clean_buffer (void) { //nettoie le buffer si on a saisie trop de caractères
	int c;

	printf("WARNNG: dépassement du nombre de caractères autorisés\n");

	while ((c = getchar()) != '\n' && c != EOF); //EOF = End Of File
}

static void clean_ (char *chaine) // permet de supprimer le retour à la ligne
{
    char *p = strchr(chaine, '\n');

    if (p)
        *p = '\0';
    else {
    	clean_buffer();
    	chaine[MAX] = '\0';
    }
}

static void input_number (char* response) {
	int ret = 0;
	int number = 0;

	do {
		printf ("Saisissez votre nombre : ");
		fgets(response, sizeof response, stdin);
		clean_ (response); //suppression du retour à la ligne OU nettoyage BUFFER
		ret = sscanf(response, "%d", &number);
	} while (ret != 1);

	printf("vous avez saisie : %d\n", number);
}

static int menu (void) {	//static car on ne va pas appeler cette fonction hors de ce fichier
	int flag = 1;
	char response[MAX];
	int place = 0;
	int choix = 0;
	List* ma_liste = NULL;
	int c;

	initialize (&ma_liste);
	
	while (flag) {
		do {	//vérification qu'un choix valide a été fait
			choix = 0;	//RAZ du choix
			printf("que voulez vous faire ?\n");
			printf ("1: voulez vous ajouter un nombre en début de liste ?\n");
			printf ("2: voulez vous ajouter un nombre en fin de liste ?\n");
			printf ("3: voulez vous ajouter un nombre à une certaine position de la liste ?\n");
			printf ("4: voulez vous supprimer un nombre de la liste ?\n");
			printf ("5: voulez vous trier la liste ?\n");
			printf ("6: voulez vous afficher la liste ?\n");
			printf ("7: voulez vous détruire la liste ?\n");
			scanf ("%d", &choix);
			while ((c = getchar()) != '\n' && c != EOF); //EOF = End Of File
		} while ((choix < 1) || (choix > 7));
		
		switch (choix)
		{
			case 1 :
				input_number(response); 
				insert_begining_list(ma_liste, response);
				break;

			case 2 :
				input_number(response);
				insert_end_list(ma_liste, response);
				break;
			
			case 3 :
				input_number(response);
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
				if (!(sort(ma_liste)))
					printf("error:sort\n");
				break;

			case 6 :
				display(ma_liste);
				break;

			case 7 :
				destruct(&ma_liste);
				return 0;
				break;
		}
		printf ("voulez vous continuer ? (oui : 1, non : 0)\n");
		scanf ("%d", &flag);
		choix = 0;	//RAZ du choix
	}
	return 0;
}

int main()
{
	menu ();

	printf("Merci et à bientôt !\n");

	return 0;
}
