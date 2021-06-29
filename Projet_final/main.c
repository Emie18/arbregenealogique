/*----------------------------
    Projet de fin d'année CIR 1
    Nom projet : 
                Arbre genealogique
    Auteurs:
            Matthis Miaud 
                    et 
            Emilie Le Rouzic

    nom du fichier : main.c
    date : Juin 2021
------------------------------*/
#include "projet.h"

//fonctoin principale
int main()
{
    //déclaration du tableau de structure
    Person structure[NB_PERSONNES];
    //variables qui contiennent les actions choisies (pour les switch)
    int action, action1;
    //variable qui contient les entrées de l'utilisateur
    char texte[LONGUEUR_MAX] = "\0";

    char *nomfichier = malloc(sizeof(char *) * 20);
    int identifiant = 0;

    //varible pour attrendre une action de l'utilisateur
    char *rien = malloc(sizeof(char *) * 20);
    srand(time(NULL));

    //Initialisation des données
    initialisation(structure);
    parents(structure);
    creationhtml(structure);

    //variable pour compter le nombre d'erreur de l'utilisateur dans les saisies
    int nombre_essai = 0;
    while (1)
    {
        //appel au menu principale qui renvoit l'action voulu
        action = menu_principal();

        //si action = 0 ça veux dire l'utilisateur à fait trop de mauvaise saisies
        //donc on sort du programme.
        if (!action)
        {
            return 0;
        }

        //Choix du code qui va répondre à l'attente de l'utilisateur
        switch (action)
        {

            //Afficher la liste de toutes les personnes connues
        case 1:

            list(structure);
            //attente d'une action de l'utilisateur
            printf(BLEUCLAIR "\nTapez sur Entrer pour retourner au menu :\n" NORMAL);
            if (fgets(rien, LONGUEUR_MAX, stdin))
            {
                break;
            }

        //recherche par nom de Famille
        case 2:

            printf("Vous voulez rechercher une personne en connaissant sont Nom de Famille\n");
            recherche_nom(structure);

            //attente d'une action de l'utilisateur
            printf(BLEUCLAIR "\nTapez sur Entrer pour retourner au menu :\n" NORMAL);
            if (fgets(rien, LONGUEUR_MAX, stdin))
            {
                break;
            }

        //Si la personne veut un arbre généalogique d'une personne en connaissant son prénom
        case 3:

            printf("Vous voulez rechercher l'arbre généalogique d'une personne en connaissant son prénom.\n");
            recherche_par_prenom(structure, texte);

            //attente d'une action de l'utilisateur
            printf(BLEUCLAIR "\nTapez sur Entrer pour retourner au menu :\n" NORMAL);
            if (fgets(rien, LONGUEUR_MAX, stdin))
            {
                break;
            }

        //Si la personne veut un arbre généalogique d'une personne en connaissant son id
        case 4:

            printf("\nVous voulez rechercher l'arbre généalogique d'une personne en connaissant son identifiant.\n");
            printf(SOULIGNE "Quel est l'identifiant de cette personne :\n" NORMAL);
            fgets(texte, LONGUEUR_MAX, stdin);
            identifiant = atoi(texte);
            nombre_essai = 0;

            //Vérification que l'id est un id possible
            identifiant = verif_id(identifiant);
            //si identifiant = 0 c'est que le nombre d'essai est dépassé
            if (!identifiant)
            {
                //attente d'une action de l'utilisateur
                printf(BLEUCLAIR "\nTapez sur Entrer pour retourner au menu :\n" NORMAL);
                if (fgets(rien, LONGUEUR_MAX, stdin))
                {
                    break;
                }
            }

            //recupération du nom du fichier
            nom_fichier_html(structure, identifiant, &nomfichier);
            ouverture_de_fichier_html(nomfichier);

            //attente d'une action de l'utilisateur
            printf(BLEUCLAIR "\nTapez sur Entrer pour retourner au menu :\n" NORMAL);
            if (fgets(rien, LONGUEUR_MAX, stdin))
            {
                break;
            }
        //Si la personne veut un arbre généalogique d'une personne aléatoire
        case 5:

            printf("Vous voulez rechercher l'arbre généalogique d'une personne aléatoire.\n");
            //on prend un nombre aléatoire
            identifiant = rand() % NB_PERSONNES;

            //récupération du nom du fichier correspondant
            nom_fichier_html(structure, identifiant, &nomfichier);
            ouverture_de_fichier_html(nomfichier);

            //attente d'une action de l'utilisateur
            printf(BLEUCLAIR "\nTapez sur Entrer pour retourner au menu :\n" NORMAL);
            if (fgets(rien, LONGUEUR_MAX, stdin))
            {
                break;
            }
        //Si la personne veut connaître les frères et soeurs d'une personne
        case 6:
            //on récupère l'action demandée du menu 2 la fratrie
            action1 = menu2_fratrie();
            //appel à la fonction switch pour la recherche de frère et soeur
            switch_fratrie(action1, structure);

            //attente d'une action de l'utilisateur
            printf(BLEUCLAIR "\nTapez sur Entrer pour retourner au menu :\n" NORMAL);
            if (fgets(rien, LONGUEUR_MAX, stdin))
            {
                break;
            }
        //l'utilisateur veux quitter le programme
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
