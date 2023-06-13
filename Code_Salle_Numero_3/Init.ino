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
  pinMode(Pin_Musique4, OUTPUT);
  pinMode(Pin_Lumiere_DMX, OUTPUT);
  pinMode(Pin_Moteur_Fermeture,OUTPUT);
  pinMode(Pin_Moteur_Ouverture,OUTPUT);
  pinMode(Pin_Souffle, OUTPUT);
  pinMode(Pin_Ventilateur, OUTPUT);  
  pinMode(Pin_Deshumidificateur, OUTPUT);  
  pinMode(Pin_LED, OUTPUT);
  
  //Etat des pins au démarrage 
  analogWrite(Pin_Lumiere,Intensitie_Lumiere_Faible);
  digitalWrite(Pin_Musique1, HIGH);
  digitalWrite(Pin_Musique2, HIGH);
  digitalWrite(Pin_Musique3, HIGH);
  digitalWrite(Pin_Musique4, HIGH);
  digitalWrite(Pin_Lumiere_DMX, LOW);
  digitalWrite(Pin_Moteur_Fermeture, LOW);
  digitalWrite(Pin_Moteur_Ouverture, LOW);
  digitalWrite(Pin_Souffle,LOW);
  digitalWrite(Pin_Ventilateur, LOW);
  digitalWrite(Pin_Deshumidificateur, HIGH);
  digitalWrite(Pin_LED, LOW);

  //Permet de communiqué sur le port série a 9600 bauds
  Serial.begin(9600);

  if(Mode_Test == 1)
  {
    Serial.println("Mode test capteur a 1 en continu");
  }
  else
  {
    Serial.println("Attente de mise a 0 des capteurs");
  
    while(digitalRead(Capteur_de_mouvement_02) == 1 || digitalRead(Capteur_de_mouvement_01) == 1)
    {
      delay(100);
  
      if(Led_Blink == 0)
      {
        Led_Blink = 1;
        digitalWrite(Pin_LED, HIGH);
      }
      else
      {
        Led_Blink = 0;
        digitalWrite(Pin_LED, LOW);
      }
  
      Serial.println("Catpeur01 Init");
      Serial.println(digitalRead(Capteur_de_mouvement_02));
      Serial.println("Catpeur02 Init");
      Serial.println(digitalRead(Capteur_de_mouvement_02));
    } 
    
    Serial.println("Capteurs prêt");
  }

  //Pour éviter que les timers prennent comme 1ère valeur 0 dans le millis();
  delay(1);
}

void Timing_Warning()
{ 
  //Verification des timing
  if(Temps_Inspiration + Temps_Expiration != 15000)
  {
     Serial.println("Erreur Temps_Inspiration + Temps_Expiration =! 15000");
  }

  if(Intensitie_Lumiere_Forte > 255 || Intensitie_Lumiere_Forte < 0)
  {
     Serial.println("Valeur de Intensitie_Lumiere_Fort problématique");
  }
 
  if(Intensitie_Lumiere_Faible > 255 || Intensitie_Lumiere_Forte < 0)
  {
     Serial.println("Valeur de Intensitie_Lumiere_Faible problématique");
  }

  if(Detecteur_1 == 0 && Detecteur_2 == 0)
  {
    Serial.println("Aucun capteur activé");
  }

  if(Temps_Inspiration + Temps_Expiration - Delay_Lumiere_Start < 0 || Delay_Lumiere_Start < 0)
  {
    Serial.println("Delay_Lumiere problématique");
  }

  if(Temps_Inspiration + Temps_Expiration - Delay_Ventilateur_Start < 0 || Delay_Ventilateur_Start < 0)
  {
    Serial.println("Delay_Ventilateur problématique");
  }

  if(Temps_Inspiration + Temps_Expiration - Delay_Diffuseur_Start < 0 || Delay_Diffuseur_Start < 0)
  {
    Serial.println("Delay_Diffuseur problématique");
  }

  if(Temps_Inspiration + Temps_Expiration - Delay_Souffle_Start < 0 || Delay_Souffle_Start < 0)
  {
    Serial.println("Delay_Souffle problématique");
  }

  if(Temps_Inspiration + Temps_Expiration - Delay_Musique_Start < 0 || Delay_Musique_Start < 0)
  {
    Serial.println("Delay_Musique problématique");
  }

  if(Temps_Souffle != Temps_Expiration)
  {
    Serial.println("Valeur de calcule.h modifié ! Temps_Souffle");
  }

  if(Security_Souffle >= Temps_Inspiration)
  {
    Serial.println("Security_Souffle chevauche Temps_Inspiration");
  }

  if(Vitesse_Ventilateur < 0 || Vitesse_Ventilateur > 100)
  {
    Serial.println("Vitesse_Ventilateur problématique");
  }

  if(Temps_Lumiere_Forte + Temps_Lumiere_Faible + Temps_Lumiere_Pause != Temps_Inspiration + Temps_Expiration)
  {
    Serial.println("Temps_Lumiere_Forte + Temps_Lumiere_Faible + Temps_Lumiere_Pause != Temps_Inspiration + Temps_Expiration");
  }
  
  if(Delay_Deshumidificateur < 0 || Temps_Lumiere_Forte < 0 || Temps_Lumiere_Faible < 0 || Temps_Lumiere_Pause < 0 || Temps_Inspiration < 0 || Temps_Expiration < 0 || Security_Souffle < 0 || Temps_Detection_max < 0 || Mode_Test < 0)
  {
    Serial.println("Valeur négative");
  }
}


