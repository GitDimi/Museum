/*
  Gestion de l'électronique de la salle 3 de l'expo sur le plateosorus

  Auteur : Dimitri Sigg

  Email : dimitri.sigg@unine.ch 

  Date : 11.05.2023
*/

//Permet d'ajouter les differant paramètre de ce programme
#include "Parametre.h"
//Permet d'ajouter les differant paramètre hardware de ce programme
#include "Hardware.h"
//Permet d'ajouter les fonction d'initalisation 
#include "Init.h"
//Permet d'ajouter les fonction logique principal
#include "Fonction.h"

void setup() 
{
  Init();

  Timing_Warning();
}

//Main
void loop() 
{
  Gestion_Capteur();

  Gestion_LED();

  Gestion_Musique();
  
  Gestion_Souffle();

  Gestion_Ventilateur();

  Gestion_Diffusion();
}
