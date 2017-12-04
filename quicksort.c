//---------------------------------
//  Comparaison des 2 nombres en paramètre
//  Retourne 1 si str1>str2
//  Retourne 2 si str2>str1
//---------------------------------
int compare(char *str1, char *str2)
{
    int nbchiffres1,nbchiffres2,i=0;

	for(nbchiffres1=0; *(str1+nbchiffres1)!='\n' && *(str1+nbchiffres1)!='\0'; nbchiffres1++);
    for(nbchiffres2=0; *(str2+nbchiffres2)!='\n' && *(str2+nbchiffres2)!='\0'; nbchiffres2++);
    if(nbchiffres1==nbchiffres2)
    {
    	while (*(str1+i) == *(str2+i) && *(str1+i)!='\0')
    	{
    		i++;
    	}
    	if (i==nbchiffres1) return 1; // Les deux nombres sont égaux
        else if (*(str1+i) > *(str2+i)) return 1;
        else return 2;
    }
    else if (nbchiffres1 > nbchiffres2)	return 1;
    return 2;
}


//---------------------------------
//  Tri par ordre croissant les nombres de la liste
//  Retourne 0 si OK
//  Retourne -1 si KO
//---------------------------------
int sort (List *list)
{
    if (list->head==NULL) return -1;
    if(size_list(list)==1) return 0;
    //############
    //Variables
    //############
    struct element *lecteur;
    struct element *finPivot;
    struct element *debutPivot;
    struct element *mem;
    struct element *mem2;
    List *leftList; //Liste gauche
    initialize(&leftList);
    List *rightList; //Liste Droite
    initialize(&rightList);
    int i=1; //Le i-ème élément de la liste;
    int j=0; //Compteur sur Element->data
    int flagLeft=0; //Event premier ELement liste gauche
    int flagRight=0; //Event premier Element liste droite
    int k; //Comparaison par le pivot
    int l=0; // Compteur sur Str2
    char strPivot [IN]; //STRING du pivot
    char str2 [IN]; //String du nombre comparé
    debutPivot=list->tail;
    lecteur=list->tail;
    while(*(lecteur->data)!='\0') //Lecture du pivot
    {
        *(strPivot+l)=*(lecteur->data+j);
        j++;
        l++;
        if(j==N) //On réinitialise à la fin de ELement->data
        {
            j=0;
            lecteur=lecteur->next;
        }
    }
    *(strPivot+l)='\0'; //-> Ajout du \0 pour l'insertion
    j=0;
    l=0;
    finPivot=lecteur; //Permet d'avoir l'élément vide \0 du pivot, pour le raccordement ultérieur
    //############
    //Construction des sous-listes
    //############
    lecteur=list->head; //On remet le lecteur au début
    mem=list->tail; //On garde en mémoire le pivot, vu que list->tail change au fur et à mesure
    while(lecteur!=mem)
    {
        mem2=lecteur;// On garde en mémoire l'adresse du premier élément du nombre
        k=0; //on réinitialise le compare -> Peu utile
        memset(str2, '\0', N);
        while(*(lecteur->data)!='\0') // Parcours d'un nombre sur plusieurs éléments
        {
            if(*(lecteur->data+j)>='0' && *(lecteur->data+j)<='9') //Permet de ne garder que les chiffres -> Peu utile ici
            {
                *(str2+l)=*(lecteur->data+j);
                l++;
            }
            j++;
            if(j==N)
            {
                j=0;
                lecteur=lecteur->next;
            }
        }
        if (*(lecteur->data)=='\0') // On est arrivé à l'élément \0
        {
            *(str2+l)='\0'; // On concaten le \0
            k=compare(strPivot, str2); //On fait la Comparaison
            lecteur=lecteur->next; //On fait passer le lecteur au numéro suivant
            switch (k) //On choisit dans quelle sous-liste on place le nombre
            {
                case 1://Le nombre est placé à gauche du pivot: on ne le bouge donc pas
                    leftList->tail=mem2;// La queue de la liste Gauche est placé sur l'élément
                    if(flagLeft==0) // SI la liste était vide, on initialise la tête -> Peut être remplacé par leftList->head==NULL
                    {
                        leftList->head=list->head;
                        flagLeft=1;
                    }
                    //on réinitialise les compteurs de caractères
                    j=0;
                    l=0;
                    break;
                case 2: //Le nombre est placé à droite du pivot : On supprime donc le nombre à gauche et on le réinsert
                    remove_element(&list, i);
                    printf("str2= %s\n", str2);
                    insert_end_list(list, str2);
                    rightList->tail=list->tail; // On place la tail de la liste droite
                    if(flagRight==0) // Si liste vide, on place la tête sur le premier nombre mis dedans
                    {
                        rightList->head=rightList->tail;
                        flagRight=1;
                    }
                    //on réinitialise les compteurs de caractères
                    j=0;
                    l=0;
                    i--; // Vu qu'on a enlevé un nombre à gauche, on décrémente le compteur d'emplacement
                    break;
            }
            i++; // On passe au nombre suivant, au incrémente le compteur d'emplacement
        }
    }
    if (leftList->head!=NULL) // On vérifie que la liste de gauche n'est pas vide pour faire le rappel sur la fonction
    {
        lecteur=leftList->tail; // On place le lecteur sur le dernier nombre de la liste, pour couper à la fin du nombre
        while(*(lecteur->data)!='\0')lecteur=lecteur->next;
        lecteur->next=NULL;
        //Edition de liens;
        sort(leftList); //Appel récursif
        lecteur=leftList->tail; //Idem que précédemment, mais le tail a changé
        while(lecteur->next!=NULL)lecteur=lecteur->next;
        lecteur->next=debutPivot; // On raccorde la liste Gauche nouvellement triée au pivot
        list->head=leftList->head; //On place la tête de liste sur la nouvelle tête de liste Gauche
    }
    if (rightList->head!=NULL) // Condition pour l'appel récursif sur la liste droite
    {
        sort(rightList);
        finPivot->next=rightList->head; // On raccorde le début de la liste droite aub dernier maillon du pivot
        list->tail=rightList->tail;// On place la queue de la liste sur la la queue de la liste droite
    }
    // On libère les espaces mémoires
    free(rightList);
    free(leftList);
    return 0;
}