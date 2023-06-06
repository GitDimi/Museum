#ifndef Init_h
#define Init_h

/* 
DESCRIPTION 

Les fichiers Init gèrent tout ce qui concerne la partie d'initialisation.
On crée les fonctions qui permet d'initialiser les périphériques et les rendre prêt à l'utilisation. 
On gère aussi ici les différentes erreurs de timing qui pourrai avoir eu lieu dans Parametre.h
*/

bool Led_Blink = 0;

//Fonction du fichier Hardware.ino

  /*
  Gère les pinModes en entrée ou en sortie.
  Initialiser les périphériques dans un état éteint.
  */
  void Init();
  /*
  Gère les timings issus de Parmetre.h 
  Il se peut que des temps ne sois pas cohérant entre eux.
  S’il y a des erreurs il les indique dans la console.
  Liste non exhaustive
  */
  void Timing_Warning();

#endif 
