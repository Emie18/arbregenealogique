void frere_soeur(Person structure[NB_PERSONNES], int id, char * prenom){


    char vide[LONGUEUR_MAX] = "\0";
    int i;
    int idmere = 0;
    int idpere = 0;
    int n = 0;

    //C'est un nom qui à été fournis
    if(strcmp(prenom,vide) != 0){

        for(i = 0; i<NB_PERSONNES; i++){

            //On recherche la personne qui à le même prénom pour pourvoir récupérer son id et ceux de ses parents
            if(strcmp(structure[i].firstname, prenom) == 0 ){


                idmere = structure[i].mother_id;
                idpere = structure[i].father_id;
                id = structure[i].id;
            }
        }                    
    }
    //Si c'est un id qui à été fournis ou si on l'a récupéré à partir de son prénom
    if(id != 0){

        //Si on ne connaît pas encore l'id des parents, on les récupèrent
        if (idmere == 0 && idpere == 0){
                        
            idmere = structure[id].mother_id;
            idpere = structure[id].father_id;
        }

        for(i = 1; i<NB_PERSONNES; i++){

            //Si la personne que l'on vérifie à les même parents
            if(idmere == structure[i].mother_id && idpere == structure[i].father_id && idmere != 0 && idpere != 0){

                //Si la personne que l'on étudie n'est pas la personne dont on veut savoir les frères et soeurs (pour eviter de dire que la personne a est frère de la personne a)
                if(structure[i].id != id){

                    printf("%s %s est un frère/une soeur de %s %s\n", structure[i].firstname, structure[i].lastname, structure[id].firstname, structure[id].lastname);
                    n++;
                }

            //Si c'est un beau-frère/une belle-soeur paternel        
            }else{if(idmere != structure[i].mother_id && idpere == structure[i].father_id && idpere != 0){

                printf("%s %s est un demi-frère/une demie-soeur de %s %s du côté paternel\n", structure[i].firstname, structure[i].lastname, structure[id].firstname, structure[id].lastname);
                n++;

            //Si c'est un beau-frère/une belle-soeur paternel        
            }else{if(idmere == structure[i].mother_id && idpere != structure[i].father_id && idmere != 0){

                printf("%s %s est un demi-frère/une demie-soeur de %s %s du côté maternel\n", structure[i].firstname, structure[i].lastname, structure[id].firstname, structure[id].lastname);
                n++;
                }
            }
            }
        }
    
        if(n == 0){

            printf("Cette personne n'a pas de frère ni de soeurs\n");

        }
    }



}
