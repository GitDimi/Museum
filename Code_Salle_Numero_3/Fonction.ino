#include "Fonction.h"

void Gestion_Capteur()
{
  //init des variables
  int Etat_du_capteur_de_mouvement01 = 0;
  int Etat_du_capteur_de_mouvement02 = 0;

  //Mise à jour de l'état du capteur
  Etat_du_capteur_de_mouvement01 = Fonction_Catpeur01();
  Etat_du_capteur_de_mouvement02 = Fonction_Catpeur02();

  //Gestion de combien de temps on va considérer qu'un personne est dans la salle en fonction des deux capteurs
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
      Fonction_Musique(1);
      //En fonction du mode on va la relancer ou pas 
      if(!RePlay)
      {
        //Plus de 125ms pour que la musique se lance
        delay(150);
        Fonction_Musique(0);
      }
      Timer_Delay_Musique = 0;
    }
    Old_State_No_Mouvement = 0;
  }
  else
  {
    Fonction_Musique(0);
    //Quand on change l'état de personne détecté a plus personne dans la salle
    if(Old_State_No_Mouvement == 0)
    {
      //Gestion de la fin de la musique 
      if(StopPlay)
      {
        digitalWrite(Pin_Alim_Musique, LOW);
        delay(1);
        digitalWrite(Pin_Alim_Musique, HIGH);
      }

      Old_State_No_Mouvement = 1;
      Old_State_Timer_Delay_Musique = 0;
    }
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
    if(millis() - Timer_Delay_Souffle >= Delay_Souffle && Timer_Delay_Souffle != 0)
    {   
      //Au démarrage, après le delay, on lance le chrono du souffle
      if(Old_State_Timer_Temps_Souffle == 0)
      {
        Timer_Temps_Souffle = millis();
        Old_State_Timer_Temps_Souffle = 1;
      }
      //on rentre dans ce timer à chaque fois que le souffle diminu de 1 (Compteur_Souffle). 
      if(millis() - Timer_Temps_Souffle >= (double)Temps_Souffle/(double)255 && Timer_Temps_Souffle != 0)
      {
        Compteur_Souffle ++;
        Fonction_Souffle(-Compteur_Souffle+255);
        if(Compteur_Souffle == 255)
        {
          Timer_Temps_Souffle = 0;
          Compteur_Souffle = 0;
          Timer_Temps_Non_Souffle = millis();
          Fonction_Souffle(0);
        }
        else
        {
         Timer_Temps_Souffle = millis();   
        }
      }
      else if(millis() - Timer_Temps_Non_Souffle >= Temps_Non_Souffle && Timer_Temps_Non_Souffle != 0)
      {
        Timer_Temps_Souffle = millis();
        Timer_Temps_Non_Souffle = 0;    
      } 
    }
  }
  else
  {
    Old_State_Timer_Delay_Souffle = 0;
    Old_State_Timer_Temps_Souffle = 0;
    Timer_Temps_Non_Souffle = 0;
    Timer_Temps_Souffle = 0;
    Timer_Delay_Souffle = 0;
    Fonction_Souffle(0);
  }
}

void Gestion_Ventilateur()
{
  //S’il y a du monde dans la salle on arrête tout
  if(Mouvement)
  {
    Fonction_Ventilateur(0);
    Old_State_Timer_Delay_Ventilateur = 0;
  }
  else
  {
    //S’il a plus personne on lance le chrono
    if(Old_State_Timer_Delay_Ventilateur == 0)
    {
      Timer_Delay_Ventilateur = millis();
      Old_State_Timer_Delay_Ventilateur = 1;
    }

    //Une fois le delay passé on allume le ventilateur 
    if(millis() - Timer_Delay_Ventilateur >= Delay_Ventilateur && Timer_Delay_Ventilateur != 0)
    {
      //Allumage du ventilateur
      Fonction_Ventilateur(1);
      //On stop ce chrono
      Timer_Delay_Ventilateur = 0;
    }
  }
}

void Gestion_Diffusion()
{
  if(Mouvement)
  {
    //Gestion des deux modes de diffusion possible
    if(Rediffusion)
    {
      //Gestion de la rediffusion
      Gestion_Rediffusion();
    }
    else
    {
      //Gestion de la diffusion
      Gestion_Diffusion_Normal();
    }
  }
  else
  {
    //Autrement on arrête bien tout
    Fonction_Diffuseur(0);
    Timer_Delay_Diffuseur = 0;
    Timer_Temps_Diffuseur = 0;
    Timer_Delay_Rediffuseur = 0;
    Timer_Temps_Rediffuseur = 0;
    Old_State_Diffusion = 0;
  }
}

void Gestion_Diffusion_Normal()
{
  //Quand on change l'état de personne détecté a plus personne dans la salle
  if(Old_State_Diffusion == 0)
  {
    //On lance le chrono
    Timer_Delay_Diffuseur = millis();
    Old_State_Diffusion = 1;
  }

  //Quand le delay du diffuseur est passé
  if(millis() - Timer_Delay_Diffuseur >= Delay_Diffuseur && Timer_Delay_Diffuseur != 0)
  {
    //On ouvre le diffuseur
    Fonction_Diffuseur(1);
    //On lance le chrono du temps de diffusion
    Timer_Temps_Diffuseur = millis();
    //On stop ce chrono
    Timer_Delay_Diffuseur = 0;
  }
  
  //Une fois que le temps est fini on stop le diffuseur 
  if(millis() - Timer_Temps_Diffuseur >= Temps_Diffuseur && Timer_Temps_Diffuseur != 0)
  {
    //On ferme le diffuseur
    Fonction_Diffuseur(0);
    //On stop ce chrono
    Timer_Temps_Diffuseur = 0;
  }
}

void Gestion_Rediffusion()
{
  //Quand on change l'état de personne détecté a plus personne dans la salle
  if(Old_State_Diffusion == 0)
  {
    //On lance le chrono
    Timer_Delay_Diffuseur = millis();
    Old_State_Diffusion = 1;
  }

  //Quand le delay du diffuseur est passé on lance le diffuseur lui même
  if(millis() - Timer_Delay_Diffuseur >= Delay_Diffuseur && Timer_Delay_Diffuseur != 0)
  {
    //On ouvre le diffuseur
    Fonction_Diffuseur(1);
    //On lance le chrono du temps de diffusion
    Timer_Temps_Diffuseur = millis();
    //On stop ce chono
    Timer_Delay_Diffuseur = 0;
  }

  //Une fois que le temps de diffusion est fini on stop le diffuseur 
  if(millis() - Timer_Temps_Diffuseur >= Temps_Diffuseur && Timer_Temps_Diffuseur != 0)
  {
    //On ferme le diffuseur
    Fonction_Diffuseur(0);
    //On lance le chono du rediffuseur
    Timer_Delay_Rediffuseur = millis();
    //On stop ce chono
    Timer_Temps_Diffuseur = 0;
  }

  //Un fois que c'est le moment on rediffuse
  if(millis() - Timer_Delay_Rediffuseur >= Delay_Rediffuseur && Timer_Delay_Rediffuseur != 0)
  {
    //On ouvre le diffuseur
    Fonction_Diffuseur(1);
    //On lance le chrono du temps de rediffusion
    Timer_Temps_Rediffuseur = millis();
    //On relance ce chono
    Timer_Delay_Rediffuseur = millis();
  }

  //Une fois que le temps de rediffusion est fini on le stop
  if(millis() - Timer_Temps_Rediffuseur >= Temps_Rediffuseur && Timer_Temps_Rediffuseur != 0)
  {
    //On ferme le diffuseur
    Fonction_Diffuseur(0);
    //On stop ce chrono
    Timer_Temps_Rediffuseur = 0;
  }
}

