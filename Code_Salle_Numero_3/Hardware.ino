#include "Hardware.h"

bool Fonction_Catpeur01()
{
  if(Detecteur_1)
  {
    return digitalRead(Capteur_de_mouvement_01);
  }
  else
  {
    return 0;
  }
}

bool Fonction_Catpeur02()
{
  if(Detecteur_2)
  {
    return digitalRead(Capteur_de_mouvement_02);
  }
  else
  {
    return 0;
  }
}

void Fonction_Diffuseur(bool state)
{
  if(Diffuseur)
  {
    if(state == 1)
    {
      digitalWrite(Pin_Diffuseur, HIGH);
    }
    else
    {
      digitalWrite(Pin_Diffuseur, LOW);
    }
  }
  else 
  {
    digitalWrite(Pin_Diffuseur, LOW);
  }
}

void Fonction_Musique(bool state)
{
  if(Musique)
  {
    if(state == 1)
    {
      digitalWrite(Pin_Musique, LOW);
    }
    else
    {
      digitalWrite(Pin_Musique, HIGH);
    }
  }
  else
  {
    digitalWrite(Pin_Musique, HIGH);
  }
}

void Fonction_Ventilateur(bool state)
{
  if(Ventilateur)
  {
    if(state == 1)
    {
      digitalWrite(Pin_Ventilateur, HIGH);
    }
    else
    {
      digitalWrite(Pin_Ventilateur, LOW);  
    }
  }
  else
  {
    digitalWrite(Pin_Ventilateur, LOW);  
  }
}

void Fonction_Souffle(int state)
{
  if(Souffle)
  {
    analogWrite(Pin_Souffle,state);
  }
  else
  {
    analogWrite(Pin_Souffle,0);
  }
}

void Fonction_LED(bool state)
{
  if(LED)
  {
    digitalWrite(Pin_LED,state);
  }
  else
  {
    digitalWrite(Pin_LED,0);
  }
}
