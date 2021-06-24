#include "projet.h"

main(){

    int id, father_id, mother_id, birthdate, birthdate1, birthdate2, birthdate3, birthzipcode;
    char *lastname, firstname;

    FILE* csv = fopen( 'ressources/40.csv', 'r');

    for(int i=0; i<NB_PERSONNES; i++){
        
        fscanf(csv, "%d,%d,%d,%s,%s,%d/%d/%d,%s", &id, &father_id, &mother_id, &lastname, &firstname, &birthdate1, &birthdate2, &birthdate3);

    }    

    fclose(csv);

    return 0;
}