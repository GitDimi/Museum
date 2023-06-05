#ifndef Fonction_h
#define Fonction_h

/* 
DESCRIPTION 

Les fichiers Fonction gèrent le gros du programme.
C'est ici que l'on va pour chaque périphérique choisir quand lire, allumer, éteindre, ext... 
Toute la logique est dans ses fonctions.
On gère aussi les différant mode choisi dans Parametre.h
*/

//Init Timer
unsigned long Timer_Temps_Detection_max = 0;
unsigned long Timer_Delay_Diffuseur = 0;
unsigned long Timer_Temps_Diffuseur = 0;
unsigned long Timer_Delay_Rediffuseur = 0;
unsigned long Timer_Temps_Rediffuseur = 0;
unsigned long Timer_Delay_Musique = 0;
unsigned long Timer_Delay_Ventilateur = 0;
unsigned long Timer_Temps_Souffle = 0;
unsigned long Timer_Temps_Non_Souffle = 0;
unsigned long Timer_Delay_Souffle = 0;

//Init lancement timer
bool Old_State_Diffusion = 0;
bool Old_State_No_Mouvement = 0;
bool Old_State_Timer_Delay_Musique = 0;
bool Old_State_Timer_Delay_Ventilateur = 0;
bool Old_State_Timer_Delay_Souffle = 0;
bool Old_State_Timer_Temps_Souffle = 0;

//Init Variable
bool Mouvement = 0;
int Compteur_Souffle = 0;

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
  Cette fonction gère une led
  La led s'allume si le programme considère qu'une personne est détecter dans la pièce. Et inversement.
  */
  void Gestion_LED();
  /*
  Cette fonction gère la musique (bruit de respiration).
  Une fois une personne détectée on lance la musique après avoir respecté le temps de delay prévu dans parametre.h.
  On gère aussi si l'on stop la musique tout de suite après la sortie du visiteur ou l'on finit la lecture de la tracks.
  On gère aussi si l'on répète la musique une fois la musique fini (Si une personne est toujours à l'intérieur).
  */
  void Gestion_Musique();
  /*
  Cette fonction gère le souffle (souffle du dinosaure).
  Quand une personne est détectée on lance le souffle après un delay prévu dans parametre.h.
  Le souffle est fait d'une phase d'expiration et d'une phase d'inspiration.
  Ses deux phases peuvent être contrôlé dans le temps par des paramètre dans parametre.h.
  L'expiration se fait de manière linaire. Elle commence fort puis s'affaibli.
  */
  void Gestion_Souffle();
  /*
  Cette fonction gère la ventilation 
  Quand personne n'est détecté on lance la ventilation de la salle après un delay prévu dans parametre.h.
  Quand une personne est détectée on arrête immédiatement la ventilation.
  */
  void Gestion_Ventilateur();
  /*
  Cette fonction gère la diffusion.
  Cette fonction gère les deux modes de diffusion possible en fonction d'un paramètre dans parametre.h.
  */
  void Gestion_Diffusion();
  /*
  Cette fonction gère la partie diffusion en mode normal
  Cette fonction ouvre le diffuseur quand une personne arrive après un certain delay donné dans parametre.h.
  Le diffuseur sera ouvert le temps donné dans parametre.h. une fois ce temps passé le diffuseur s'arrête.
  */
  void Gestion_Diffusion_Normal();
  /*
  Cette fonction gère la partie diffusion en mode rediffusion
  Cette fonction ouvre le diffuseur quand une personne arrive après un certain delay donné dans parametre.h.
  Le diffuseur sera ouvert le temps donné dans parametre.h. une fois ce temps passé le diffuseur s'arrête.
  Le diffuseur se réouvre ensuite à l'intervalle régulier qu'un paramètre dans parametre.h règle.
  On peut également choisir le temps de réouverture à l'aide d'un paramètre.
  */
  void Gestion_Rediffusion();

#endif 

