/* ------------dans le fichier projet.h ---------*/
#define TAILLE_MAX 1000
void creationhtml(Person structure[NB_PERSONNES]);
char *baliselien(char *nom, char *prenom, char *balise);

/* ------------dans le fichier main.c ---------*/
//appel de la fonction
 creationhtml(structure);
/* ------------dans le fichier fonction.c ---------*/
//modification de la fonction nom des parents
void noms_parents(Person struture[LONGUEUR_MAX], int enfant, char **nmere, char **pmere, char **npere, char **ppere,
                  int *id_mere, int *id_pere)
{

   Person *a = NULL;

   a = struture[enfant].p_mother;
   if (a == 0)
   {
      *pmere = "inconnue";
      *nmere = "";
      *id_mere = 0;
   }
   else
   {
      *pmere = a->firstname;
      *nmere = a->lastname;
      *id_mere = a->id;
   }

   //*idm =a->mother_id;

   a = struture[enfant].p_father;
    if (a == 0)
   {
      *ppere = "inconnue";
      *npere = "";
      *id_pere = 0;
   }
   else
   {
      *ppere = a->firstname;
      *npere = a->lastname;
      *id_pere = a->id;
   }

  
}

//fonction pour créer les balises lien
char *baliselien(char *nom, char *prenom, char *balise)
{

   sprintf(balise, "<a href=\"%s%s.html\">%s %s</a>", nom, prenom, prenom, nom);
   return balise;
}
//la fonction pour créer les fichier html 
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
      int rien;
      //recherche des parents de l'enfant
      noms_parents(structure, j, &nom_mere, &prenom_mere, &nom_pere, &prenom_pere, &id_pere, &id_mere);
      
      //côté père
      char *prenom_grandpere1;
      char *nom_grandpere1;
      char *prenom_grandmere1;
      char *nom_grandmere1;

      //recherche des parents du pere
      noms_parents(structure, id_pere, &nom_grandmere1, &prenom_grandmere1, &nom_grandpere1, &prenom_grandpere1, &rien, &rien);

      
      //côté mères
      char *prenom_grandpere2;
      char *nom_grandpere2;
      char *prenom_grandmere2;
      char *nom_grandmere2;
      //recherche des parents de la mere
      noms_parents(structure, id_mere, &nom_grandmere2, &prenom_grandmere2, &nom_grandpere2, &prenom_grandpere2, &rien, &rien);
      
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
      //création du non du fichier
      sprintf(nomfichier, "%s%s.html", nom, prenom);
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
