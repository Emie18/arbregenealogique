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

void libere_structure(Person *person){

        // Person *temp = NULL;

        // for(int i = 0; i < NB_PERSONNES; i++){

                 
        //         free(&tab[i]);
        // }

        // free(person);
}