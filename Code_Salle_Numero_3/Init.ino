#include "Init.h"

void Init()
{
  //INPUT
  pinMode(Capteur_de_mouvement_01, INPUT);
  pinMode(Capteur_de_mouvement_02, INPUT);

  //OUTPUT
  pinMode(Pin_Lumiere, OUTPUT);  
  pinMode(Pin_Musique1, OUTPUT);
  pinMode(Pin_Musique2, OUTPUT);
  pinMode(Pin_Musique3, OUTPUT);
  pinMode(Pin_Diffuseur,OUTPUT);
  pinMode(Pin_Souffle, OUTPUT);
  pinMode(Pin_Ventilateur, OUTPUT);  
  pinMode(Pin_Deshumidificateur, OUTPUT);  
  pinMode(Pin_LED, OUTPUT);
  
  //Etat des pins au démarrage 
  analogWrite(Pin_Lumiere,0);
  digitalWrite(Pin_Musique1, HIGH);
  digitalWrite(Pin_Musique2, HIGH);
  digitalWrite(Pin_Musique3, HIGH);
  digitalWrite(Pin_Diffuseur, LOW);
  analogWrite(Pin_Souffle,0);
  digitalWrite(Pin_Ventilateur, LOW);
  digitalWrite(Pin_Deshumidificateur, LOW);
  digitalWrite(Pin_LED, LOW);

  //Permet de communiqué sur le port série a 9600 bauds
  Serial.begin(9600);

  Serial.println("Attente de mise a 0 des capteurs");

  while(digitalRead(Capteur_de_mouvement_02) == 1 || digitalRead(Capteur_de_mouvement_01) == 1)
  {
    Serial.println("Catpeur01");
    Serial.println(digitalRead(Capteur_de_mouvement_02));
    Serial.println("Catpeur02");
    Serial.println(digitalRead(Capteur_de_mouvement_02));
  } 
  
  Serial.println("Capteurs prêt");

  //Pour eviter que les timers perenne comme 1ère valeur 0 dans le millis();
  delay(1);
}

void Timing_Warning()
{ 
  //Verification des timing
  if(Intensitie_Lumiere_Forte > 255 || Intensitie_Lumiere_Forte < 0)
  {
     Serial.println("Valeur de Intensitie_Lumiere_Fort problèmatique");
  }
 
  if(Intensitie_Lumiere_Faible > 255 || Intensitie_Lumiere_Forte < 0)
  {
     Serial.println("Valeur de Intensitie_Lumiere_Faible problèmatique");
  }

  if(Vitesse_Musique > 3 || Vitesse_Musique <= 0)
  {
    Serial.println("Valeur de Vitesse_Musique problèmatique");
  }

  if(Detecteur_1 == 0 && Detecteur_2 == 0)
  {
    Serial.println("Aucun capteur activé");
  }
}
