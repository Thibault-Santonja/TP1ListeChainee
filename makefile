main : main.o liste.o
	gcc -o TP1_liste_chainee main.o liste.o

main.o : main.c
	gcc -o main.o -c main.c -w -wall

liste.o : liste.c fonction.h
	gcc -o liste.o -c liste.c -w -wall

clean : 
	rm -rf *.o