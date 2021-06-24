#include "projet.h"

int main(){

    char ligne [NB_PERSONNES];
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

        printf("%d", structure[i].id);

    }

    fclose(csv);

    return 0;
}