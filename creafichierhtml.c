#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 1000

 
int main ()
{
 char *chaine = malloc(sizeof(char*)*TAILLE_MAX);
    FILE *fp = fopen("test.html", "r");
    int i =0;
    char * prenom = "Earnest";
    char * nom = "Davenport";
    char *date = "14/5/1875";
    char * lieux = "Norfolk";
    //parents
    char * pere = "Barney";
    char * mere ="Gia";
    //côté père
    char * gpp ="Davenport, Christian";
    char * gmp ="dezfzefe";
    //côté mère
    char * gpm ="Newbury,Rey,";
    char * gmm ="-";
    //déclaration des balises
    char balisetitre[TAILLE_MAX];
    char nomfichier[TAILLE_MAX];
    char balisedate[TAILLE_MAX];
    char baliselieux[TAILLE_MAX];
    char balisepere[TAILLE_MAX];
    //création de la balise date
    sprintf(balisedate,"<span>%s</span>",date);//ligne 51
    //création de la balise lieux de naissance
    sprintf(baliselieux,"<span>%s</span>",lieux);//ligne 54
   //création de la balise nom prenom
   sprintf(balisetitre,"<h2> %s %s </h2>\n",prenom,nom);//ligne 49
   //création du non du fichier 
   sprintf(nomfichier,"%s%s.html",nom,prenom);
   //creation balise père
   sprintf(balisepere,"<a href=\"%s%s.html\">%s</a>",nom,pere,pere);

    FILE *newfp =fopen (nomfichier,"w");
  if (fp != NULL)

   {

       while (fgets(chaine, TAILLE_MAX, fp) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)

       {
           i++;
           switch (i)
           {
           case 49:
               fputs(balisetitre,newfp);
               break;
           case 51 :
             fputs(balisedate,newfp);
             break;
           case 54:
             fputs(baliselieux,newfp);
             break;
            case 62:
            fputs(balisepere,newfp);
             break;
           default:
               fputs(chaine,newfp);
               break;
           }
           
          

       }


    fclose(newfp);
    fclose(fp);

   }

    return 0;
}