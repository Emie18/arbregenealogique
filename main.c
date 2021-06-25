#include "projet.h"

int main(){

    char ligne [CARACTERE_LIGNE];
    char virgule [2] = ",";
    char *id1, *father_id1, *mother_id1, *lastname, *firstname, *city, *birthdate;
    int id, father_id, mother_id;
    
    Person structure[NB_PERSONNES];


    FILE* csv = NULL;

    
    csv = fopen( "ressources/40.csv", "r");

    for (int i = 0; i<NB_PERSONNES; i++){

        fgets(ligne, CARACTERE_LIGNE, csv);

        for(int j=0; j<7; j++){

        switch(j){

            case 0:

                    id1 = strtok(ligne, virgule);
                    break;

            case 1:

                    father_id1 = strtok(NULL, virgule);
                    break;

            case 2:

                    mother_id1 = strtok(NULL, virgule);
                break;

            case 3:

                    lastname = strtok(NULL, virgule);
                    break;

            case 4:

                    firstname = strtok(NULL, virgule);
                break;

            case 5:

                    
                    birthdate = strtok(NULL, virgule);
                break;

            case 6:

                    city = strtok(NULL, virgule);
                break;
        }

        }
    
        id = atoi(id1);
        father_id = atoi(father_id1);
        mother_id = atoi(mother_id1);

        
        structure[i] = *initPerson(id, father_id, mother_id, lastname, firstname, birthdate, city);

        //printf("%d\n", structure[i].id);

    }

    fclose(csv);

    parents(structure);

    char *nmere = NULL; 
    char pmere[20];
    char npere[20]; 
    char ppere[20];

    noms_parents(structure, 1, nmere, pmere, npere, ppere);

    printf("nom mère : %s\t prénom mère : %s\n", nmere, pmere);
    printf("nom père : %s\t prénom père : %s\n", npere, ppere);





    // printf("%d\n", structure[2].id);
    // printf("%d\n", structure[2].father_id);
    // printf("%d\n", structure[2].mother_id);
    // printf("%s\n", structure[2].lastname);
    // printf("%s\n", structure[2].firstname);
    // printf("%s\n", structure[2].birthdate);
    // printf("%s\n", structure[2].city);
    // printf("%p\n", structure[2].p_father);
    // printf("%p\n", structure[2].p_mother);
    
    //libere_structure(structure);


    return 0;
}