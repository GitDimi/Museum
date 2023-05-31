#ifndef Fonction_h
#define Fonction_h

/* 
DESCRIPTION 

Les fichiers Fonction gèrent le gros du programme.
C'est ici que l'on va pour chaque périphérique choisir quand lire, allumer, éteindre, ext... 
Toute la logique est dans ses fonctions.
On gère aussi les différant mode choisi dans Parametre.h
*/

bool Old_State_Capteur01 = 0;
bool Old_State_Capteur02 = 0;
unsigned long Timer_Temps_Detection_max = 0;
bool Mouvement = 0;

unsigned long Timer_Delay_Lumiere = 0;
unsigned long Timer_Temps_Non_Lumiere = 0;
bool Old_State_Timer_Delay_Lumiere = 0;
bool Old_State_Timer_Temps_Lumiere = 0;
unsigned long Timer_Temps_Lumiere_Up = 0;
unsigned long Timer_Temps_Lumiere_Down = 0;
int Lumiere_Down = 0;
int Lumiere_Up = 0;

unsigned long Timer_Delay_Musique = 0;
bool Old_State_Timer_Delay_Musique = 0;
unsigned long Timer_Ajuste_Musique = 0;
unsigned long Timer_Stop_Musique = 0;

unsigned long Timer_Delay_Souffle = 0;
unsigned long Timer_Temps_Souffle = 0;
unsigned long Timer_Temps_Non_Souffle = 0;
bool Old_State_Timer_Delay_Souffle = 0;
bool Old_State_Timer_Temps_Souffle = 0;

unsigned long Timer_Delay_Diffuseur = 0;
unsigned long Timer_Temps_Diffuseur = 0;
unsigned long Timer_Temps_Non_Diffuseur = 0;
bool Old_State_Timer_Delay_Diffuseur = 0;
bool Old_State_Timer_Temps_Diffuseur = 0;

unsigned long Timer_Delay_Ventilateur = 0;
unsigned long Timer_Temps_Ventilateur = 0;
unsigned long Timer_Temps_Non_Ventilateur = 0;
bool Old_State_Timer_Delay_Ventilateur = 0;
bool Old_State_Timer_Temps_Ventilateur = 0;

unsigned long Timer_Delay_Deshumidificateur = 0;
bool Old_State_Timer_Delay_Deshumidificateur = 0;

//Fonction du fichier Fonction.ino

  /*
  Cette fonction gère les capteurs.
  Elle est programmée pour que tant qu'il ait un des deux capteurs qui perçois un mouvement, Le programme considère qu'il ait une personne dans la pièce.
  Dans le cas où les capteurs ne détectent plus personne du a l'immobilité de cette dernière, 
  un paramètre dans Paramere.h permet de prolonger l'état ou le programme considère qu'il y ai une personne dans la pièce.
  Si aucun capteur ne détecte un mouvement et que le delay de prolongation est terminer les valeurs, le programme indiquera que la pièce est vide.
  */
  void Gestion_Capteur();
  /*
  Cette fonction gère la lumière.
  Grace à des paramètres dans parametre.h on peut choisi : 
  - l'intensité de la lumière quand elle est forte
  - Le temps que la lumière forte est active
  - l'intensité de la lumière quand elle est faible
  - Le temps que la lumière faible est active
  */
  void Gestion_Lumiere();
  /*
  Cette fonction gère la musique (bruit de respiration).
  Une fois une personne détectée on lance la musique après avoir respecté le temps de delay prévu dans parametre.h.
  Plusieurs modes sont possible : 
  mode 1 : 12 s d'inspiration et 8 s d'expiration
  mode 2 : 9 s d'inspiration et 6 s d'expiration
  mode 3 : Respiration humaine
  Ses mode sont gérable dans parametre.h.
  */
  void Gestion_Musique();
  /*
  Cette fonction gère le souffle (souffle du dinosaure).
  Quand une personne est détectée on lance le souffle après un delay prévu dans parametre.h.
  Le souffle est fait d'une phase d'expiration et d'une phase d'inspiration.
  Ses deux phases peuvent être contrôlé dans le temps par des paramètre dans parametre.h.
  */
  void Gestion_Souffle();
  /*
  Cette fonction gère la diffusion.
  Grace à un paramètre dans parametre.h on peut choisi le temps que le diffuseur est actif
  et le temps que le diffuseur est inactif
  */
  void Gestion_Diffusion();
  /*
  Cette fonction gère le ventilateur.
  Grace à un paramètre dans parametre.h on peut choisi le temps que le ventilateur est actif
  et le temps que le ventilateur est inactif
  */
  void Gestion_Ventilateur();
  /*
  Cette fonction gère la deshumidification
  Quand personne n'est détecté on lance la deshumidification de la salle après un delay prévu dans parametre.h.
  Quand une personne est détectée on arrête immédiatement la deshumidification.
  */
  void Gestion_Deshumidificateur();
  /*
  Cette fonction gère une led
  La led s'allume si le programme considère qu'une personne est détecter dans la pièce. Et inversement.
  */
  void Gestion_LED();

#endif 

