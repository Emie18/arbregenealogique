#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB_PERSONNES 40
#define LONGUEUR_MAX 20
#define CARACTERE_LIGNE 100

typedef struct Person Person; 

struct Person{
    int id;
    int father_id;
    int mother_id;
    char lastname[LONGUEUR_MAX];
    char firstname[LONGUEUR_MAX];
    char birthdate[LONGUEUR_MAX];
    char city[LONGUEUR_MAX];
    struct Person * p_father;
    struct Person * p_mother;
};


Person * initPerson(int id, int father_id, int mother_id, char *lastname, char *firstname, char * birthdate, char * city);

void parents(Person structure[LONGUEUR_MAX]);

void noms_parents(Person struture[LONGUEUR_MAX], int enfant, char *nmere, char * pmere, char * npere, char * ppere);

void libere_structure(Person structure[NB_PERSONNES]);



