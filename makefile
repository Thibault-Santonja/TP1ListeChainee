TP1_liste_chainee : main.o liste.o
	gcc -o TP1_liste_chainee main.o liste.o

main.o : main.c
	gcc -o main.o -c main.c -W -Wall

liste.o : liste.c fonctions.h
	gcc -o liste.o -c liste.c -W -Wall

clean : 
	@rm -rf *.o
