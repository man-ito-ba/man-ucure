// Github : https://github.com/man-ito-ba/man-ucure
// Projet 123D.circuits.io : https://circuits.io/circuits/2409875

#include <LiquidCrystal.h>				// bibliothèque de contrôle de l'écran LCD

const int Sec = 1000;					// variable pratique pour gérer les secondes

int Led = 13;							// UI : Leds indiquant qu'on se fait cramer les ongles
int Selecteur_Durees = 8;				// Bouton utilisateur : programmer la durée de grillage des ongles
bool Etat_Selecteur;					// Variable d'état du sélecteur de durée
int Duree;								// Variable de durée contrôlant le temps d'allumage des Leds
int Start_Button = 9;					// Bouton utilisateur :	lancer le grille-pain 
bool Etat_Start;						// Variable d'état du bouton start

LiquidCrystal LCD(12,11,5,4,3,2);		// pins connectés au LCD

void setup()
{
	LCD.begin(16,2);					// initialisation de la communication avec 16 colonnes et 2 lignes
		LCD.clear();					// on efface l'écran
		LCD.print("Orteils  2.0  :)");
		LCD.setCursor(0,1);				// on met le curseur sur la deuxième ligne à gauche
		LCD.print("----------------");
		delay(1*Sec);
		LCD.clear();

	pinMode(Selecteur_Durees, INPUT);	// les deux pins des boutons en entrée
	pinMode(Start_Button, INPUT);

	pinMode(Led, OUTPUT);
	digitalWrite(Led, LOW);
	Etat_Selecteur, Etat_Start, Duree = 0;
}

void loop()
{
	Etat_Selecteur = digitalRead(Selecteur_Durees);
	if(Etat_Selecteur)					// si le bouton de sélection de durée est appuyé, on rajoute 30 secondes de chauffe
	{
		Duree = Duree + 30;
		if(Duree > 90)
		{
			Duree = 0;					// on revient à 0 si on appuie plus de 3 fois
		}
		Affichage(Duree);				// avec cette fonction, on affiche le temps sélectionné sur le LCD
		Etat_Selecteur = 0;
	}

	Etat_Start = digitalRead(Start_Button);
	if(Etat_Start)						// si le bouton start est sélectionné
	{
		digitalWrite(Led, HIGH);		// on allume les Leds
		Decompte(Duree);				// on lance le compte à rebour sur le LCD
		digitalWrite(Led, LOW);
			delay(Sec/5);
			LCD.print("Fin !");
			LCD.setCursor(0,1);
			LCD.print(":)");
			delay(2*Sec);
			LCD.clear();
		Duree = 0;
		Etat_Start = 0;
	}
	delay(10);
}

void Affichage(int Duree)
{										// fonction d'affichage des durées sélectionnées
	LCD.print("Duree : ");
	LCD.setCursor(11,1);				// on place le curseur sur la première ligne tout à droite
	LCD.print(Duree);
	LCD.setCursor(14,1);
	LCD.print("s.");
	delay(1.5*Sec);
	LCD.clear();
}

void Decompte(int Duree)				
{										// fonction de compte à rebour
	for(int i=Duree; i > 0; i--){		// compte à rebour avec la fonction de temporisation
		LCD.print("Temps");
		LCD.setCursor(0,1);
		LCD.print("restant :");
		LCD.setCursor(11,1);
		LCD.print(i,DEC);
		LCD.setCursor(14,1);
		LCD.print("s.");
		delay(Sec);
		LCD.clear();
	}
	return;
}