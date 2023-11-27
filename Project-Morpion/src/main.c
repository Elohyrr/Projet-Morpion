#include "../include/main.h"

int etatJeu = 0;

int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	
	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);
	char tabjeu[ttab][ttab];
	initTabJeu(tabjeu);
	afficheTabJeu(tabjeu);
	lanceBoucleEvenements();

	
	return 0;
}

void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran
	static char scoreJoueur[10] = "";
	static char scoreBot[10] = "";


	
	switch (evenement)
	{
		case Initialisation:
			image = lisBMPRGB("/home/kali/Documents/Project-Morpion/Project-Morpion/img/patateboy.bmp");
			demandeTemporisation(20);
			break;
		
		case Temporisation:
			rafraichisFenetre();
			break;
			
		case Affichage:
			effaceFenetre(37,50,51);
			switch(etatJeu){
				case 0:
					afficheMenu(scoreJoueur, scoreBot);

				break;
				case 1:
					afficheTab();
				break;
			}
			if (image != NULL) // Si l'image a pu etre lue
			{
				// On affiche l'image
				//ecrisImage((largeurFenetre()-image->largeurImage)/2, (hauteurFenetre()-image->hauteurImage)/2, image->largeurImage, image->hauteurImage, image->donneesRGB);
			}

			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir quelque peu proprement du programme */
				case 'q':
					libereDonneesImageRGB(&image); /* On libere la structure image,
					c'est plus propre, meme si on va sortir du programme juste apres */
					termineBoucleEvenements();
					break;

				case 'F':
				case 'f':
					pleinEcran = !pleinEcran; // Changement de mode plein ecran
					if (pleinEcran)
						modePleinEcran();
					else
						redimensionneFenetre(LargeurFenetre, HauteurFenetre);
					break;

				case 'R':
				case 'r':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 20 millisecondes (rapide)
					demandeTemporisation(20);
					break;

				case 'L':
				case 'l':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 100 millisecondes (lent)
					demandeTemporisation(100);
					break;

				case 'S':
				case 's':
					// Configure le systeme pour ne plus generer de message Temporisation
					demandeTemporisation(-1);
					break;
			}
			break;
			
		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:
		switch(etatJeu){
			case 0:
			if (etatBoutonSouris() == GaucheAppuye){
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
				// ********bouton exit
				if (abscisseSouris() < centrex + 300 && abscisseSouris() > centrex + 100 && ordonneeSouris() < centrey + 150 && ordonneeSouris() > centrey + 50)  
				{
					termineBoucleEvenements();
				}
				// ********fin bouton exit 
				// ********Bouton Play
				if (abscisseSouris() < centrex - 100 && abscisseSouris() > centrex - 300 && ordonneeSouris() < centrey + 150 && ordonneeSouris() > centrey + 50)  //(centrex - 300 ,centrey + 50 , centrex - 100 , centrey + 150); 
				{
					etatJeu = 1;
				}
				// ********Fin Bouton Play
			}
				break;
			case 1:
				if (etatBoutonSouris() == GaucheAppuye && abscisseSouris() > 400 && ordonneeSouris() > 400)
				{
					printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
					etatJeu = 0;
				}
		}
		case Souris: // Si la souris est deplacee
			break;
		
		case Inactivite: // Quand aucun message n'est disponible
			break;
		
		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
			// Donc le systeme nous en informe
			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}
