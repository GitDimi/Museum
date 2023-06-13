// -------------- GESTION DES TIMINGS AUTOMATIQUE-------------------- //
/*
SOUFFLE
*/
//Combien de temps dure une expiration (Vapeur allumé)
#define Temps_Souffle Temps_Expiration
//Combien de temps dure une inspiration (Vapeur éteint)
#define Temps_Non_Souffle Temps_Inspiration
//Combien de temps se lance le souffle après la détection
#define Delay_Souffle Delay_Souffle_Start

/*
DIFFUSEUR
*/
//Combien de temps dure la pause de diffusion (Diffuseur éteint)
#define Temps_Non_Diffuseur Temps_Inspiration + Temps_Expiration - Temps_Diffuseur
//Combien de temps se lance la lumière après la détection 
#define Delay_Diffuseur Delay_Souffle + Delay_Diffuseur_Start

/*
VENTILATEUR
*/
//Combien de temps se lance le ventilateur après la détection 
#define Delay_Ventilateur Delay_Souffle + Delay_Ventilateur_Start
//Combien de temps dure la pause de ventilation (Ventilateur éteint)
#define Temps_Non_Ventilateur Temps_Inspiration + Temps_Expiration - Temps_Ventilateur
//Temps actif du ventilateur sur 100
#define Vitesse_Ventilateur_Up 10 * Vitesse_Ventilateur
//Temps inactif du ventilateur sur 100
#define Vitesse_Ventilateur_Down 1000 - 10 * Vitesse_Ventilateur

/*
LUMIERE
*/
//Après combien de temps on lance le cycle de lumière après une détection 
#define Delay_Lumiere Delay_Souffle + Delay_Lumiere_Start 
//Pendant combien de temps la sortie DMX va être active pour simuler un clavier
#define Temps_DMX 500

/*
MUSIQUE
*/
//Combien de temps se lance la musique après la détection
#define Delay_Musique Delay_Souffle + Delay_Musique_Start


