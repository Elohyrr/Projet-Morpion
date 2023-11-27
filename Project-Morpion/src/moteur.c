#include "../include/moteur.h"
#include <stdio.h>
#include <stdlib.h>
void initTabJeu(char tabjeu[tailletab][tailletab])
{
    for(int i = 0; i < tailletab ; i++){
        for(int j = 0; j < tailletab ; j++ ){
            tabjeu[i][j] = '.';
        }
    }
}

void afficheTabJeu(char tabjeu[tailletab][tailletab])
{
    for(int i = 0; i < tailletab ; i++){
        printf("\n");
        for(int j = 0; j < tailletab ; j++ ){
            printf("%c" , tabjeu[i][j]);
        }
    }    
}


