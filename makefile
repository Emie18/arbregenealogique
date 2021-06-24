projet.exe: main.o fonctions.o
	gcc main.o fonctions.o -o projet.exe
main.o : main.c projet.h
	gcc -c main.c
fonctions.o : fonctions.c projet.h
	gcc -c fonctions.c
clean :
	rm *.o *.exe
