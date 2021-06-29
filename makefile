projet.exe: main.o fonctions.o flancement.o
	gcc -g main.o fonctions.o flancement.o -o projet.exe
main.o : main.c projet.h
	gcc -c main.c
fonctions.o : fonctions.c projet.h
	gcc -c fonctions.c
flancement.o : flancement.c projet.h
	gcc -c flancement.c
clean :
	rm *.o *.exe
