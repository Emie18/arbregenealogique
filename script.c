#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 255
int main(){
     char * nomfichier = "test.html";
     ouverture_de_fichierhtml(nomfichier);
}
int ouverture_de_fichierhtml(char * nomfichier){
    char fichier_ouvrir[TAILLE_MAX];
     sprintf(fichier_ouvrir,"xdg-open %s",nomfichier);
     system(fichier_ouvrir);
     return 0;
}