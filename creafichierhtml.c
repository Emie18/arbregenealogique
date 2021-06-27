#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 1000

//fonction pour créer les balises lien
char *baliselien(char *nom, char *prenom, char *balise)
{

   sprintf(balise, "<a href=\"%s%s.html\">%s %s</a>", nom, prenom, prenom, nom);
   return balise;
}


void creationhtml(Person structure[TAILLE_MAX])
{
   for (int j = 0; j < 40; j++)
   {

      char chaine[TAILLE_MAX];
      FILE *fp = fopen("test.html", "r");
      int i = 0;
      char prenom[TAILLE_MAX] = structure[j].firstname;
      char nom[TAILLE_MAX] = structure[j].lastname;
      char date[TAILLE_MAX] = structure[j].birthdate;
      char lieux[TAILLE_MAX] = structure[j].city;

      //parents
      char prenom_pere[TAILLE_MAX] = "Barney";
      char nom_pere[TAILLE_MAX] = "Davenport";
      char prenom_mere[TAILLE_MAX] = "Gia";
      char nom_mere[TAILLE_MAX] = "idehyyy";
      //côté père
      char prenom_grandpere1[TAILLE_MAX];
      char nom_grandpere1[TAILLE_MAX];
      char prenom_grandmere1[TAILLE_MAX];
      char nom_grandmere1[TAILLE_MAX];
      //côté mère
      char prenom_grandpere2[TAILLE_MAX];
      char nom_grandpere2[TAILLE_MAX];
      char prenom_grandmere2[TAILLE_MAX];
      char nom_grandmere2[TAILLE_MAX];
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