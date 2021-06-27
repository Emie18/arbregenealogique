#include "projet.h"

int main(){

    Person structure[NB_PERSONNES];
    int action, action1;
    char actionc[LONGUEUR_MAX];
    char action1c[LONGUEUR_MAX];

    char prenom[LONGUEUR_MAX] = "\0";
    char nom[LONGUEUR_MAX] = "\0";
    char prenom1[LONGUEUR_MAX] = "\0";
    char nom1[LONGUEUR_MAX] = "\0";
    char * nomfichier;
    int identifiant = 0;
    char identifiantc[LONGUEUR_MAX];
    int identifiant1 = 0;
    char identifiant1c[LONGUEUR_MAX];
    int longueur;

    srand(time(NULL));

    //Initialisation des données
    initialisation(structure);
    parents(structure);
    creationhtml(structure);

    //char *nmere = NULL; 
    //char *pmere = NULL;
    //char *npere = NULL; 
    //char *ppere = NULL;

    //noms_parents(structure, 1, &nmere, &pmere, &npere, &ppere);

    //printf("nom mère : %s\t prénom mère : %s\n", nmere, pmere);
    //printf("nom père : %s\t prénom père : %s\n", npere, ppere);



    while (1) {

      //affichage du menu
        printf("\n\n===========================================================================\n\n");

        printf("Bonjour, que souhaitez vous faire ?\n\n");

        printf("1. Rechercher une personne par son nom.\n\n");

        printf("2. Rechercher une personne par son prénom.\n\n");

        printf("3. Rechercher une personne par son identifiant (id).\n\n");

        printf("4. Découvrir un arbre généalogique aléatoire.\n\n");

        printf("5. Rechercher les frères et soeurs d'une personne.\n\n");

        printf("\t\t->Si vous voulez stopper le logiciel, tapez 6<-\n");

        printf("\n\n===========================================================================\n");

        //Récupération du choix
        printf("Veuillez renseigner votre choix :\n");
        fgets(actionc, LONGUEUR_MAX, stdin);
        action = atoi(actionc);

        //Vérification du choix est un choix possible
        while(1){

            if(action<1 || action>6){

                printf("Vous n'avez pas renseigné une action valide, veuillez réessayer :\n");
                fgets(actionc, LONGUEUR_MAX, stdin);
                action = atoi(actionc);

            }else{

                break;
            }

        }

        //Choix du code qui va répondre à l'attente de l'utilisateur
        switch(action){

            //Partie utilisant un nom et actuellement inutilisable car il y a plusieurs personnes avec le même nom
            /*case 1:

                Plusieurs personnes ont le même nom donc c'est façon de rechercher n'est pas viable.

                printf("Vous voulez rechercher l'arbre généalogique d'une personne en connaissant son nom.\nQuel est le nom de cette personne :\n");
                fgets(nom, LONGUEUR_MAX, stdin);
                printf("1\n");
                nom_fichier_html(structure, identifiant, prenom, nom);
                printf("0\n");
                printf("Merci, je vais vous ouvrir l'arbre généalogique de cette personne tout de suite...\n");
                */
                break;

            //Si la personne veut un arbre généalogique d'une personne en connaissant son prénom
            case 2:

                printf("Vous voulez rechercher l'arbre généalogique d'une personne en connaissant son prénom.\nQuel est le prénom de cette personne :\n");
                fgets(prenom, LONGUEUR_MAX, stdin);
                longueur = strlen(prenom);
                prenom[(longueur - 1)] = '\0';
                nomfichier = nom_fichier_html(structure, identifiant, prenom, nom);
                printf("Merci, je vais vous ouvrir l'arbre généalogique de cette personne tout de suite...\n");
                ouverture_de_fichier_html(nomfichier);
                break;

            //Si la personne veut un arbre généalogique d'une personne en connaissant son id
            case 3:

                printf("Vous voulez rechercher l'arbre généalogique d'une personne en connaissant son identifiant.\nQuel est l'identifiant de cette personne :\n");
                fgets(identifiantc, LONGUEUR_MAX, stdin);
                identifiant = atoi(identifiantc);

                //Vérification que l'id est un id possible
                while(1){

                    if(identifiant<1 ||identifiant>40){

                        printf("Vous n'avez pas renseigné une action valide, veuillez réessayer :\n");
                        fgets(identifiantc, LONGUEUR_MAX, stdin);
                        identifiant = atoi(identifiantc);

                    }else{

                    break;
                    }

                }
                nomfichier = nom_fichier_html(structure, identifiant, prenom, nom);             
                printf("Merci, je vais vous ouvrir l'arbre généalogique de cette personne tout de suite...\n");
                ouverture_de_fichier_html(nomfichier);

                break;
            //Si la personne veut un arbre généalogique d'une personne aléatoire
            case 4:

                printf("Vous voulez rechercher l'arbre généalogique d'une personne aléatoire.\n");
                identifiant = rand()%NB_PERSONNES;
                nomfichier = nom_fichier_html(structure, identifiant, prenom, nom);
                printf("%s\n", nomfichier);
                printf("Je vais vous ouvrir ça tout de suite...\n");
                ouverture_de_fichier_html(nomfichier);

                break;
            //Si la personne veut connaître les frères et soeurs d'une personne
            case 5:

                printf("Vous voulez rechercher les frères et soeurs d'une personne.\n\n");
                printf("Comment voulez vous rechercher cette personne ?\n\n");
                printf("1. Rechercher par son nom.\n\n");
                printf("2. Rechercher par son prénom.\n\n");
                printf("3. Rechercher par son identifiant (id)\n\n");
                printf("Veuillez renseigner votre choix :\n");
                fgets(action1c, LONGUEUR_MAX, stdin);
                action1 = atoi(action1c);
                
                //Vérification que le choix est un choix possible
                while(1){ 

                    if(action1<1 || action1>3){

                        printf("Vous n'avez pas renseigné une action valide, veuillez réessayer :\n");
                        fgets(action1c, LONGUEUR_MAX, stdin);
                        action1 = atoi(action1c);
            
                    }else{

                        break;
                    }

                }

                //Choix du code qui va répondre à l'attente de l'utilisateur
                switch (action1){

                    //Partie utilisant un nom et actuellement inutilisable car il y a plusieurs personnes avec le même nom
                    /*case 1:

                        Même problème que pour la recherche d'arbre généalogique par nom.
                        
                        printf("Vous voulez rechercher les frères et soeurs d'une personne en connaissant son nom.\nQuel est le nom de cette personne :\n");
                        fgets(nom1, LONGUEUR_MAX, stdin);
                        longueur = strlen(nom1);
                        nom1[(longueur - 1)] = '\0';
                        */
                        break;

                    //Si la personne veut les frères et soeurs d'une personne en connaissant son prénom
                    case 2:

                        printf("Vous voulez rechercher les frères et soeurs d'une personne en connaissant son prénom.\nQuel est le prénom de cette personne :\n");
                        fgets(prenom1, LONGUEUR_MAX, stdin);
                        longueur = strlen(prenom1);
                        prenom1[(longueur - 1)] = '\0';
                        frere_soeur(structure, identifiant1, prenom1);

                        //printf("Merci, je vais vous ouvrir l'arbre généalogique de cette personne tout de suite...\n");

                        break;

                    //Si la personne veut les frères et soeurs d'une personne en connaissant son prénom
                    case 3:

                        printf("Vous voulez rechercher les frères et soeurs d'une personne en connaissant son identifiant.\nQuel est l'identifiant de cette personne :\n");
                        fgets(identifiant1c, LONGUEUR_MAX, stdin);
                        identifiant1 = atoi(identifiant1c);

                    //Vérification que l'id est un id possible
                        while(1){

                            if(identifiant1<1 ||identifiant1>40){

                                printf("Vous n'avez pas renseigné une action valide, veuillez réessayer :\n");
                                fgets(identifiant1c, LONGUEUR_MAX, stdin);
                                identifiant1 = atoi(identifiant1c);

                            }else{

                            break;
                            }

                        }

                        frere_soeur(structure, identifiant1, prenom1);
                        //printf("Merci, je vais vous ouvrir l'arbre généalogique de cette personne tout de suite...\n");

                        break;

                    
                }

            case 6:

                break;
           
        }

        if(action == 6){
            
            break;
        }
    }

    //  printf("%d\n", structure[2].id);
    //  printf("%d\n", structure[2].father_id);
    //  printf("%d\n", structure[2].mother_id);
    //  printf("%s\n", structure[2].lastname);
    //  printf("%s\n", structure[2].firstname);
    //  printf("%s\n", structure[2].birthdate);
    //  printf("%s\n", structure[2].city);
    //  printf("%p\n", structure[2].p_father);
    //  printf("%p\n", structure[2].p_mother);
    
    //libere_structure(structure);

    
    return 0;
}
