#include "Init.h"

void Init()
{
  //INPUT
  pinMode(Capteur_de_mouvement_01, INPUT);
  pinMode(Capteur_de_mouvement_02, INPUT);

  //OUTPUT
  pinMode(Pin_Diffuseur, OUTPUT);
  pinMode(Pin_Musique, OUTPUT);
  pinMode(Pin_Alim_Musique, OUTPUT);
  pinMode(Pin_Ventilateur, OUTPUT);
  pinMode(Pin_LED, OUTPUT);
  pinMode(Pin_Souffle, OUTPUT);
  
  //Etat des pins au démarrage 
  digitalWrite(Pin_Musique, HIGH);
  digitalWrite(Pin_Alim_Musique, HIGH);
  digitalWrite(Pin_Diffuseur, LOW);
  digitalWrite(Pin_Ventilateur, LOW);
  digitalWrite(Pin_LED, LOW);
  analogWrite(Pin_Souffle,0);
}

void Timing_Warning()
{
  //Permet de communiqué sur le port série a 9600 bauds
  Serial.begin(9600);
  
  //Verification des timing
  if(Rediffusion)
  {
    if(Delay_Rediffuseur < Temps_Rediffuseur)
    {
      Serial.println("Attention Delay_Rediffuseur < Temps_Rediffuseur");
    }
    if(Delay_Rediffuseur < Temps_Diffuseur)
    {
      Serial.println("Attention Delay_Rediffuseur < Temps_Diffuseur");
    }
    if(Delay_Rediffuseur < Delay_Diffuseur)
    {
      Serial.println("Attention Delay_Rediffuseur < Delay_Diffuseur");
    }
    if(Delay_Rediffuseur > Temps_Detection_max)
    {
      Serial.println("Attention Delay_Rediffuseur > Temps_Detection_max");
    }
  }
}
