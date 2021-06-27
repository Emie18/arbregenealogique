#include "projet.h"

//Fonction qui récupère les données du fichier fourni, appelle la fonction pour créer une struture pour stocker ces données puis les stocke dans le tableau de struture donné à l'appel
void initialisation(Person structure[NB_PERSONNES]){

        char ligne [CARACTERE_LIGNE];
        char virgule [2] = ",";
        char *id1, *father_id1, *mother_id1, *lastname, *firstname, *city, *birthdate;
        int id, father_id, mother_id;
        FILE* csv = NULL;

        //ouverture du fichier avec les données
        csv = fopen( "ressources/40.csv", "r");

        for (int i = 0; i<NB_PERSONNES; i++){
        
        //Lecture de la ligne
                fgets(ligne, CARACTERE_LIGNE, csv);
                
                //Pour chaque donnée récupéré, on la range dans la variable temporaire du même type
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
                
                //Convertion des chiffres en int
                id = atoi(id1);
                father_id = atoi(father_id1);
                mother_id = atoi(mother_id1);

                //Affectation des données lu au struct du même rang que la ligne lu
                structure[i] = *initPerson(id, father_id, mother_id, lastname, firstname, birthdate, city);

        }
        //Fermeture du fichier
        fclose(csv);
}

//Fonction pour créer une struture
Person * initPerson(int id, int father_id, int mother_id, char *lastname, char *firstname, char * birthdate, char * city){

        //Allocation de la mémoire nécessaire
        Person *actuel = malloc(sizeof(Person));
        
        //Affectation des données à la structure crée
        actuel->id=id;
        actuel->father_id=father_id ;
        actuel->mother_id=mother_id ;
        strncpy(actuel->lastname, lastname, strlen(lastname));
        strncpy(actuel->firstname, firstname, strlen(firstname));
        strncpy(actuel->birthdate, birthdate, strlen(birthdate));
        strncpy(actuel->city, city, strlen(city));
        
        //renvoie de l'adresse de la struture créé
        return actuel;
}

//Fonction pour associer les adresses des structures des parents à la struture de l'enfant
void parents(Person structure[NB_PERSONNES]){

        int b;
        

        for(int i=0; i<NB_PERSONNES; i++){

                //Récupération du rang du père
                b = structure[i].father_id;

                //Si le rang est de 0, il n'y a pas de père donc pas d'adresse à fournir, renvoi ver NULL
                if(b == 0){

                        structure[i].p_father = NULL;
                
                //Sinon, affectation de l'adresse de la struct au rang récupéré
                }else{

                        structure[i].p_father = &structure[b];

                }
                       
                //Récupération du rang de la mère
                b = structure[i].mother_id;

                //Si le rang est de 0, il n'y a pas de père donc pas d'adresse à fournir, renvoi ver NULL
                if(b == 0){

                        structure[i].p_mother = NULL;

                //Sinon, affectation de l'adresse de la struct au rang récupéré        
                }else{

                        structure[i].p_mother = &structure[b];

                }

        }
}

/*void noms_parents(Person struture[NB_PERSONNES], int enfant, char **nmere, char **pmere, char **npere, char **ppere){

        Person *a = NULL;

        a = struture[enfant].p_mother;
        *pmere = a->firstname;
        *nmere = a->lastname;

        a = struture[enfant].p_father;
        *ppere = a->firstname;
        *npere = a->lastname;

}*/

//Fonction qui récupère le nom des parents
void noms_parents(Person struture[LONGUEUR_MAX], int enfant, char **nmere, char **pmere, char **npere, char **ppere, int *id_mere, int *id_pere){

        Person *a = NULL;
        a = struture[enfant].p_mother;
        
        //S'il n'y a pas de mère, le nom sera "inconnue" et les autres informations seront nulles
        if (a == NULL){

                *pmere = "inconnue";
                *nmere = "";
                *id_mere = 0;

        //Sinon, récupération des information et affectation par paramètre entrée/sortie
        }else{

                *pmere = a->firstname;
                *nmere = a->lastname;
                *id_mere = a->id;

        }
 
        a = struture[enfant].p_father;
        
        //S'il n'y a pas de père, le nom sera "inconnue" et les autres informations seront nulles
        if (a == 0){

                *ppere = "inconnue";
                *npere = "";
                *id_pere = 0;

        //Sinon, récupération des information et affectation par paramètre entrée/sortie        
        }else{

                *ppere = a->firstname;
                *npere = a->lastname;
                *id_pere = a->id ;
        }


  
}
void recherche_par_prenom(Person structure[NB_PERSONNES], char * prenom,char ** nomfichier){
       
       int erreur = 0;
       char * nom;
        for(int i = 0;i<NB_PERSONNES;i++){
                if(strcmp(prenom,structure[i].firstname) == 0){
                        
                        erreur = 1;
                        nom = structure[i].lastname;
                        sprintf(*nomfichier,"fichiers_HTML/%s%s.html",nom,prenom);
                        printf("Merci, je vais vous ouvrir l'arbre généalogique de cette personne tout de suite...\n");
                }
        }
        if (erreur==0){
                printf(ROUGE"Prenom inconnu !( vérifier les Majuscules )\n"NORMAL);
                *nomfichier = "";
        }
}

// int list_nom_famille(Person structure[NB_PERSONNES],char * nom){
//         //char f[TAILLE_MAX];
//         for(int i = 0; i<NB_PERSONNES;i ++){
//                 char *f ;
//                 char *g = structure[i].lastname;
//                 sprintf(f,"%s%s",nom,nom);
//                 sprintf(g"%s%s"g)
//                  if(strcmp(g,nom) == 0){
//                         //printf(BLEUCLAIR"%d:%s,%s\n",structure[i].id,structure[i].firstname,structure[i].lastname, NORMAL);
                        
//                 }else{
//                         printf("%s\n,%s",f,g);
//                 }
//         }
//         // printf("Entrer l'id voulu de la personne :");
//         // char * idtexte;
//         // fgets(idtexte, LONGUEUR_MAX, stdin);
//         // int id = atoi(idtexte);
//         // char * nomfichier;
//         // sprintf(*nomfichier,"fichiers_HTML/%s%s.html",structure[id-1].lastname,structure[id-1].firstname);
//         // ouverture_de_fichier_html(nomfichier);
//         // return 0;

// }
//Fonction qui à pour but de recréer le nomm du fichier contenant l'arbre généalogique de la personne renseigné
void nom_fichier_html(Person structure[NB_PERSONNES], int id, char ** nomfichier){
         char *prenom1;
        char *nom1;
        
        char vide[LONGUEUR_MAX] = "\0";
        int i;
        //décalage du tableau
        id ++;
      
        //Si l'utilisateur à fournis un ID (qui n'est donc pas nul)
        if(id != 0){

                //Le nom du fichier sera "fichiers_HTML+le nom et le prénom contenus dans la structure au rang de l'id donné - 1 (les tableau commencent au rang 0 alors que le fichier commence au rang 0) 
                sprintf(*nomfichier,"fichiers_HTML/%s%s.html",structure[id-1].lastname,structure[id-1].firstname);
                
        
                }else{
                        printf(ROUGE"Désolé, nous n'avons pas pu trouver la personne que vous demandiez...\n"NORMAL);   
                        *nomfichier = "";
                }


}


//Fonction qui ouvre le fichier fournis à l'appel
void ouverture_de_fichier_html(char * nomfichier){
    if(strcmp(nomfichier,"")!= 0){
        char* fichier_ouvrir = malloc(sizeof(char*)*TAILLE_MAX);
        sprintf(fichier_ouvrir,"xdg-open %s",nomfichier);
        system(fichier_ouvrir);  
    }else{
            printf(ROUGE"Nous n'avons pas put ouvrir de fichier"NORMAL);
    }
     

}

//fonction pour créer les balises lien
char *baliselien(char *nom, char *prenom, char *balise)
{
   sprintf(balise, "<a href=\"%s%s.html\">%s %s</a>", nom, prenom, prenom, nom);
   return balise;
}
//fonction pour la création des fichiers HTML dans le dessier fichiers_HTML
void creationhtml(Person structure[NB_PERSONNES])
{
   for (int j = 0; j < NB_PERSONNES; j++)
   {

      char chaine[TAILLE_MAX];

      int i = 0;
      char *prenom = structure[j].firstname;
      char *nom = structure[j].lastname;
      char *date = structure[j].birthdate;
      char *lieux = structure[j].city;

      //parents
      char *prenom_pere;
      char *nom_pere;
      char *prenom_mere;
      char *nom_mere;
      int id_mere;
      int id_pere;
      //variable pour les s'arrêter au grand parent
      int rien;
      //recherche des parents de l'enfant
      noms_parents(structure, j, &nom_mere, &prenom_mere, &nom_pere, &prenom_pere, &id_pere, &id_mere);
      
      //côté père
      char *prenom_grandpere1;
      char *nom_grandpere1;
      char *prenom_grandmere1;
      char *nom_grandmere1;

      //recherche des parents du père
      noms_parents(structure, id_mere, &nom_grandmere1, &prenom_grandmere1, &nom_grandpere1, &prenom_grandpere1, &rien, &rien);
      
      
      //côté mères
      char *prenom_grandpere2;
      char *nom_grandpere2;
      char *prenom_grandmere2;
      char *nom_grandmere2;
      //recherche des parents de la mère
      noms_parents(structure, id_pere, &nom_grandmere2, &prenom_grandmere2, &nom_grandpere2, &prenom_grandpere2, &rien, &rien);
      
      //déclaration des balises
      char balisetitre[TAILLE_MAX];
      char nomfichier[TAILLE_MAX];
      char balisedate[TAILLE_MAX];
      char baliselieux[TAILLE_MAX];
      char balise_lien[TAILLE_MAX];
      //création de la balise date
      sprintf(balisedate, "<span>%s</span>", date); //ligne 51
      //création de la balise lieux de naissance
      sprintf(baliselieux, "<span>%s</span>", lieux); //ligne 54
      //création de la balise nom prenom
      sprintf(balisetitre, "<h2> %s %s </h2>\n", prenom, nom); //ligne 49
      //création du nom du fichier
      sprintf(nomfichier, "fichiers_HTML/%s%s.html", nom, prenom);

      FILE *fp = fopen("test.html", "r");
      FILE *newfp = fopen(nomfichier, "w");
      if (fp != NULL)
      {
         while (fgets(chaine, TAILLE_MAX, fp) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
         {
            i++;
            switch (i)
            {
            case 49:
               fputs(balisetitre, newfp);
               break;
            case 51:
               fputs(balisedate, newfp);
               break;
            case 54:
               fputs(baliselieux, newfp);
               break;
            case 62:
               fputs(baliselien(nom_pere, prenom_pere, balise_lien), newfp);
               break;
            case 65:
               fputs(baliselien(nom_mere, prenom_mere, balise_lien), newfp);
               break;
            case 70:
               fputs(baliselien(nom_grandpere1, prenom_grandpere1, balise_lien), newfp);
               break;
            case 73:
               fputs(baliselien(nom_grandmere1, prenom_grandmere1, balise_lien), newfp);
               break;
            case 76:
               fputs(baliselien(nom_grandpere2, prenom_grandpere2, balise_lien), newfp);
               break;
            case 79:
               fputs(baliselien(nom_grandmere2, prenom_grandmere2, balise_lien), newfp);
               break;
            default:
               fputs(chaine, newfp);
               break;
            }
         }
         fclose(newfp);
         fclose(fp);
      }
   }
}

//Fonction qui permet de rescencer les frères et soeurs de la personne renseigné à l'appel
void frere_soeur(Person structure[NB_PERSONNES], int id, char * prenom){


        char vide[LONGUEUR_MAX] = "\0";
        int i;
        int idmere = 0;
        int idpere = 0;

        //C'est un nom qui à été fournis
        if(strcmp(prenom,vide) != 0){

                for(i = 0; i<NB_PERSONNES; i++){

                        //On recherche la personne qui à le même prénom pour pourvoir récupérer son id et ceux de ses parents
                        if(strcmp(structure[i].firstname, prenom) == 0 ){


                                idmere = structure[i].mother_id;
                                idpere = structure[i].father_id;
                                id = structure[i].id;
                                //break;

                        }

                }
                /*for(i = 0; i<NB_PERSONNES; i++){

                        


                        if(idmere == structure[i].mother_id && idpere == structure[i].father_id){
                                
                                //printf("2.1.1\n");

                                if(structure[i].id != id){

                                        printf("%s %s est un frère/une soeur de %s %s\n", structure[i].firstname, structure[i].lastname, structure[id-1].firstname, structure[id-1].lastname);
                                }

                        }else{if(idmere != structure[i].mother_id && idpere == structure[i].father_id){
                                        printf("2.1.2\n");

                                        printf("%s %s est un beau-frère/une belle-soeur de %s %s du côté paternel\n", structure[i].firstname, structure[i].lastname, structure[id-1].firstname, structure[id-1].lastname);

                        }else{if(idmere == structure[i].mother_id && idpere != structure[i].father_id){
                                        printf("2.1.3\n");

                                        printf("%s %s est un beau-frère/une belle-soeur de %s %s du côté maternel\n", structure[i].firstname, structure[i].lastname, structure[id-1].firstname, structure[id-1].lastname);

                                }
                                //Peut-être rajouter une variable pour savoir si des frêres ou soeurs on été trouvé et si aucun n'a été trouvé, afficher un message particulier ?
                        }
                        }

                }*/
               
        }
        //Si c'est un id qui à été fournis ou si on l'a récupéré à partir de son prénom
        if(id != 0){

                //Si on ne connaît pas encore l'id des parents, on les récupèrent
                if (idmere == 0){
                
                        idmere = structure[id-1].mother_id;
                        idpere = structure[id-1].father_id;

                }


                for(i = 0; i<NB_PERSONNES; i++){

                        //Si la personne que l'on vérifie à les même parents
                        if(idmere == structure[i].mother_id && idpere == structure[i].father_id){

                                //Si la personne que l'on étudie n'est pas la personne dont on veut savoir les frères et soeurs (pour eviter de dire que la personne a est frère de la personne a)
                                if(structure[i].id != id){

                                        printf("%s %s est un frère/une soeur de %s %s\n", structure[i].firstname, structure[i].lastname, structure[id-1].firstname, structure[id-1].lastname);
                                }

                        //Si c'est un beau-frère/une belle-soeur paternel        
                        }else{if(idmere != structure[i].mother_id && idpere == structure[i].father_id){

                                        printf("%s %s est un beau-frère/une belle-soeur de %s %s du côté paternel\n", structure[i].firstname, structure[i].lastname, structure[id-1].firstname, structure[id-1].lastname);

                        //Si c'est un beau-frère/une belle-soeur paternel        
                        }else{if(idmere == structure[i].mother_id && idpere != structure[i].father_id){

                                        printf("%s %s est un beau-frère/une belle-soeur de %s %s du côté maternel\n", structure[i].firstname, structure[i].lastname, structure[id-1].firstname, structure[id-1].lastname);

                                }
                                //Peut-être rajouter une variable pour savoir si des frêres ou soeurs on été trouvé et si aucun n'a été trouvé, afficher un message particulier ?
                        }
                        }

                }
        }



}

/* void libere_structure(Person structure[NB_PERSONNES]){

        //  for(int i = 0; i < NB_PERSONNES; i++){

                 
        //          free(structure[i]);

        //  }
}*/

