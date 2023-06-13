#ifndef Fonction_h
#define Fonction_h

/* 
DESCRIPTION 

Les fichiers Fonction gèrent le gros du programme.
C'est ici que l'on va, pour chaque périphérique, choisir quand lire, allumer, éteindre, ext... 
Toute la logique est donc ici.
*/

//Déclaration des variables de Fonction.ino

//Capteur
bool Old_State_Capteur01 = 0;
bool Old_State_Capteur02 = 0;
unsigned long Timer_Temps_Detection_max = 0;
bool Mouvement = 0;

//Lumière
bool Old_State_Timer_Delay_Lumiere = 0;
unsigned long Timer_Delay_Lumiere = 0;
unsigned long Timer_Temps_Lumiere_Up_Save = 0;
unsigned long Timer_Temps_Lumiere_Down_Save = 0;
unsigned long Timer_Temps_Lumiere_Up = 0;
unsigned long Timer_Temps_Lumiere_Down = 0;
unsigned long Timer_Temps_Lumiere_Pause = 0;
unsigned long Timer_Temps_Lumiere_DMX = 0;
int Lumiere_Down = 0;
int Lumiere_Up = 0;

//Musique
bool Old_State_Timer_Delay_Musique = 0;
unsigned long Timer_Delay_Musique = 0;
unsigned long Timer_Ajuste_Musique = 0;
unsigned long Timer_Stop_Musique = 0;
int Nb_Musique = 0;

//Souffle
bool Old_State_Timer_Delay_Souffle = 0;
unsigned long Timer_Delay_Souffle = 0;
unsigned long Timer_Temps_Souffle = 0;
unsigned long Timer_Temps_Non_Souffle = 0;
unsigned long Timer_Security_Souffle = 0;

//Diffuseur
bool Old_State_Timer_Delay_Diffuseur = 0;
unsigned long Timer_Delay_Diffuseur = 0;
unsigned long Timer_Temps_Diffuseur = 0;
unsigned long Timer_Temps_Non_Diffuseur = 0;
unsigned long Timer_Mouvement_Moteur = 0;
bool Old_State_Security_Diffuseur = 0;
int State_Diffuseur = 2;
int Moteur_Security = 0;

//ventilateur
bool Old_State_Timer_Delay_Ventilateur = 0;
unsigned long Timer_Delay_Ventilateur = 0;
unsigned long Timer_Temps_Ventilateur = 0;
unsigned long Timer_Temps_Non_Ventilateur = 0;
unsigned long Timer_Vitesse_Ventilateur_Up = 0;
unsigned long Timer_Vitesse_Ventilateur_Down = 0;

//deshumidifiacteur 
bool Old_State_Timer_Delay_Deshumidificateur = 0;
unsigned long Timer_Delay_Deshumidificateur = 0;

//Fonction du fichier Fonction.ino

  /*
  Cette fonction gère les capteurs.
  Elle est programmée pour que tant qu'il ait un des deux capteurs qui perçois un mouvement, Le programme considère qu'il ait une personne dans la pièce.
  Dans le cas où les capteurs ne détectent plus personne du a l'absence de cette dernière, 
  un paramètre dans Paramere.h permet de prolonger l'état ou le programme considère qu'il y ai une personne dans la pièce.
  Si aucun capteur ne détecte un mouvement et que le delay de prolongation est terminer, le programme indiquera que la pièce est vide.
  */
  void Gestion_Capteur();
  /*
  Cette fonction gère la lumière.
  Grace à des paramètres dans parametre.h on peut choisi : 
  - l'intensité de la lumière quand elle est forte
  - l'intensité de la lumière quand elle est faible
  - Le temps que la lumière passe de faible à fort 
  - Le temps que la lumière passe de fort à faible
  - Le temps que la lumière reste faible avant de repartir
  - Le delay pour que la lumière s'allume par rapport au début du souffle
  */
  void Gestion_Lumiere();
  /*
  Cette fonction gère la musique (bruit de respiration).
  Grace à un paramètre dans parametre.h on peut choisi : 
  - Le delay pour que la musique s’enclenche par rapport au début du souffle
  La musique possède 4 tracks qui tourne l'une après les autres.
  */
  void Gestion_Musique();
  /*
  Cette fonction gère le souffle (souffle du dinosaure produit par une projection de vapeur d'eau).
  Grace à des paramètres dans parametre.h on peut choisi : 
  - Le delay pour que le souffle se lance par rapport à la détection d'une personne
  - Le temps que le souffle est actif
  Le souffle est fait d'une phase d'expiration (vapeur d'eau) et d'une phase d'inspiration (calme).
  */
  void Gestion_Souffle();
  /*
  Cette fonction gère la diffusion (ouverture du contenant de l'odeur).
  Grace à des paramètres dans parametre.h on peut choisi : 
  - Le delay pour que la diffusion s’enclenche par rapport au début du souffle
  - Le temps que la diffusion est active
  La diffusion est faite d'une phase d'ouverture (contenant ouvert) et d'une phase de fermeture (contenant fermé).
  */
  void Gestion_Diffusion();
  /*
  Cette fonction gère le ventilateur (le ventilateur qui sort l'aire du contenant de du diffuseur et les ventilateurs qui projettent l'aire dans la pièce).
  Grace à des paramètres dans parametre.h on peut choisi : 
  - Le delay pour que les ventilateurs s’enclenchent par rapport au début du souffle
  - Le temps que les ventilateurs sont activés
  La ventilation est faite d'une phase de fonctionnement (ventilateur ON) et d'une phase d'arrêt (ventilateur OFF).
  */
  void Gestion_Ventilateur();
  /*
  Cette fonction gère la déshumidification.
  Grace à des paramètres dans parametre.h on peut choisi : 
  - Le delay pour que les déshumidifications s’enclenchent par rapport à la fin de la détection d'une personne
  Même une fois la prise de l'alimentation du Arduino retiré, le déshumidificateur fonctionne toujours pour qu'il soit active la nuit
  */
  void Gestion_Deshumidificateur();
  /*
  Cette fonction gère une led
  La led s'allume si le programme considère qu'une personne est détecter dans la pièce. Et inversement.
  */
  void Gestion_LED();

#endif 


