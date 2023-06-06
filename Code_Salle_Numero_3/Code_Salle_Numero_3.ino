/*
  Gestion de l'électronique de la salle 3 de l'expo sur le plateosorus

  Auteur : Dimitri Sigg

  Email : dimitri.sigg@outlook.com

  Date : 06.06.2023
*/

//Permet d'ajouter les differant paramètre de ce programme
#include "Parametre.h"
//Permet d'ajouter les differant calcule de ce programme
#include "Calcule.h"
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

  Gestion_Lumiere(); 

  Gestion_Musique(); 
  
  Gestion_Souffle(); 

  Gestion_Diffusion(); 

  Gestion_Ventilateur(); 

  Gestion_Deshumidificateur(); 

  Gestion_LED();
}
