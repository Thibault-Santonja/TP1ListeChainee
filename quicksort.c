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
    	if (i==nbchiffres1) 
            return 1; 
        else if (*(str1+i) > *(str2+i)) 
            return 1;
        else 
            return 2;
    }
    else if (nbchiffres1 > nbchiffres2)	
        return 1;
    return 2;
}

int sort (List *list)
{
    if (list->head==NULL) 
        return -1;
    if(size_list(list)==1) 
        return 0;

    struct element *lecteur;
    struct element *finPivot;
    struct element *debutPivot;
    struct element *mem;
    struct element *mem2;

    List *leftList; 
    initialize(&leftList);
    List *rightList; 
    initialize(&rightList);

    int i=1; 
    int j=0; 
    int flagLeft=0; 
    int flagRight=0; 
    int k; 
    int l=0;

    char strPivot [IN]; 
    char str2 [IN];

    debutPivot=list->tail;
    lecteur=list->tail;

    while(*(lecteur->data)!='\0')
    {
        *(strPivot+l)=*(lecteur->data+j);
        j++;
        l++;
        if(j==N)
        {
            j=0;
            lecteur=lecteur->next;
        }
    }

    *(strPivot+l)='\0';
    j=0;
    l=0;
    finPivot=lecteur;
    lecteur=list->head; 
    mem=list->tail;
    
    while(lecteur!=mem)
    {
        mem2=lecteur;
        k=0; 
        memset(str2, '\0', N);
        while(*(lecteur->data)!='\0') 
        {
            if(*(lecteur->data+j)>='0' && *(lecteur->data+j)<='9')
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
        if (*(lecteur->data)=='\0') 
        {
            *(str2+l)='\0';
            k=compare(strPivot, str2); 
            lecteur=lecteur->next;
            switch (k) 
            {
                case 1:
                    leftList->tail=mem2;
                    if(flagLeft==0)
                    {
                        leftList->head=list->head;
                        flagLeft=1;
                    }

                    j=0;
                    l=0;
                    break;
                case 2:
                    remove_element(&list, i);
                    printf("str2= %s\n", str2);
                    insert_end_list(list, str2);
                    rightList->tail=list->tail; 
                    if(flagRight==0) 
                    {
                        rightList->head=rightList->tail;
                        flagRight=1;
                    }

                    j=0;
                    l=0;
                    i--; 
                    break;
            }
            i++;
        }
    }
    if (leftList->head!=NULL) 
    {
        lecteur=leftList->tail; 
        while(*(lecteur->data)!='\0')lecteur=lecteur->next;
        lecteur->next=NULL;

        sort(leftList);
        lecteur=leftList->tail;
        while(lecteur->next!=NULL)lecteur=lecteur->next;
        lecteur->next=debutPivot;
        list->head=leftList->head; 
    }
    if (rightList->head!=NULL) 
    {
        sort(rightList);
        finPivot->next=rightList->head; 
        list->tail=rightList->tail;
    }

    free(rightList);
    free(leftList);
    return 0;
}