#include "projet.h"

Person * initPerson(int id, int father_id, int mother_id, char *lastname, char *firstname, char * birthdate, char * city){

        Person *actuel = malloc(sizeof(Person));

        actuel->id=id;
        actuel->father_id=father_id;
        actuel->mother_id=mother_id;
        strncpy(actuel->lastname, lastname, strlen(lastname));
        strncpy(actuel->firstname, firstname, strlen(firstname));
        strncpy(actuel->birthdate, birthdate, strlen(birthdate));
        strncpy(actuel->city, city, strlen(city));
        
        return actuel;
}
void parents(Person structure[LONGUEUR_MAX]){

        Person *a = NULL;
        int b;
        

        for(int i=0; i<NB_PERSONNES; i++){

                b = structure[i].father_id;
                if(b == 0){

                        structure[i].p_father = NULL;

                }else{

                        structure[i].p_father = &structure[b];

                }
                
                //printf("rang père : %d\t adresse père : %p - ", b, structure[i].p_father);        

                b = structure[i].mother_id;
                if(b == 0){

                        structure[i].p_mother = NULL;
                }else{

                        structure[i].p_mother = &structure[b];

                }

                //printf("rang mère : %d\t adresse mère : %p\n", b, structure[i].p_mother);
                

        }
}

void noms_parents(Person struture[LONGUEUR_MAX], int enfant, char *nmere, char * pmere, char * npere, char * ppere){

        Person *a = NULL;

        a = struture[enfant].p_mother;
        pmere = a->firstname;
        nmere = a->lastname;

        a = struture[enfant].p_father;
        ppere = a->firstname;
        npere = a->lastname;

        printf("nom mère : %s\t prénom mère : %s\n", nmere, pmere);
        printf("nom père : %s\t prénom père : %s\n", npere, ppere);


}

 void libere_structure(Person structure[NB_PERSONNES]){

        //  for(int i = 0; i < NB_PERSONNES; i++){

                 
        //          free(structure[i]);

        //  }
}