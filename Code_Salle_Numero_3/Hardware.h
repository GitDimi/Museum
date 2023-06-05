#ifndef Hardware_h
#define Hardware_h

#include "Parametre.h"

/* 
DESCRIPTION 

Les fichiers Hardware gèrent tout ce qui concerne la partie physique.
C'est ici qu'on gère les assignations des pins.
On crée les fonctions qui permet de contrôler les périphériques au bas niveau. 
Les périphériques sont activés ou désactiver en fonction des paramètres du Parametre.h
*/

//Pin d'entrée : 
  #define Capteur_de_mouvement_01 2
  #define Capteur_de_mouvement_02 3

//Pin de sortie
  #define Pin_Diffuseur 13
  #define Pin_Musique 12
  #define Pin_Ventilateur 11
  #define Pin_LED 10
  #define Pin_Alim_Musique 9
  #define Pin_Souffle 5

//Fonction du fichier Hardware.ino
  /*
  Récupère la valeur du capteur 1.
  bool : La valeur du capteur.  
  */
  bool Fonction_Catpeur01();
  /*
  Récupère la valeur du capteur 2.
  bool : La valeur du capteur.  
  */
  bool Fonction_Catpeur02();
  /*
  Allume ou éteint le diffuseur.
  (bool) : La valeur qui va être donnée au diffuseur.
  */
  void Fonction_Diffuseur(bool);
  /*
  Allume ou éteint la Musique. 
  (bool) : L'état qui va être donnée à la Musique.
  */
  void Fonction_Musique(bool);
  /*
  Allume ou éteint le ventilateur. 
  (bool) : L'état qui va être donnée au ventilateur.
  */
  void Fonction_Ventilateur(bool);
  /*
  Gère la force du souffle. 
  (int) : La valeur qui va être donnée au souffle.
  */
  void Fonction_Souffle(int);
  /*
  Allume ou éteint la LED. 
  (bool) : L'état qui va être donnée à la LED.
  */
  void Fonction_LED(bool);

#endif 
