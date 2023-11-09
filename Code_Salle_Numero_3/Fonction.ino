#include "Fonction.h"

void Gestion_Capteur()
{
  //init des variables
  int Etat_du_capteur_de_mouvement01 = 0;
  int Etat_du_capteur_de_mouvement02 = 0;
  
  if(Mode_Test == 1)
  {
    Mouvement = 1;
  }
  else
  {
    //Mise à jour de l'état du capteur
    Etat_du_capteur_de_mouvement01 = Fonction_Catpeur01();
    Etat_du_capteur_de_mouvement02 = Fonction_Catpeur02();
  
    //Si un des deux capteurs détecte quelque chose, on agit autrement on ne change rien 
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
  
    //Debug, indique sur la console (serial monitor 9600 bauds) chaque changement d'état des capteurs
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
      Timer_Temps_Lumiere_Up_Save = millis();
      Timer_Delay_Lumiere = 0;
    }
    /*
    Etant donné que le chrono de l'augmentation de la lumière se fait avec une division, 
    Il est possible que le timing ne soit pas exactement celui que l'on veut et que cela provoque un décalage.
    Cela est dû à des pertes de chiffres après la virgule.
    Pour y remédier on lance ici un autre chrono parallèle qui va s'assurer que le timing sois respecté.
    */
    if(millis() - Timer_Temps_Lumiere_Up_Save >= Temps_Lumiere_Forte && Timer_Temps_Lumiere_Up_Save != 0)
    {
      Fonction_Lumiere_DMX(1);
      Timer_Temps_Lumiere_DMX = millis();
      Timer_Temps_Lumiere_Down = millis();
      Timer_Temps_Lumiere_Down_Save = millis();
      Timer_Temps_Lumiere_Up = 0;
      Timer_Temps_Lumiere_Up_Save = 0;
      Lumiere_Down = 0;
      Lumiere_Up = 0;
    } 
    /*Chrono de la lumière qui augmente.
    On prend le temps de montée et on le divise par l'écart qu'il y a entre la valeur de départ et la valeur final
    C'est comme ça que l'on rentre dans le if le nombre de fois qu'il faut dans le temps qu'il faut.
    */
    else if(millis() - Timer_Temps_Lumiere_Up >= (double)Temps_Lumiere_Forte/((double)Intensitie_Lumiere_Forte - (double)Intensitie_Lumiere_Faible) && Timer_Temps_Lumiere_Up != 0)
    {
      Lumiere_Up++;
      Fonction_Lumiere(Intensitie_Lumiere_Faible + Lumiere_Up);
      if(Lumiere_Up == (Intensitie_Lumiere_Forte - Intensitie_Lumiere_Faible))
      {
        Timer_Temps_Lumiere_Up = 0; 
        Lumiere_Up = 0;
        Timer_Temps_Lumiere_Down_Save = millis();
        Timer_Temps_Lumiere_Down = millis();
      }
      else
      {
        Timer_Temps_Lumiere_Up = millis();
      }
    } 
    //Chrono qui simule une touche clavier qui active le DMX 
    if(millis() - Timer_Temps_Lumiere_DMX >= Temps_DMX && Timer_Temps_Lumiere_DMX != 0)
    {
      Fonction_Lumiere_DMX(0);
      Timer_Temps_Lumiere_DMX = 0;
    } 
    //Chrono de descente qui assure le timing exact
    if(millis() - Timer_Temps_Lumiere_Down_Save >= Temps_Lumiere_Faible && Timer_Temps_Lumiere_Down_Save != 0)
    {
      Timer_Temps_Lumiere_Pause = millis();
      Timer_Temps_Lumiere_Down = 0;
      Timer_Temps_Lumiere_Down_Save = 0;
      Lumiere_Down = 0;
      Lumiere_Up = 0;
    } 
    /*Chrono de la lumière qui diminue.
    On prend le temps de descente et on le divise par l'écart qu'il y a entre la valeur de départ et la valeur final
    C'est comme ça que l'on rentre dans le if le nombre de fois qu'il faut dans le temps qu'il faut.
    */
    else if(millis() - Timer_Temps_Lumiere_Down >= (double)(Temps_Lumiere_Faible)/((double)Intensitie_Lumiere_Forte-(double)Intensitie_Lumiere_Faible) && Timer_Temps_Lumiere_Down != 0)
    {
      Lumiere_Down++;
      Fonction_Lumiere(Intensitie_Lumiere_Forte - Lumiere_Down);
      if(Lumiere_Down == (Intensitie_Lumiere_Forte-Intensitie_Lumiere_Faible))
      {
        Timer_Temps_Lumiere_Pause = millis();
        Timer_Temps_Lumiere_Down = 0; 
        Lumiere_Down = 0;
      }
      else
      {
        Timer_Temps_Lumiere_Down = millis();
      }
    } 
    //Chrono de pause de la lumière
    if(millis() - Timer_Temps_Lumiere_Pause >= Temps_Lumiere_Pause && Timer_Temps_Lumiere_Pause != 0)
    {
      Timer_Temps_Lumiere_Up = millis();
      Timer_Temps_Lumiere_Up_Save = millis();
      Timer_Temps_Lumiere_Pause = 0;
    } 
  }
  else
  {
    Timer_Temps_Lumiere_Down = 0;
    Timer_Temps_Lumiere_Up = 0;
    Timer_Temps_Lumiere_Pause = 0;
    Timer_Delay_Lumiere = 0;
    Lumiere_Down = 0;
    Lumiere_Up = 0;
    Old_State_Timer_Delay_Lumiere = 0;
    Fonction_Lumiere(Intensitie_Lumiere_Faible); 
    Timer_Temps_Lumiere_Down_Save = 0;
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
    //Une fois le chrono du delay est passé on lance la musique. 
    if(millis() - Timer_Delay_Musique >= Delay_Musique && Timer_Delay_Musique != 0)
    {
      Timer_Ajuste_Musique = millis();
      Nb_Musique++;
      Fonction_Musique(Nb_Musique);
      Timer_Delay_Musique = 0;
    }
    //Chrono qui éteint la pin pour pas que la musique se relancer
    if(millis() - Timer_Ajuste_Musique >= 1000 && Timer_Ajuste_Musique != 0)
    {  
      Fonction_Musique(0);
      Timer_Stop_Musique = millis();
      Timer_Ajuste_Musique = 0;
    }
    //Chrono qui rallume la musique. On change de musique à chaque tour
    if(millis() - Timer_Stop_Musique >= 14000 && Timer_Stop_Musique != 0)
    {  
      Nb_Musique++;
      Fonction_Musique(Nb_Musique);
      if(Nb_Musique == 4)
      {
        Nb_Musique = 0;
      }

      Timer_Ajuste_Musique = millis();
      Timer_Stop_Musique = 0;
    }
  }
  else
  {
    Fonction_Musique(0);
    Old_State_Timer_Delay_Musique = 0;
    Timer_Delay_Musique = 0;
    Timer_Ajuste_Musique = 0;
    Timer_Stop_Musique = 0;
    Nb_Musique = 0;
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
      Timer_Security_Souffle = millis();
      Old_State_Timer_Delay_Souffle = 1;
      Fonction_Souffle(1);
    }
    //Dès la détection d'une personne on projet de la vapeur instantanément pendant un court instant pour projeter les quelque goute de condensation brulante qui se sont créé du a un long moment d'inactivité
    if(millis() - Timer_Security_Souffle >= Security_Souffle && Timer_Security_Souffle != 0)
    {   
      Fonction_Souffle(0);
      Timer_Security_Souffle = 0;
    }
    //Au démarrage, après le delay, on lance le chrono du souffle
    if(millis() - Timer_Delay_Souffle >= Delay_Souffle && Timer_Delay_Souffle != 0)
    {   
      Timer_Temps_Non_Souffle = millis();
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
    Timer_Security_Souffle = 0;
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
    //Au démarrage, après le delay, on lance le chrono du diffuseur. On lance le chrono qui va ouvrir le diffuseur et on lance le chrono qui va compter combien de temps il doit être ouvert
    if(millis() - Timer_Delay_Diffuseur >= Delay_Diffuseur && Timer_Delay_Diffuseur != 0)
    {   
      Timer_Temps_Diffuseur = millis();
      State_Diffuseur = 0;
      Timer_Mouvement_Moteur = millis();
      Timer_Delay_Diffuseur = 0;
    }  
    //On lance le chrono qui va ouvrir le diffuseur et on lance le chrono qui va compter combien de temps il doit être ouvert
    if(millis() - Timer_Temps_Diffuseur >= Temps_Diffuseur && Timer_Temps_Diffuseur != 0)
    {
      State_Diffuseur = 1;
      Timer_Mouvement_Moteur = millis();
      Timer_Temps_Non_Diffuseur = millis();
      Timer_Temps_Diffuseur = 0;
    }
    //On lance le chrono qui va fermer le diffuseur et on lance le chrono qui va compter combien de temps il doit être fermé
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

    /*
    Ici on gère l'état de notre diffuseur (fermé ou ouvert).
    Si on ne détecte plus personne et le diffuseur est en train de s'ouvrir, on s s'assuré qu'il se referme.
    On se souvient donc à chaque fois de l'état du diffuseur et on gère ça fermeture.
    Dans le cas où l'électricité est coupée, on ne peut rien faire. 
    Il a été préférer de ne pas forcer la fermeture dès le retour de l'alimentation 
    Car il y a très peu de chance que cela arrive et il pourrait être dommageable de fermer tous les jours le diffuseur qui est déjà fermé
    */
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
    //Au démarrage, après le delay, on lance le chrono du Ventilateur
    if(millis() - Timer_Delay_Ventilateur >= Delay_Ventilateur && Timer_Delay_Ventilateur != 0)
    {   
      Timer_Delay_Ventilateur = 0;
      Timer_Temps_Ventilateur = millis();
      Timer_Vitesse_Ventilateur_Up = millis();
      Fonction_Ventilateur(1);
    }
    //Chrono qui allume le pourcentage de "Vitesse_Ventilateur"
    if(millis() - Timer_Vitesse_Ventilateur_Up >= Vitesse_Ventilateur_Up && Timer_Vitesse_Ventilateur_Up != 0)
    {   
      Timer_Vitesse_Ventilateur_Down = millis();
      Timer_Vitesse_Ventilateur_Up = 0;
      Fonction_Ventilateur(0);
    }
    //Chrono qui éteint le pourcentage de "Vitesse_Ventilateur"
    if(millis() - Timer_Vitesse_Ventilateur_Down >= Vitesse_Ventilateur_Down && Timer_Vitesse_Ventilateur_Down != 0)
    {   
      Timer_Vitesse_Ventilateur_Up = millis();
      Timer_Vitesse_Ventilateur_Down = 0;
      Fonction_Ventilateur(1);
    }

    //Chrono du ventilateur allumé (tant que ce chrono est en marche les deux chronos d'en dessus vont tourner)
    if(millis() - Timer_Temps_Ventilateur >= Temps_Ventilateur && Timer_Temps_Ventilateur != 0)
    {
      Fonction_Ventilateur(0);
      Timer_Vitesse_Ventilateur_Up = 0;
      Timer_Vitesse_Ventilateur_Down = 0;
      Timer_Temps_Non_Ventilateur = millis();
      Timer_Temps_Ventilateur = 0;
    }
    //Chrono du ventilateur éteint
    else if(millis() - Timer_Temps_Non_Ventilateur >= Temps_Non_Ventilateur && Timer_Temps_Non_Ventilateur != 0)
    {
      Timer_Temps_Ventilateur = millis();
      Timer_Vitesse_Ventilateur_Up = millis();
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
    Timer_Vitesse_Ventilateur_Up = 0;
    Timer_Vitesse_Ventilateur_Down = 0;
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


