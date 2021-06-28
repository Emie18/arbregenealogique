//dans le main: A la place de la recherche de par nom
case 1:

       
            list(structure);
       
            //attente d'une action de l'utilisateur
            printf(BLEUCLAIR"\nTaper sur Entrer pour retourner au menu :\n"NORMAL);
            if(fgets(rien,LONGUEUR_MAX,stdin));{
                break;
            }

             break;

//fonction qui affiche la liste et propose l'ouverture d'un fcihier précis
int list (Person structure[NB_PERSONNES]){
        char texte[TAILLE_MAX];
        printf(SOULIGNE"Liste de toutes les personne enregistré:\n"NORMAL);
        for (int i = 1; i< NB_PERSONNES ; i++){
                printf("id: %d\t nom: %s\t prénom :%s\n",structure[i].id,structure[i].lastname, structure[i].firstname);

        }
        printf("Taper un id pour ouvrir sa page ou \t Taper: 0 ou autre \n :");
        fgets(texte,TAILLE_MAX,stdin);
        int id = atoi(texte);
        
        char nomfichier[TAILLE_MAX] = "\0";
        if(id > 0){

                sprintf(nomfichier, "fichiers_HTML/%s%s.html", structure[id].lastname, structure[id].firstname);
                printf(BLEUCLAIR"Ouverture dufichier en cours ...\n"NORMAL);
                ouverture_de_fichier_html(nomfichier);
        }

        

 }