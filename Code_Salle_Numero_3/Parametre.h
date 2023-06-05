/*
Activer ou désactiver les perifiériques
1 = activé
0 = désactivé
*/
//Diffuseur d'odeur
#define Diffuseur 1
//Musique
#define Musique 1
//Ventilateur
#define Ventilateur 1
//Souffle
#define Souffle 1
//Dectecteur 1 
#define Detecteur_1 1
//Dectecteur 2 
#define Detecteur_2 1
//LED
#define LED 1

/*
Gestion des 
temps
*/
//Combien de temps se lance le diffuseur d'odeur après une detection (en ms)
#define Delay_Diffuseur 1000
//Combien de temps se lance la musique après une detection (en ms)
#define Delay_Musique 1000
//Combien de temps se lance le ventilateur après la fin d'une detection (en ms)
#define Delay_Ventilateur 1000

//Combien de temps le diffuseur diffuse (en ms)
#define Temps_Diffuseur 3000

//Combien de temps on dit que quelqu'un est dans la piece après ne plus détécté personne (en ms)
#define Temps_Detection_max 15000

/*
paramètre des perifiériques
1 = activé
0 = désactivé
*/
//Es ce qu'on diffuse plusieurs fois quand le visiteur est dans la salle
#define Rediffusion 1
//Et cela, tout les combien de temps ? (en ms)
#define Delay_Rediffuseur 4000
//Combien de temps dur les diffusions répété
#define Temps_Rediffuseur 1000

//Es ce qu'on relance la musique si elle est fini alors qu'un visiteur est encore présent : oui (1) non (0)
#define RePlay 1
//Es ce qu'on stop la musique quand il n'y a plus personne (1) ou alors on laisse la musique finir (1)
#define StopPlay 1

//Combien de temps se lance le souffle après une détection
#define Delay_Souffle 1000
//Combien de temps dure une expiration (Ventilateur allumé)
#define Temps_Souffle 1000
//Combien de temps dure une inspiration (Ventilateur éteint)
#define Temps_Non_Souffle 1000

