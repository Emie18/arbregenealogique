#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{
    int id;
    int father_id;
    int mother_id;
    char lastname[20];
    char firstname[20];
    int birthdate;
    int birthzipcode;
    struct Person * p_father;
    struct Person * p_mother;
}person;

initPerson(int id, int father_id, int mother_id, char *lastname, char *firstname, int birthdate, int birthzipcode);

