/*----------------------------
    Projet de fin d'année CIR 1
    Nom projet : 
                Arbre genealogique
    Auteurs:
            Matthis Miaud 
                    et 
            Emilie Le Rouzic

    nom du fichier : flancement.c
    date : Juin 2021
------------------------------*/

#include "projet.h"

//Fonction qui récupère les données du fichier fourni, appelle la fonction pour créer une struture pour stocker
//ces données puis les stocke dans le tableau de struture donné à l'appel
void initialisation(Person structure[NB_PERSONNES])
{

        char ligne[CARACTERE_LIGNE];
        char virgule[2] = ",";
        char *id1, *father_id1, *mother_id1, *lastname, *firstname, *city, *birthdate;
        int id, father_id, mother_id;
        FILE *csv = NULL;

        //ouverture du fichier avec les données
        csv = fopen(NOM_FICHIER_SOURCE, "r");

        for (int i = 0; i < NB_PERSONNES; i++)
        {

                //Lecture de la ligne
                fgets(ligne, CARACTERE_LIGNE, csv);

                //Pour chaque donnée récupéré, on la range dans la variable temporaire du même type
                for (int j = 0; j < 7; j++)
                {

                        switch (j)
                        {

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
Person *initPerson(int id, int father_id, int mother_id, char *lastname,
                   char *firstname, char *birthdate, char *city)
{
        //Allocation de la mémoire nécessaire
        Person *actuel = malloc(sizeof(Person));

        //Affectation des données à la structure crée
        actuel->id = id;
        actuel->father_id = father_id;
        actuel->mother_id = mother_id;
        strncpy(actuel->lastname, lastname, strlen(lastname));
        strncpy(actuel->firstname, firstname, strlen(firstname));
        strncpy(actuel->birthdate, birthdate, strlen(birthdate));
        strncpy(actuel->city, city, strlen(city));
        //renvoie de l'adresse de la struture créé
        return actuel;
}

//Fonction pour associer les adresses des structures des parents à la struture de l'enfant
void parents(Person structure[NB_PERSONNES])
{
        int b;

        for (int i = 0; i < NB_PERSONNES; i++)
        {

                //Récupération du rang du père
                b = structure[i].father_id;

                //Si le rang est de 0, il n'y a pas de père donc pas d'adresse à fournir, renvoi ver NULL
                if (b == 0)
                {
                        structure[i].p_father = NULL;     
                }
                //Sinon, affectation de l'adresse de la struct au rang récupéré
                else
                {
                        structure[i].p_father = &structure[b];
                }

                //Récupération du rang de la mère
                b = structure[i].mother_id;

                //Si le rang est de 0, il n'y a pas de père donc pas d'adresse à fournir, renvoi ver NULL
                if (b == 0)
                {
                        structure[i].p_mother = NULL;      
                }
                //Sinon, affectation de l'adresse de la struct au rang récupéré
                else
                {
                        structure[i].p_mother = &structure[b];
                }
        }
}

//fonction pour créer les balises lien
char *baliselien(char *nom, char *prenom, char *balise)
{
        sprintf(balise, "<a href=\"%s%s.html\">%s %s</a>", nom, prenom, prenom, nom);
        return balise;
}

//fonction pour la création des fichiers HTML dans le dossier fichier_HTML
void creationhtml(Person structure[NB_PERSONNES])
{

        for (int j = 1; j < NB_PERSONNES; j++)
        {
                char chaine[TAILLE_MAX];
                int i = 0;
                //affectation des données dans des variables
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

                //variable pour s'arrêter au grand parent
                int rien;

                //recherche des parents de l'enfant
                noms_parents(structure, j, &nom_mere, &prenom_mere, &nom_pere, &prenom_pere, &id_pere, &id_mere);

                //côté mère
                char *prenom_grandpere1;
                char *nom_grandpere1;
                char *prenom_grandmere1;
                char *nom_grandmere1;

                //recherche des parents du mère
                noms_parents(structure, id_mere, &nom_grandmere1, &prenom_grandmere1, &nom_grandpere1, &prenom_grandpere1, &rien, &rien);

                //côté père
                char *prenom_grandpere2;
                char *nom_grandpere2;
                char *prenom_grandmere2;
                char *nom_grandmere2;

                //recherche des parents de la père
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

                //ouverture du fichier source html
                FILE *fp = fopen(NOM_FICHIER_HTML_SOURCE, "r");
                //ouverture/créaton du nouveau fichier
                FILE *newfp = fopen(nomfichier, "w");
                if (fp != NULL)
                {
                        // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
                        while (fgets(chaine, TAILLE_MAX, fp) != NULL)
                        { 

                                i++;
                                //i corresspond à la ligne dans le fichier source HTML
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
                        //fermeture des fichiers
                        fclose(newfp);
                        fclose(fp);
                }
        }
}

//fonction qui libère la structure
void libere_structure(Person structure[NB_PERSONNES])
{

         for(int i = 0; i<NB_PERSONNES;i++){

                free(&structure[i]);
         }
}

//fonction qui affiche le menu principale et renvois l'action voulu
int menu_principal()
{
        int nombre_essai = 0;
        char actionc[TAILLE_MAX];
        int action;
        while (1)
        {
                //affichage du menu
                printf("\n\n===========================================================================\n\n");

                printf(BLEU "Bonjour, que souhaitez vous faire ?\n\n");

                printf("1. Afficher la liste entère des personnes enregistrées.\n\n");

                printf("2. Rechercher les personne posédant un le même Nom de famille\n\n");

                printf("3. Rechercher une personne par son prénom.\n\n");

                printf("4. Rechercher une personne par son identifiant (id).\n\n");

                printf("5. Découvrir un arbre généalogique aléatoire.\n\n");

                printf("6. Rechercher les frères et soeurs d'une personne.\n\n");

                printf("\t\t->Si vous voulez stopper le logiciel, tapez 7<-\n" NORMAL);

                printf("\n\n===========================================================================\n");

                //Récupération du choix
                printf(SOULIGNE "Veuillez renseigner votre choix :\n" NORMAL);
                fgets(actionc, LONGUEUR_MAX, stdin);
                action = atoi(actionc);

                //Vérification du choix est un choix possible
                while (1)
                {
                        if (action < 1 || action > 7)
                        {
                                printf(ROUGE "Vous n'avez pas renseigné une action valide, veuillez réessayer :\n" NORMAL);
                                fgets(actionc, LONGUEUR_MAX, stdin);
                                action = atoi(actionc);
                                nombre_essai++;
                                if (nombre_essai == NB_MAX_ESSAI)
                                {
                                        printf(ROUGE "Nombre d'essai dépassé\n" NORMAL);
                                        return 0;
                                }
                        }
                        else
                        {
                                nombre_essai = 0;
                                return action;
                        }
                }
        }
}