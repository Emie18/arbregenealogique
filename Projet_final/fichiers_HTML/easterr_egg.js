let n = 0;
var intervalId = setInterval (easter_egg, 3000);
function easter_egg(){
    
    n++;
   
    if(n==1){

        document.getElementById("texte").innerHTML = "Désolé, on n'a pas pu trouver la personne que vous recherchez...";
    }
    if(n==2){

        document.getElementById("texte").innerHTML = "Ah ! On me dit dans l'oreillette, qu'on aurait peut être retrouvé cette personne...";
    }
    if(n == 3){

        document.getElementById("texte").innerHTML = "Effectivement, on l'a retrouvé, je vais vous la présenter de ce pas !";
        window.open("https://www.youtube.com/watch?v=QtBDL8EiNZo","nom_de_la_fenetre","options_nouvelle_fenetre");
        
    }
    if(n == 20){

        document.getElementById("texte").innerHTML = "désolé, je n'ai pas pu m'en empecher ^_^";
        clearInterval(intervalId);


    }
} 

//Il faut aussi rajouter un simple div dans le fichier HTML avec comme id texte.