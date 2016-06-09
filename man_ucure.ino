/*Déclarations*/
	//Déclaration de la broche contrôlant les Leds
	int Led=13;
	//Déclaration des broches de Switchs
	int Switchs[]={8,9,10};
	//Déclaration de la broche du bouton de lancement de séquence
	int BoutonAllumage=5;
	//Variables
		int EtatSwitch[3]; //État des switchs (ce sera 1 ou 0)
		int EtatBouton; //État du bouton (ce sera 1 ou 0)
	//Variables pratiques
		int Sec=1000; 
		//pour utiliser des "secondes" quand je dois utiliser des temps

void setup()
{
	//initialisation des Leds : broches en sortie et 0V
	pinMode(Led, OUTPUT);
		digitalWrite(Led, LOW);
	//initialisation des Switchs
	for(int i=0; i<3; i++){
		pinMode(Switchs[i], INPUT);
		EtatSwitch[i]=0;
	}
	//initialisation des variables
	EtatBouton=0;
	//communication Port Série
	Serial.begin(9600);
	Serial.println("Start");
}

void loop()
{
	for(int i=0; i<3; i++){
	    EtatSwitch[i]=digitalRead(Switchs[i]);
	}
	EtatBouton=digitalRead(BoutonAllumage);
	if(EtatBouton){
	    if(EtatSwitch[0]){
	        digitalWrite(Led, HIGH);
	        delay(3*Sec);
	    	digitalWrite(Led, LOW);
	    }
	    else if(EtatSwitch[1]){
	        digitalWrite(Led, HIGH);
	        delay(6*Sec);
	    	digitalWrite(Led, LOW);
	    }
	    else if(EtatSwitch[2]){
	        digitalWrite(Led, HIGH);
	        delay(9*Sec);
	    	digitalWrite(Led, LOW);
	    }
	}
}
/*
- je mets 3 au lieu de 30 pour pas poireauter alors que je ne fais que tester le programme
- pour l'instant, je ne me suis pas occuper de savoir ce qui se passerait si plusieurs switchs sont mis en position haute en même temps
Ça signifie que c'est toujours la valeur du switch le plus faible qui est pris en compte pour la durée d'allumage
*/

//En dessous, je te mets des variantes de code possibles
/*
//Ici, le code fait que les durées s'ajoutent. Donc on pourrait proposer "30 sec" par switch allumés.
//Si les utilisateurs en activent deux, ben ça donne 30+30 sec par ex. 
//Ici je te montre l'exemple avec des durées de 3 secondes.
void loop()
{
	for(int i=0; i<3; i++){
	    EtatSwitch[i]=digitalRead(Switchs[i]);
	}
	EtatBouton=digitalRead(BoutonAllumage);
	if(EtatBouton){
	    if(EtatSwitch[0]){
	        digitalWrite(Led, HIGH);
	        delay(3*Sec);
	    	digitalWrite(Led, LOW);
	    }
	    else if(EtatSwitch[1]){
	        digitalWrite(Led, HIGH);
	        delay(3*Sec);
	    	digitalWrite(Led, LOW);
	    }
	    else if(EtatSwitch[2]){
	        digitalWrite(Led, HIGH);
	        delay(3*Sec);
	    	digitalWrite(Led, LOW);
	    }
	}
}
*/
