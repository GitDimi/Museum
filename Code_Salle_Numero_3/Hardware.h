#ifndef Hardware_h
#define Hardware_h

/* 
DESCRIPTION 

Les fichiers Hardware gèrent tout ce qui concerne la partie physique.
C'est ici qu'on gère les assignations des pins.
On crée les fonctions qui permet de contrôler les périphériques au bas niveau. 
Les périphériques sont activés ou désactiver en fonction des paramètres du Parametre.h
*/

//Define pin d'entrée : 
  #define Capteur_de_mouvement_01 2
  #define Capteur_de_mouvement_02 3

//Define pin de sortie
  #define Pin_Musique1 A0
  #define Pin_Musique2 A1
  #define Pin_Musique3 A2
  #define Pin_Musique4 A3
  #define Pin_Lumiere_DMX 6
  #define Pin_LED 7
  #define Pin_Moteur_Fermeture 8
  #define Pin_Moteur_Ouverture 9
  #define Pin_Ventilateur 10
  #define Pin_Lumiere 11
  #define Pin_Souffle 12
  #define Pin_Deshumidificateur 13

//Define valeur static
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
  (int) : Valeur de l'intensité
  */
  void Fonction_Lumiere(int);
    /*
  Allume ou éteint la lumière contrôlé par DMX. 
  (bool) : L'état qui va être donnée à la lumière DMX.
  */
  void Fonction_Lumiere_DMX(bool);
    /*
  Allume ou éteint la Musique. 
  (int) : Le numéro de la tracks à jouer.
  */
  void Fonction_Musique(int);
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


