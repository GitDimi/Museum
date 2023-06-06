#ifndef Hardware_h
#define Hardware_h

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

  #define Pin_Musique1 4
  #define Pin_Musique2 5
  #define Pin_Musique3 6
  #define Pin_LED 7
  #define Pin_Moteur_Fermeture 8
  #define Pin_Moteur_Ouverture 9
  #define Pin_Ventilateur 10
  #define Pin_Lumiere 11
  #define Pin_Souffle 12
  #define Pin_Deshumidificateur 13

//Temps static
  #define Temps_Moteur 730

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
  Gère l'intensité de la lumière
  int : Valeur de l'intensité
  */
  void Fonction_Lumiere(int);
    /*
  Allume ou éteint la Musique. 
  (bool) : L'état qui va être donnée à la Musique.
  */
  void Fonction_Musique(bool);
  /*
  Ferme le diffuseur.
  (bool) : La valeur qui va être donnée au diffuseur.
  */
  void Fonction_Moteur_Fermeture(bool);
  /*
  Ouvre le diffuseur.
  (bool) : La valeur qui va être donnée au diffuseur.
  */
  void Fonction_Moteur_Ouverture(bool);
  /*
  Allume ou éteint le souffle.
  (Bool) : La valeur qui va être donnée au souffle.
  */
  void Fonction_Souffle(bool);
  /*
  Allume ou éteint le ventilateur.
  (Bool) : La valeur qui va être donnée au ventilateur.
  */
  void Fonction_Ventilateur(bool);
  /*
  Allume ou éteint le Deshumidificateur. 
  (bool) : L'état qui va être donnée au Deshumidificateur.
  */
  void Fonction_Deshumidificateur(bool);
  /*
  Allume ou éteint la LED. 
  (bool) : L'état qui va être donnée à la LED.
  */
  void Fonction_LED(bool);

#endif 
