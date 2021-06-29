/*----------------------------
    Projet de fin d'année CIR 1
    Nom projet : 
                Arbre genealogique
    Auteurs:
            Matthis Miaud 
                    et 
            Emilie Le Rouzic

    nom du fichier : fonctions.c
    date : Juin 2021
------------------------------*/

#include "projet.h"

//Fonction qui récupère le nom des parents
void noms_parents(Person struture[LONGUEUR_MAX], int enfant, char **nmere, char **pmere,
                  char **npere, char **ppere, int *id_mere, int *id_pere)
{
        Person *a = NULL;
        a = struture[enfant].p_mother;

        //S'il n'y a pas de mère, le nom sera "inconnue" et les autres informations seront nulles
        if (a == NULL)
        {
                *pmere = "inconnue";
                *nmere = "";
                *id_mere = 0;     
        }
        //Sinon, récupération des information et affectation par paramètre entrée/sortie
        else
        {
                *pmere = a->firstname;
                *nmere = a->lastname;
                *id_mere = a->id;
        }
        a = struture[enfant].p_father;

        //S'il n'y a pas de père, le nom sera "inconnue" et les autres informations seront nulles
        if (a == 0)
        {
                *ppere = "inconnue";
                *npere = "";
                *id_pere = 0;   
        }
        //Sinon, récupération des information et affectation par paramètre entrée/sortie
        else
        {
                *ppere = a->firstname;
                *npere = a->lastname;
                *id_pere = a->id;
        }
}

//fonction qui recherche par prénom
int recherche_par_prenom(Person structure[NB_PERSONNES], char *prenom)
{
        char texte[TAILLE_MAX];
        printf("%s\nEntrez le prenom (La première lettre doit-être une majuscule !)%s :", SOULIGNE, NORMAL);
        fgets(texte, TAILLE_MAX, stdin);
        texte[strlen(texte) - 1] = '\0';
        int erreur = 0;
        //affichage de tout les personnes portant ce prénom
        for (int i = 0; i < NB_PERSONNES; i++)
        {
                if (strcmp(texte, structure[i].firstname) == 0)
                {
                        printf("ID :%d\t Nom :%s\t Prénom: %s\n", i, structure[i].lastname, structure[i].firstname);
                        erreur = 1;
                }
        }
        //si il y a au moins une personne portant ce prénom
        if (erreur)
        {
                printf("Tapez un id pour ouvrir sa page %s ou tapez sur une touche pour passer%s\n:", SOULIGNE, NORMAL);
                fgets(texte, TAILLE_MAX, stdin);
                int id = atoi(texte);

                char nomfichier[TAILLE_MAX] = "\0";
                if (id > 0 && id < NB_PERSONNES )
                {       
                        //on met le nom du fichier de cette personne dans nomfichier
                        sprintf(nomfichier, "fichiers_HTML/%s%s.html", structure[id].lastname, structure[id].firstname);
                        printf(BLEUCLAIR "Ouverture du fichier en cours ...\n" NORMAL);
                        ouverture_de_fichier_html(nomfichier);
                        return id;
                }
        }
        else
        {
                printf(ROUGE "Prenom inconnu. (vérifiez que le nom commence par une Majuscule)\n" NORMAL);
                return 0;
        }
}

//Fonction qui à pour but de recréer le nomm du fichier contenant l'arbre généalogique de la personne renseigné
void nom_fichier_html(Person structure[NB_PERSONNES], int id, char **nomfichier)
{

        //Si l'utilisateur à fournis un ID qui existe
        if (id > 0 && id < NB_PERSONNES)
        {
                //Le nom du fichier sera "fichiers_HTML+le nom et le prénom contenus dans la structure au rang de l'id donné - 1
                //(les tableau commencent au rang 0 alors que le fichier commence au rang 0)
                sprintf(*nomfichier, "fichiers_HTML/%s%s.html", structure[id].lastname, structure[id].firstname);
                printf(BLEUCLAIR "Veuillez attrendre quelques secondes l'ouverture du fichier...\n" NORMAL);
                //Si le l'id n'est pas connu
        }
        else
        {
                printf(ROUGE "Désolé, nous n'avons pas pu trouver la personne que vous demandiez...\n" NORMAL);
                *nomfichier = "";
        }
}

//Fonction qui ouvre le fichier fournis à l'appel
void ouverture_de_fichier_html(char *nomfichier)
{
        if (strcmp(nomfichier, "") != 0)
        {
                char *fichier_ouvrir = malloc(sizeof(char *) * TAILLE_MAX);
                sprintf(fichier_ouvrir, "xdg-open %s", nomfichier);
                system(fichier_ouvrir);
        }
        else
        {
                printf(ROUGE "Nous n'avons pas pu ouvrir de fichier" NORMAL);
        }
}

//Fonction qui permet de rescencer les frères et soeurs de la personne renseigné à l'appel
void frere_soeur(Person structure[NB_PERSONNES], int id)
{
        char vide[LONGUEUR_MAX] = "\0";
        int i;
        int idmere = 0;
        int idpere = 0;
        int n = 0;
        int erreur = 0;

        //Si c'est un id qui à été fournis ou si on l'a récupéré à partir de son prénom
        if (id != 0)
        {
                erreur = 1;
                //Si on ne connaît pas encore l'id des parents, on les récupèrent
                if (idmere == 0 && idpere == 0)
                {
                        idmere = structure[id].mother_id;
                        idpere = structure[id].father_id;
                }
                printf("Vous cherchez les frères et soeurs de %s %s\n", structure[id].lastname, structure[id].firstname);
                for (i = 1; i < NB_PERSONNES; i++)
                {

                        //Si la personne que l'on vérifie à les même parents
                        if (idmere == structure[i].mother_id && idpere == structure[i].father_id && idmere != 0 && idpere != 0)
                        {
                                //Si la personne que l'on étudie n'est pas la personne dont on veut savoir les frères et soeurs (pour eviter de dire que la personne a est frère de la personne a)
                                if (structure[i].id != id)
                                {
                                        printf("%s %s\t est un frère/une soeur de %s %s\n", structure[i].firstname, structure[i].lastname, structure[id].firstname, structure[id].lastname);
                                        n++;
                                }   
                        } 
                        else
                        {       //Si c'est un demi-frère/une belle-soeur paternel
                                if (idmere != structure[i].mother_id && idpere == structure[i].father_id && idpere != 0)
                                {
                                        printf("%s %s\t est un demi-frère/une demie-soeur de %s %s du côté paternel\n", structure[i].firstname, structure[i].lastname, structure[id].firstname, structure[id].lastname);
                                        n++;
                                }
                                else
                                {       //Si c'est un demi-frère/une belle-soeur paternel
                                        if (idmere == structure[i].mother_id && idpere != structure[i].father_id && idmere != 0)
                                        {
                                                printf("%s %s\t est un demi-frère/une demie-soeur de %s %s du côté maternel\n", structure[i].firstname, structure[i].lastname, structure[id].firstname, structure[id].lastname);
                                                n++;
                                        }
                                }
                        }
                }

                if (n == 0)
                {
                        printf("Cette personne n'a pas de frères ni de soeurs\n");
                }
                if (!erreur)
                {
                        printf(ROUGE "Prénom inconnu (vérifiez que le prénom commence par une Majuscule!)\n" NORMAL);
                }
        }
}

// fonction qui affiche le menu 2 fratrie comportant 3 choix et retourne ce choix
int menu2_fratrie()
{
        int i = 0;
        char action[TAILLE_MAX];
        printf(SOULIGNE "\nVous voulez rechercher les frères et soeurs d'une personne.\n" NORMAL);
        printf("Comment voulez vous rechercher cette personne ?\n\n");
        printf(BLEU "1. Rechercher par son nom.\n\n");
        printf("2. Rechercher par son prénom.\n\n");
        printf("3. Rechercher par son identifiant (id)\n\n" NORMAL);
        printf(SOULIGNE "Veuillez renseigner votre choix :\n" NORMAL);
        fgets(action, LONGUEUR_MAX, stdin);
        int action1 = atoi(action);

        //Vérification que le choix est un choix possible
        while (1)
        {

                if (action1 < 1 || action1 > 3)
                {
                        i++;
                        printf(ROUGE "Vous n'avez pas renseigné une action valide, veuillez réessayer :\n" NORMAL);
                        fgets(action, LONGUEUR_MAX, stdin);
                        action1 = atoi(action);
                        if (i > NB_MAX_ESSAI)
                        {
                                printf(ROUGE "Nombre d'essai dépasser\n" NORMAL);
                                return 0;
                        }
                }
                else
                {
                        return action1;
                }
        }
}

//fonction qui contient le switch pour la recherche de frères et soeurs
int switch_fratrie(int action1, Person structure[NB_PERSONNES])
{
        char texte[LONGUEUR_MAX] = "\0";
        int identifiant = 0;
        int nombre_essai = 0;

        switch (action1)
        {
        //Partie recherchant les frères et soeurs à partir d'un nom de famille
        case 1:

                recherche_frere_soeur_par_nom(structure);
                break;

        //Si la personne veut les frères et soeurs d'une personne en connaissant son prénom
        case 2:

                printf("Vous voulez rechercher les frères et soeurs d'une personne en connaissant son prénom.\n");
                identifiant = recherche_frere_soeur_par_prenom(structure);
                frere_soeur(structure, identifiant);
                break;

        //Si la personne veut les frères et soeurs d'une personne en connaissant son prénom
        case 3:

                printf("Vous voulez rechercher les frères et soeurs d'une personne en connaissant son identifiant.\n");
                printf(SOULIGNE "Quel est l'identifiant de cette personne :\n" NORMAL);
                fgets(texte, LONGUEUR_MAX, stdin);
                identifiant = atoi(texte);

                //Vérification que l'id est un id possible
                identifiant = verif_id(identifiant);
                //si identifiant = 0 c'est que le nombre d'essai est dépassé
                if (!identifiant)
                {
                        break;
                }

                frere_soeur(structure, identifiant);
                break;
        }
}

//fonction qui affiche la liste de toutes les personnes du registre et propose d'ouvrir une page HTML
int list(Person structure[NB_PERSONNES])
{
        char texte[TAILLE_MAX];
        printf(SOULIGNE "Liste de toutes les personnes enregistrées :\n" NORMAL);
        for (int i = 1; i < NB_PERSONNES; i++)
        {
                printf("ID: %d\t Nom: %s\t Prénom : %s\n", structure[i].id, structure[i].lastname, structure[i].firstname);
        }
        printf("Taper un id pour ouvrir sa page %s ou tapez sur une touche pour passer %s\n :", SOULIGNE, NORMAL);
        fgets(texte, TAILLE_MAX, stdin);
        int id = atoi(texte);
        char nomfichier[TAILLE_MAX] = "\0";
        if (id > 0)
        {
                sprintf(nomfichier, "fichiers_HTML/%s%s.html", structure[id].lastname, structure[id].firstname);
                printf(BLEUCLAIR "Ouverture du fichier en cours ...\n" NORMAL);
                ouverture_de_fichier_html(nomfichier);
        }
}

//fonction qui affiche les personnes qui possèdent un même nom de famille
int recherche_nom(Person structure[NB_PERSONNES])
{
        char nom[TAILLE_MAX];
        printf("Entrez le nom (La première lettre doit-être une majuscule !): ");
        fgets(nom, TAILLE_MAX, stdin);
        nom[strlen(nom) - 1] = '\0';
        //variable permettant de savoir si le nom entrer existe 1:il existe et 0: il existe pas
        int erreur = 0;

        //boucle qui affiche toutes les personnes possédant le nom recherché
        for (int i = 0; i < NB_PERSONNES; i++)
        {
                if (strcmp(nom, structure[i].lastname) == 0)
                {
                        printf("ID :%d\t Nom :%s\t Prénom: %s\n", i, nom, structure[i].firstname);
                        erreur = 1;
                }
        }
        //si il y a au moins une personne avec ce nom de Famille
        if (erreur)
        {
                printf("Taper un id pour ouvrir sa page %s ou tapez sur une touche pour passer %s\n :", SOULIGNE, NORMAL);
                fgets(nom, TAILLE_MAX, stdin);
                int id = atoi(nom);

                char nomfichier[TAILLE_MAX] = "\0";
                if (id > 0)
                {
                        sprintf(nomfichier, "fichiers_HTML/%s%s.html", structure[id].lastname, structure[id].firstname);
                        printf(BLEUCLAIR "Ouverture du fichier en cours ...\n" NORMAL);
                        ouverture_de_fichier_html(nomfichier);
                }
        }
        //si le nom n'existe pas
        else
        {
                printf(ROUGE "Nom inconnu. (vérifiez que le nom commence par une Majuscule)\n" NORMAL);
        }
}

//fonction listant les personne possédant le nom
//et appel la fonction frere_soeur de l'id entrer
//attention à l'id qu'on rentre la liste n'est qu'à titre informatif
int recherche_frere_soeur_par_nom(Person structure[NB_PERSONNES])
{
        char nom[TAILLE_MAX];
        printf("Entrez le nom (La première lettre doit-être une Majuscule !): ");
        fgets(nom, TAILLE_MAX, stdin);
        nom[strlen(nom) - 1] = '\0';
        int erreur = 0;
        for (int i = 0; i < NB_PERSONNES; i++)
        {
                if (strcmp(nom, structure[i].lastname) == 0)
                {
                        printf("ID : %d\t nom : %s\tprénom: %s\n", i, nom, structure[i].firstname);
                        erreur = 1;
                }
        }
        //si il y a au moins une personne avec ce nom de Famille
        if (erreur)
        {
                printf(SOULIGNE "Taper l'id de la personne souhaitée  ou tapez sur une touche pour passer\n :" NORMAL);
                fgets(nom, TAILLE_MAX, stdin);
                int id = atoi(nom);

                char nomfichier[TAILLE_MAX] = "\0";
                if (id > 0 && id < NB_PERSONNES)
                {
                        frere_soeur(structure, id);
                }
        }
        else
        {
                printf(ROUGE "Nom inconnu,(vérifier que le nom commence par une Majuscule)\n" NORMAL);
        }
}

//exactement la même fonction que recherche_frere_soeur_par_nom , mais avec prénom à la place
int recherche_frere_soeur_par_prenom(Person structure[NB_PERSONNES])
{
        char texte[TAILLE_MAX];
        printf("Entrez le prenom (La première lettre doit-être une Majuscule !): ");
        fgets(texte, TAILLE_MAX, stdin);
        texte[strlen(texte) - 1] = '\0';
        int erreur = 0;
        for (int i = 0; i < NB_PERSONNES; i++)
        {
                if (strcmp(texte, structure[i].firstname) == 0)
                {
                        printf("ID : %d\t nom : %s\tprénom: %s\n", i, structure[i].lastname, structure[i].firstname);
                        erreur = 1;
                }
        }
        //si il y a au moins une personne avec ce prénom
        if (erreur)
        {
                printf(SOULIGNE "Taper l'id de la personne souhaitée  ou tapez sur une touche pour passer\n :" NORMAL);
                fgets(texte, TAILLE_MAX, stdin);
                int id = atoi(texte);

                char nomfichier[TAILLE_MAX] = "\0";
                if (id > 0 && id < NB_PERSONNES )
                {
                        frere_soeur(structure, id);
                }
        }
        else
        {
                printf(ROUGE "Prenom inconnu,(vérifier que le nom commence par une Majuscule)\n" NORMAL);
        }
}

//fonction qui vérifie que l'identifiant est bien compris entre 1 et NB_PERSONNES
//et renvoi l'identifiant si il renvoit 0:nombre d'essai dépassés
int verif_id(int identifiant)
{
        int nombre_essai = 0;
        char *texte = malloc(sizeof(char *) * TAILLE_MAX);
        while (1)
        {
                //si l'identifiant n'existe pas
                if (identifiant < 1 || identifiant > NB_PERSONNES - 1)
                {
                        printf(ROUGE "Vous n'avez pas renseigné une action valide, veuillez réessayer :\n");
                        printf("Vérifier qui l'id est compris entre %s%s 1 et %d %s:\n", SOULIGNE, BLEUCLAIR, NB_PERSONNES - 1, NORMAL);
                        fgets(texte, LONGUEUR_MAX, stdin);
                        identifiant = atoi(texte);
                        nombre_essai++;

                        //si le nombre d'essai est dépassé on retourne 0
                        if (nombre_essai == NB_MAX_ESSAI)
                        {
                                printf(ROUGE SOULIGNE "Nombre d'essais dépassés\n" NORMAL);
                                return 0;
                        }
                }
                //sinon on retourne l'identifiant entré
                else
                {
                        return identifiant;
                }
        }
}
