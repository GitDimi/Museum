#include "Fonction.h"

void Gestion_Capteur()
{
  //init des variables
  int Etat_du_capteur_de_mouvement01 = 0;
  int Etat_du_capteur_de_mouvement02 = 0;

  //Mise à jour de l'état du capteur
  Etat_du_capteur_de_mouvement01 = Fonction_Catpeur01();
  Etat_du_capteur_de_mouvement02 = Fonction_Catpeur02();

  //Gestion de combien de temps on va considérer qu’une personne est dans la salle en fonction des deux capteurs
  if(Etat_du_capteur_de_mouvement01 == 1 || Etat_du_capteur_de_mouvement02 == 1)
  {
    Mouvement = 1;
    Timer_Temps_Detection_max = millis();
  }
  else if(Etat_du_capteur_de_mouvement01 == 0 && Etat_du_capteur_de_mouvement02 == 0)
  {
    if(millis() - Timer_Temps_Detection_max >= Temps_Detection_max && Timer_Temps_Detection_max != 0)
    {
      Mouvement = 0;
      Timer_Temps_Detection_max = 0;
    }
  }

  //Debug
  if(Old_State_Capteur01 != Etat_du_capteur_de_mouvement01)
  {
    Serial.println("Catpeur01");
    Serial.println(Etat_du_capteur_de_mouvement01);
  }

  if(Old_State_Capteur02 != Etat_du_capteur_de_mouvement02)
  {
    Serial.println("Catpeur02");
    Serial.println(Etat_du_capteur_de_mouvement02);
  }

  
  if(Etat_du_capteur_de_mouvement01)
  {
    Old_State_Capteur01 = 1;
  }
  else
  {
    Old_State_Capteur01 = 0;
  }

  if(Etat_du_capteur_de_mouvement02)
  {
    Old_State_Capteur02 = 1;
  }
  else
  {
    Old_State_Capteur02 = 0;
  }
}

void Gestion_Lumiere()
{
  if(Mouvement)
  {
    //Au démarrage on lance le chrono du delay
    if(Old_State_Timer_Delay_Lumiere == 0)
    {
      Timer_Delay_Lumiere = millis();
      Old_State_Timer_Delay_Lumiere= 1;
    }
    //Chrono du delay
    if(millis() - Timer_Delay_Lumiere >= Delay_Lumiere && Timer_Delay_Lumiere != 0)
    {   
      //Au démarrage, après le delay, on lance le chrono du Lumière
      Fonction_Lumiere(Intensitie_Lumiere_Faible);
      Timer_Temps_Lumiere_Up = millis();
      Timer_Temps_Lumiere = millis();
      Timer_Delay_Lumiere = 0;
    }
    if(millis() - Timer_Temps_Lumiere >= Temps_Lumiere_Forte && Timer_Temps_Lumiere != 0)
    {
      Timer_Temps_Non_Lumiere = millis();
      Timer_Temps_Lumiere_Up = 0;
      Timer_Temps_Lumiere_Down = 0;
      Timer_Temps_Lumiere = 0;
      Lumiere_Down = 0;
      Lumiere_Up = 0;
      Fonction_Lumiere(Intensitie_Lumiere_Faible); 
    } 
    //Chrono de la lumière qui augmente
    else if(millis() - Timer_Temps_Lumiere_Up >= (double)1000/((double)Intensitie_Lumiere_Forte - (double)Intensitie_Lumiere_Faible) && Timer_Temps_Lumiere_Up != 0)
    {
      Lumiere_Up++;
      Fonction_Lumiere(Intensitie_Lumiere_Faible + Lumiere_Up);
      if(Lumiere_Up == (Intensitie_Lumiere_Forte - Intensitie_Lumiere_Faible))
      {
        Timer_Temps_Lumiere_Up = 0; 
        Lumiere_Up = 0;
        Timer_Temps_Lumiere_Down = millis();
      }
      else
      {
        Timer_Temps_Lumiere_Up = millis();
      }
    } 
    //Chrono de la lumière qui diminue
    else if(millis() - Timer_Temps_Lumiere_Down >= (double)(Temps_Lumiere_Forte - 1000)/((double)Intensitie_Lumiere_Forte-(double)Intensitie_Lumiere_Faible) && Timer_Temps_Lumiere_Down != 0)
    {
      Lumiere_Down++;
      Fonction_Lumiere(Intensitie_Lumiere_Forte - Lumiere_Down);
      if(Lumiere_Down == (Intensitie_Lumiere_Forte-Intensitie_Lumiere_Faible))
      {
        Timer_Temps_Lumiere_Down = 0; 
        Lumiere_Down = 0;
      }
      else
      {
        Timer_Temps_Lumiere_Down = millis();
      }
    } 
    //Chrono de la lumière qui reste faible 
    if(millis() - Timer_Temps_Non_Lumiere >= Temps_Lumiere_Faible && Timer_Temps_Non_Lumiere != 0)
    {
      Timer_Temps_Lumiere_Up = millis();
      Timer_Temps_Lumiere = millis();
      Timer_Temps_Non_Lumiere = 0;  
    } 
  }
  else
  {
    Timer_Temps_Non_Lumiere = 0;
    Timer_Temps_Lumiere_Down = 0;
    Timer_Temps_Lumiere_Up = 0;
    Timer_Delay_Lumiere = 0;
    Lumiere_Down = 0;
    Lumiere_Up = 0;
    Old_State_Timer_Delay_Lumiere = 0;
    Fonction_Lumiere(Intensitie_Lumiere_Faible); 
  }
}

void Gestion_Musique()
{
  if(Mouvement)
  {
    //Au démarrage on lance le chrono
    if(Old_State_Timer_Delay_Musique == 0)
    {
      Timer_Delay_Musique = millis();
      Old_State_Timer_Delay_Musique = 1;
    }

    //Une fois le chrono du delay est passé on lance la musique
    if(millis() - Timer_Delay_Musique >= Delay_Musique && Timer_Delay_Musique != 0)
    {
      Timer_Ajuste_Musique = millis();
      Fonction_Musique(1);
      Timer_Delay_Musique = 0;
    }
    if(Vitesse_Musique == 1)
    {
      //Chrono qui éteint la pin pour pas que la musique se relancer
      if(millis() - Timer_Ajuste_Musique >= 1000 && Timer_Ajuste_Musique != 0)
      {  
        Fonction_Musique(0);
        Timer_Stop_Musique = millis();
        Timer_Ajuste_Musique = 0;
      }
      //Chrono qui rallume la musique 
      if(millis() - Timer_Stop_Musique >= 19000 && Timer_Stop_Musique != 0)
      {  
        Fonction_Musique(1);
        Timer_Ajuste_Musique = millis();
        Timer_Stop_Musique = 0;
      }
    }
    else if(Vitesse_Musique == 2)
    {
      //Chrono qui éteint la pin pour pas que la musique se relancer
      if(millis() - Timer_Ajuste_Musique >= 1000 && Timer_Ajuste_Musique != 0)
      {  
        Fonction_Musique(0);
        Timer_Stop_Musique = millis();
        Timer_Ajuste_Musique = 0;
      }
      //Chrono qui rallume la musique 
      if(millis() - Timer_Stop_Musique >= 14000 && Timer_Stop_Musique != 0)
      {  
        Fonction_Musique(1);
        Timer_Ajuste_Musique = millis();
        Timer_Stop_Musique = 0;
      }
    }
  }
  else
  {
    Fonction_Musique(0);
    Old_State_Timer_Delay_Musique = 0;
    Timer_Delay_Musique = 0;
    Timer_Ajuste_Musique = 0;
  }
}

void Gestion_Souffle()
{
  if(Mouvement)
  {
    //Au démarrage on lance le chrono du delay
    if(Old_State_Timer_Delay_Souffle == 0)
    {
      Timer_Delay_Souffle = millis();
      Old_State_Timer_Delay_Souffle = 1;
    }
    //Au démarrage, après le delay, on lance le chrono du souffle
    if(millis() - Timer_Delay_Souffle >= Delay_Souffle && Timer_Delay_Souffle != 0)
    {   
      Timer_Temps_Souffle = millis();
      Fonction_Souffle(1);
      Timer_Delay_Souffle = 0;
    }
    //Chrono du souffle allumé 
    if(millis() - Timer_Temps_Souffle >= Temps_Souffle && Timer_Temps_Souffle != 0)
    {
      Fonction_Souffle(0);
      Timer_Temps_Non_Souffle = millis();
      Timer_Temps_Souffle = 0;
    }
    //Chrono du souffle éteint
    else if(millis() - Timer_Temps_Non_Souffle >= Temps_Non_Souffle && Timer_Temps_Non_Souffle != 0)
    {
      Timer_Temps_Souffle = millis();
      Timer_Temps_Non_Souffle = 0;  
      Fonction_Souffle(1); 
    } 
  }
  else
  {
    Old_State_Timer_Delay_Souffle = 0;
    Timer_Temps_Non_Souffle = 0;
    Timer_Temps_Souffle = 0;
    Timer_Delay_Souffle = 0;
    Fonction_Souffle(0);
  }
}

void Gestion_Diffusion()
{
  if(Mouvement)
  {
    //Au démarrage on lance le chrono du delay
    if(Old_State_Timer_Delay_Diffuseur == 0)
    {
      Timer_Delay_Diffuseur = millis();
      Old_State_Timer_Delay_Diffuseur= 1;
    }
    if(millis() - Timer_Delay_Diffuseur >= Delay_Diffuseur && Timer_Delay_Diffuseur != 0)
    {   
      //Au démarrage, après le delay, on lance le chrono du diffuseur
      Timer_Temps_Diffuseur = millis();
      State_Diffuseur = 0;
      Timer_Mouvement_Moteur = millis();
      Timer_Delay_Diffuseur = 0;
    }  
    //Chrono du diffuseur allumé
    if(millis() - Timer_Temps_Diffuseur >= Temps_Diffuseur && Timer_Temps_Diffuseur != 0)
    {
      State_Diffuseur = 1;
      Timer_Mouvement_Moteur = millis();
      Timer_Temps_Non_Diffuseur = millis();
      Timer_Temps_Diffuseur = 0;
    }
    //Chrono du diffuseur éteint
    else if(millis() - Timer_Temps_Non_Diffuseur >= Temps_Non_Diffuseur && Timer_Temps_Non_Diffuseur != 0)
    {
      State_Diffuseur = 0;
      Timer_Mouvement_Moteur = millis();
      Timer_Temps_Diffuseur = millis();
      Timer_Temps_Non_Diffuseur = 0;  
    } 
    //On ferme
    if(State_Diffuseur == 0)
    {
      if(millis() - Timer_Mouvement_Moteur >= Temps_Moteur)
      {
        Timer_Mouvement_Moteur = Temps_Moteur;
        Fonction_Moteur_Fermeture(0);
        Moteur_Security = 0;
      }
      else
      {
        Fonction_Moteur_Fermeture(1);
        Moteur_Security = 1;
      }
    }
    //On ouvre
    else if(State_Diffuseur == 1)
    {
      if(millis() - Timer_Mouvement_Moteur >= Temps_Moteur)
      {
        Timer_Mouvement_Moteur = Temps_Moteur;
        Fonction_Moteur_Ouverture(0);
        Moteur_Security = 3;
      }
      else
      {
        Fonction_Moteur_Ouverture(1);
        Moteur_Security = 2;
      }
    }
    else if(State_Diffuseur == 2)
    {
      Fonction_Moteur_Ouverture(0);
      Fonction_Moteur_Fermeture(0);
    }
  }
  else
  {
    Old_State_Timer_Delay_Diffuseur = 0;
    Timer_Temps_Non_Diffuseur = 0;
    Timer_Temps_Diffuseur = 0;
    Timer_Delay_Diffuseur = 0;

    if(Moteur_Security == 0)
    {
      Timer_Mouvement_Moteur = 0;
      State_Diffuseur = 2;
      Fonction_Moteur_Ouverture(0);
      Fonction_Moteur_Fermeture(0);
    }
    else if(Moteur_Security == 1)
    {
      if(millis() - Timer_Mouvement_Moteur >= Temps_Moteur && Timer_Mouvement_Moteur != 0)
      {
        Timer_Mouvement_Moteur = 0;
        Fonction_Moteur_Fermeture(0);
        Moteur_Security = 0;
      }
      Fonction_Moteur_Fermeture(1);
    }
    else if(Moteur_Security == 2)
    {
      Fonction_Moteur_Ouverture(0);
      if(Temps_Moteur - (millis() - Timer_Mouvement_Moteur) >= Temps_Moteur && Timer_Mouvement_Moteur != 0)
      {
        Timer_Mouvement_Moteur = 0;
        Fonction_Moteur_Fermeture(0);
        Moteur_Security = 0;
      }
      Fonction_Moteur_Fermeture(1);
    }
    else if(Moteur_Security == 3)
    {
      if(Old_State_Security_Diffuseur == 0)
      {
        Timer_Mouvement_Moteur = millis();
        Old_State_Security_Diffuseur= 1;
      }
      if(millis() - Timer_Mouvement_Moteur >= Temps_Moteur && Timer_Mouvement_Moteur != 0)
      {
        Timer_Mouvement_Moteur = 0;
        Fonction_Moteur_Fermeture(0);
        Moteur_Security = 0;
      }
      Fonction_Moteur_Fermeture(1);
    }
  }
}

void Gestion_Ventilateur()
{
  if(Mouvement)
  {
    //Au démarrage on lance le chrono du delay
    if(Old_State_Timer_Delay_Ventilateur == 0)
    {
      Timer_Delay_Ventilateur = millis();
      Old_State_Timer_Delay_Ventilateur= 1;
    }
    if(millis() - Timer_Delay_Ventilateur >= Delay_Ventilateur && Timer_Delay_Ventilateur != 0)
    {   
      //Au démarrage, après le delay, on lance le chrono du Ventilateur
      Timer_Delay_Ventilateur = 0;
      Timer_Temps_Ventilateur = millis();
      Fonction_Ventilateur(1);
    }
    //Chrono du ventilateur allumé
    if(millis() - Timer_Temps_Ventilateur >= Temps_Ventilateur && Timer_Temps_Ventilateur != 0)
    {
      Fonction_Ventilateur(0);
      Timer_Temps_Non_Ventilateur = millis();
      Timer_Temps_Ventilateur = 0;
    }
    //Chrono du ventilateur éteint
    else if(millis() - Timer_Temps_Non_Ventilateur >= Temps_Non_Ventilateur && Timer_Temps_Non_Ventilateur != 0)
    {
      Timer_Temps_Ventilateur = millis();
      Timer_Temps_Non_Ventilateur = 0;  
      Fonction_Ventilateur(1); 
    } 
  }
  else
  {
    Old_State_Timer_Delay_Ventilateur = 0;
    Timer_Delay_Ventilateur = 0;
    Timer_Temps_Non_Ventilateur = 0;
    Timer_Temps_Ventilateur = 0;

    Fonction_Ventilateur(0);
  }
}

void Gestion_Deshumidificateur()
{
  //S’il y a du monde dans la salle on arrête tout
  if(Mouvement)
  {
    Fonction_Deshumidificateur(0);
    Old_State_Timer_Delay_Deshumidificateur = 0;
    Timer_Delay_Deshumidificateur = 0;

  }
  else
  {
    //S’il a plus personne on lance le chrono
    if(Old_State_Timer_Delay_Deshumidificateur == 0)
    {
      Timer_Delay_Deshumidificateur = millis();
      Old_State_Timer_Delay_Deshumidificateur = 1;
    }

    //Une fois le delay passé on allume le déshumidificateur 
    if(millis() - Timer_Delay_Deshumidificateur >= Delay_Deshumidificateur && Timer_Delay_Deshumidificateur != 0)
    {
      Fonction_Deshumidificateur(1);
      Timer_Delay_Deshumidificateur = 0;
    }
  }
}

void Gestion_LED()
{
  if(Mouvement)
  {
    Fonction_LED(1);
  }
  else
  {
    Fonction_LED(0);
  }
}

