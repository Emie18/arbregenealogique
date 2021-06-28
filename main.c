/*----------------------------
    Projet de fin d'année CIR 1
    Nom projet : 
                Arbre genealogique
    Auteurs:
            Matthis Miaud 
                    et 
            Emilie Le Rouzic

    nom du fichier : Main.c
    date : Juin 2021
------------------------------*/
#include "projet.h"

int main()
{

    Person structure[NB_PERSONNES];
    int action, action1;
    //variable qui contient les entrées de l'utilisateur
    char texte[LONGUEUR_MAX] = "\0";
    char *nomfichier = malloc(sizeof(char *) * 20);
    int identifiant = 0;
    int longueur;
    //varible pour attrendre une action de l'utilisateur
    char *rien = malloc(sizeof(char *) * 20);
    srand(time(NULL));
    
     
    //Initialisation des données
    initialisation(structure);
    parents(structure);
    creationhtml(structure);

    //variable pour compter le nombre d'erreur de l'utilisateur
    int nombre_essai = 0;
    while (1)
    {
        action =menu_principal();
        if(!action){
            return 0;
        }
        
        //Choix du code qui va répondre à l'attente de l'utilisateur
        switch (action)
        {

        //Partie utilisant un nom et actuellement inutilisable car il y a plusieurs personnes avec le même nom
         case 1:

            list(structure);
            recherche_nom(structure);
            //attente d'une action de l'utilisateur
            printf(BLEUCLAIR"\nTaper sur Entrer pour retourner au menu :\n"NORMAL);
            if(fgets(rien,LONGUEUR_MAX,stdin));{
                break;
            }

             break;
        //recherche par nom de Famille
        case 2 :

            recherche_nom(structure);
            //attente d'une action de l'utilisateur
            printf(BLEUCLAIR"\nTaper sur Entrer pour retourner au menu :\n"NORMAL);
            if(fgets(rien,LONGUEUR_MAX,stdin));{
                break;
            }


        //Si la personne veut un arbre généalogique d'une personne en connaissant son prénom
        case 3:

            printf("Vous voulez rechercher l'arbre généalogique d'une personne en connaissant son prénom.\n");
            printf(SOULIGNE"Quel est le prénom de cette personne :\n"NORMAL);

            fgets(texte, LONGUEUR_MAX, stdin);
            longueur = strlen(texte);
            texte[(longueur - 1)] = '\0';

            recherche_par_prenom(structure, texte, &nomfichier);
            ouverture_de_fichier_html(nomfichier);

            //attente d'une action de l'utilisateur
            printf(BLEUCLAIR"\nTaper sur Entrer pour retourner au menu :\n"NORMAL);
            if(fgets(rien,LONGUEUR_MAX,stdin));{
                break;
            }
            

        //Si la personne veut un arbre généalogique d'une personne en connaissant son id
        case 4:

            printf("\nVous voulez rechercher l'arbre généalogique d'une personne en connaissant son identifiant.\n");
            printf(SOULIGNE"Quel est l'identifiant de cette personne :\n" NORMAL);
            fgets(texte, LONGUEUR_MAX, stdin);
            identifiant = atoi(texte);
            nombre_essai = 0;
            //Vérification que l'id est un id possible
            while (1)
            {

                if (identifiant < 1 || identifiant > NB_PERSONNES-1)
                {

                    printf(ROUGE "Vous n'avez pas renseigné une action valide, veuillez réessayer :\n");
                    printf("vérifier qui l'id est combre entre%s%s 1 et %d %s:\n",SOULIGNE,BLEUCLAIR, NB_PERSONNES-1, NORMAL);
                    fgets(texte, LONGUEUR_MAX, stdin);
                    identifiant = atoi(texte);
                    nombre_essai++;
                    if (nombre_essai == NB_MAX_ESSAI)
                    {
                        printf(ROUGE SOULIGNE"Nombre d'essai dépassés\n" NORMAL);
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            
            nom_fichier_html(structure, identifiant, &nomfichier);
            ouverture_de_fichier_html(nomfichier);

            //attente d'une action de l'utilisateur
            printf(BLEUCLAIR"\nTaper sur Entrer pour retourner au menu :\n"NORMAL);
            if(fgets(rien,LONGUEUR_MAX,stdin));{
                break;
            }
        //Si la personne veut un arbre généalogique d'une personne aléatoire
        case 5:

            printf("Vous voulez rechercher l'arbre généalogique d'une personne aléatoire.\n");
            identifiant = rand() % NB_PERSONNES;
            nom_fichier_html(structure, identifiant, &nomfichier);
            ouverture_de_fichier_html(nomfichier);
            //attente d'une action de l'utilisateur
            printf(BLEUCLAIR"\nTaper sur Entrer pour retourner au menu :\n"NORMAL);
            if(fgets(rien,LONGUEUR_MAX,stdin));{
                break;
            }
        //Si la personne veut connaître les frères et soeurs d'une personne
        case 6:
            
            action1 = menu2_fratrie();
            switch_fratrie(action1, structure);

            //attente d'une action de l'utilisateur
            printf(BLEUCLAIR"\nTaper sur Entrer pour retourner au menu :\n"NORMAL);
            if(fgets(rien,LONGUEUR_MAX,stdin));{
                break;
            }

        case 7:

            break;
        }

        if (action == 7)
        {

        //libere_structure(structure);
       
            break;
        }

    }
  


    return 0;
}
