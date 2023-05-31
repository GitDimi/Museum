/*
Activer ou désactiver les perifiériques
1 = activé
0 = désactivé
*/
//Diffuseur d'odeur
#define Diffuseur 1
//Musique
#define Musique 1
//Deshumidification
#define Deshumidificateur 1
//Souffle
#define Souffle 1
//Dectecteur 1 
#define Detecteur_1 1
//Dectecteur 2 
#define Detecteur_2 1
//LED
#define LED 1
//Ventilateru 
#define Ventilateur 1
//Lumière
#define Lumiere 1


// -------------- GESTION DES CAPTEUR -------------------- //

/*
CAPTEUR
*/
//Combien de temps on dit que quelqu'un est dans la piece après ne plus détécté personne 
#define Temps_Detection_max 15000

/*
MUSIQUE
*/
//Combien de temps se lance la musique après une detection 
#define Delay_Musique 1000
/*A quelle vitesse la repiration va ?
mode 1 : 12 s d'inspiration et 8 s d'expiration
mode 2 : 9 s d'inspiration et 6 s d'expiration
mode 3 : Respiration humaine
*/
#define Vitesse_Musique 1

/*
SOUFFLE
*/
//Combien de temps se lance le souffle après une detection 
#define Delay_Souffle 12000
//Combien de temps dure une expiration (Vapeur allumé)
#define Temps_Souffle 8000
//Combien de temps dure une inspiration (Vapeur éteint)
#define Temps_Non_Souffle 12000

/*
DIFFUSEUR
*/
//Combien de temps se lance le diffuseur après une detection 
#define Delay_Diffuseur 4000
//Combien de temps dure une diffusion (Diffuseur allumé)
#define Temps_Diffuseur 8000
//Combien de temps dure la pause de diffusion (Diffuseur éteint)
#define Temps_Non_Diffuseur 12000

/*
VENTILATEUR
*/
//Combien de temps se lance le ventilateur après une detection 
#define Delay_Ventilateur 5000
//Combien de temps dure une ventilation (Ventilateur allumé)
#define Temps_Ventilateur 8000
//Combien de temps dure la pause de ventilation (Ventilateur éteint)
#define Temps_Non_Ventilateur 12000

/*
LUMIERE
*/
//Après combien de temps on lance le cycle de lumière après une detection 
#define Delay_Lumiere 12000
//Quelle est l'intensité de la lumière forte (de 0 a 255)
#define Intensitie_Lumiere_Forte 200
//Combien de temps allume t-on la lumière en mode fort 
#define Temps_Lumiere_Forte 8000
//Quelle est l'intensité de la lumière forte (de 0 a 255) (d'experiance 0 à 12 = éteint)
#define Intensitie_Lumiere_Faible 15
//Combien de temps allume t-on la lumière en mode faible 
#define Temps_Lumiere_Faible 12000

/*
DESHUMIDIFICATEUR
*/
//Combien de temps se lance la deshumidification après une detection 
#define Delay_Deshumidificateur 10000

