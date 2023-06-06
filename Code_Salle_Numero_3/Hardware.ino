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

void Fonction_Lumiere(int state)
{
  if(Lumiere)
  {
      analogWrite(Pin_Lumiere,state);
  }
  else
  {
      analogWrite(Pin_Lumiere,0);
  }
}

void Fonction_Musique(bool state)
{
  if(Musique)
  {
    if(state)
    {
      if(Vitesse_Musique == 1)
      {
        digitalWrite(Pin_Musique1, LOW);
      }
      else if(Vitesse_Musique == 2)
      {
        digitalWrite(Pin_Musique2, LOW);
      }
      else if(Vitesse_Musique == 3)
      {
        digitalWrite(Pin_Musique3, LOW);
      }
    }
    else
    {
      digitalWrite(Pin_Musique1, HIGH);
      digitalWrite(Pin_Musique2, HIGH);
      digitalWrite(Pin_Musique3, HIGH);
    }
  }
  else
  {
    digitalWrite(Pin_Musique1, HIGH);
    digitalWrite(Pin_Musique2, HIGH);
    digitalWrite(Pin_Musique3, HIGH);
  }
}

void Fonction_Souffle(bool state)
{
  if(Souffle)
  {
    if(state)
    {
      digitalWrite(Pin_Souffle,HIGH);
    }
    else
    {
      digitalWrite(Pin_Souffle,LOW);
    }
  }
  else
  {
    digitalWrite(Pin_Souffle,LOW);
  }
}

void Fonction_Moteur_Fermeture(bool state)
{
  if(Diffuseur)
  {
    if(state == 1)
    {
      digitalWrite(Pin_Moteur_Fermeture, HIGH);
    }
    else
    {
      digitalWrite(Pin_Moteur_Fermeture, LOW);
    }
  }
  else 
  {
    digitalWrite(Pin_Moteur_Fermeture, LOW);
  }
}

void Fonction_Moteur_Ouverture(bool state)
{
  if(Diffuseur)
  {
    if(state == 1)
    {
      digitalWrite(Pin_Moteur_Ouverture, HIGH);
    }
    else
    {
      digitalWrite(Pin_Moteur_Ouverture, LOW);
    }
  }
  else 
  {
    digitalWrite(Pin_Moteur_Ouverture, LOW);
  }
}

void Fonction_Ventilateur(bool state)
{
  if(Ventilateur)
  {
    if(state)
    {
      digitalWrite(Pin_Ventilateur,HIGH);
    }
    else
    {
      digitalWrite(Pin_Ventilateur,LOW);
    }
  }
  else
  {
    digitalWrite(Pin_Ventilateur,LOW);
  }
}

void Fonction_Deshumidificateur(bool state)
{
  if(Deshumidificateur)
  {
    if(state == 1)
    {
      digitalWrite(Pin_Deshumidificateur, HIGH);
    }
    else
    {
      digitalWrite(Pin_Deshumidificateur, LOW);  
    }
  }
  else
  {
    digitalWrite(Pin_Deshumidificateur, LOW);  
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
