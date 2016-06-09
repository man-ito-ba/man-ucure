//Déclaration
//Déclaration des broches de Leds
int LedRouge=2;
int LedVerte=3;
//Déclaration des broches de Switchs
int Switch1=8;
int Switch2=9;
//Variables de l'état des swithcs (1 ou 0)
int EtatSwitch1;
int EtatSwitch2;
//Variables pratiques
int Sec=1000; //pour utiliser des "secondes" quand je dois utiliser des temps

void setup()
{
	//initialisation des Leds
	pinMode(LedRouge, OUTPUT);
		digitalWrite(LedRouge, LOW);
	pinMode(LedVerte, OUTPUT);
		digitalWrite(LedVerte, LOW);
	//initialisation des Switchs
	pinMode(Switch1, INPUT);
	pinMode(Switch2, INPUT);
	//initialisation des variables
	EtatSwitch1=0;
	EtatSwitch2=0;
	//communication Port Série
	Serial.begin(9600);
	Serial.println("Start");
}

void loop()
{
	//Switch 1 / LED rouge
		EtatSwitch1=digitalRead(Switch1);
		Serial.print("Switch 1 : ");
		Serial.println(EtatSwitch1);//J'ai remarqué que si j'essayais de lire la valeur du switch directement au niveau du pin8 (Switch1) sans passer par une variable qui l'enregistrait avant, ça me donnait des chiffres très difficile à utiliser, car ils ne changent pas d'état... Je sais pas pourquoi la variable EtatSwitch1 change elle d'état.
		digitalWrite(LedRouge, EtatSwitch1);
	//Switch 2 / LED verte
		EtatSwitch2=digitalRead(Switch2);
		Serial.print("Switch 2 : ");
		Serial.println(EtatSwitch2);
		digitalWrite(LedVerte, EtatSwitch2);
	//Fin de la boucle
	Serial.println("End");
	delay(1*Sec);
}
