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
  digitalWrite(Pin_Moteur_Fermeture, LOW);
  digitalWrite(Pin_Moteur_Ouverture, LOW);
  digitalWrite(Pin_Souffle,LOW);
  digitalWrite(Pin_Ventilateur, LOW);
  digitalWrite(Pin_Deshumidificateur, LOW);
  digitalWrite(Pin_LED, LOW);

  //Permet de communiqué sur le port série a 9600 bauds
  Serial.begin(9600);

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

    Serial.println("Catpeur01");
    Serial.println(digitalRead(Capteur_de_mouvement_02));
    Serial.println("Catpeur02");
    Serial.println(digitalRead(Capteur_de_mouvement_02));
  } 
  
  Serial.println("Capteurs prêt");

  //Pour éviter que les timers prennent comme 1ère valeur 0 dans le millis();
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

  if(Vitesse_Musique == 1)
  {
    if(Temps_Inspiration + Temps_Expiration != 20000)
    {
      Serial.println("La musique et la respiration ne sont pas sycro");
    }
  }
  else if(Vitesse_Musique == 2)
  {
    if(Temps_Inspiration + Temps_Expiration != 15000)
    {
      Serial.println("La musique et la respiration ne sont pas sycro");
    }
  }

  if(Temps_Inspiration + Temps_Expiration - Delay_Lumiere < 0)
  {
    Serial.println("Delay_Lumiere problèmatique");
  }

  if(Temps_Inspiration + Temps_Expiration - Delay_Ventilateur < 0)
  {
    Serial.println("Delay_Ventilateur problèmatique");
  }

  if(Temps_Inspiration + Temps_Expiration - Delay_Diffuseur < 0)
  {
    Serial.println("Delay_Diffuseur problèmatique");
  }

  if(Temps_Inspiration + Temps_Expiration - Delay_Souffle < 0)
  {
    Serial.println("Delay_Souffle problèmatique");
  }

  if(Temps_Inspiration + Temps_Expiration - Delay_Musique < 0)
  {
    Serial.println("Delay_Musique problèmatique");
  }

  if(Temps_Detection_max < 0 || Temps_Inspiration  < 0 || Temps_Expiration  < 0 || Delay_Musique  < 0 || Delay_Souffle  < 0 || Delay_Diffuseur  < 0 || Delay_Ventilateur  < 0 || Delay_Lumiere  < 0 || Delay_Deshumidificateur  < 0)
  {
    Serial.println("Valeur negative !");
  }

  if(Temps_Souffle != Temps_Expiration || Temps_Diffuseur != Temps_Expiration || Temps_Ventilateur != Temps_Expiration || Temps_Lumiere_Forte != Temps_Expiration)
  {
    Serial.println("Valeur de calcule.h modifié ! Temps_Expiration");
  }

  if(Temps_Non_Souffle  != Temps_Inspiration || Temps_Non_Diffuseur  != Temps_Inspiration || Temps_Non_Ventilateur  != Temps_Inspiration || Temps_Lumiere_Faible  != Temps_Inspiration)
  {
    Serial.println("Valeur de calcule.h modifié ! Temps_Inspiration");
  }
}


