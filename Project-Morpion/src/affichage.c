#include "../../gfxlib/include/GfxLib.h"
#include "../../gfxlib/include/BmpLib.h"
#include "../include/affichage.h"
#define centrex largeurFenetre() / 2
#define centrey hauteurFenetre() / 2



void afficheMenu(char scJ, char scBot){
    couleurCourante(61,219,230);
    epaisseurDeTrait(20);
    afficheChaine("Tic - Tac - Toe", 60, centrex - 320, centrey + 250);


    couleurCourante(85,125,128);
    rectangle(centrex - 300 ,centrey + 50 , centrex - 100 , centrey + 150); 
    rectangle(centrex + 100, centrey + 50 , centrex + 300, centrey + 150);

    couleurCourante(104,197,204);
    afficheChaine("PLAY", 60, centrex - 280 , centrey + 72 ); // PLAY
    afficheChaine("EXIT ", 60, centrex + 139, centrey + 72); // EXIT

    afficheChaine("SCORE", 60, centrex - 100 , centrey - 30 );  // SCORE

    afficheChaine(scJ, 60, centrex - 300  , centrey - 150);  // Joueur 1
    afficheChaine(scBot, 60, centrex + 150 , centrey - 150);  // Bot
}

void afficheTab(){
    couleurCourante(189,189,189);
    epaisseurDeTrait(5);
    ligne(centrex  - 250 ,centrey - 250 ,centrex  - 250 , centrey + 250 );  //mur gauche
    ligne(centrex  - 125 ,centrey - 250 ,centrex  - 125 , centrey + 250 );    // colonne 1 

    ligne(centrex   + 250 ,centrey   - 250 ,centrex    + 250 , centrey   + 250 );  // mur droite
    ligne(centrex    ,centrey   - 250 ,centrex    , centrey   + 250 );  // colonne 2 
    ligne(centrex    + 125 ,centrey   - 250 ,centrex    + 125, centrey   + 250 );  // colonne 3 


    ligne(centrex   - 250 ,centrey   - 250 ,centrex    + 250 , centrey   - 250 );  // mur bas
    ligne(centrex   - 250 ,centrey   - 125 ,centrex    + 250 , centrey   - 125 );  // ligne 1

    ligne(centrex   - 250 ,centrey   + 250 ,centrex    + 250 , centrey   + 250 );  // mur haut
    ligne(centrex   - 250 ,centrey  ,centrex    + 250 , centrey   ); // ligne 2
    ligne(centrex   - 250 ,centrey   + 125 ,centrex    + 250 , centrey   + 125 ); // ligne 3
}