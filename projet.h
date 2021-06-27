#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NB_PERSONNES 41
#define LONGUEUR_MAX 30
#define CARACTERE_LIGNE 100
#define TAILLE_MAX 100
#define NB_MAX_ESSAI 5

//la déclaration define permet de mettre des couleurs dans la console
#define BLEUCLAIR "\033[01;34m"
#define ROUGE "\033[00;31m"
#define BLEU "\033[00;34m"
#define SOULIGNE "\033[04m"
#define NORMAL "\033[00m"

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

void initialisation(Person structure[NB_PERSONNES]);

Person * initPerson(int id, int father_id, int mother_id, char *lastname, char *firstname, char * birthdate, char * city);

void parents(Person structure[NB_PERSONNES]);

//void noms_parents(Person struture[NB_PERSONNES], int enfant, char **nmere, char **pmere, char **npere, char **ppere);
void noms_parents(Person struture[LONGUEUR_MAX], int enfant, char **nmere, char **pmere, char **npere, char **ppere, int *id_mere, int *id_pere);

void nom_fichier_html(Person structure[NB_PERSONNES], int id, char ** nomfichier);
void recherche_par_prenom(Person structure[NB_PERSONNES], char * prenom,char ** nomfichier);
//int list_nom_famille(Person structure[NB_PERSONNES],char * nom);

void ouverture_de_fichier_html(char * nomfichier);

void creationhtml(Person structure[NB_PERSONNES]);

char *baliselien(char *nom, char *prenom, char *balise);

void frere_soeur(Person structure[NB_PERSONNES], int id, char * prenom);

void libere_structure(Person structure[NB_PERSONNES]);



