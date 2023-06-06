/*
Activer ou désactiver les périphériques
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
//Ventilateur 
#define Ventilateur 1
//Lumière
#define Lumiere 1

// -------------- GESTION DES CAPTEUR -------------------- //

/*
CAPTEUR
*/
//Combien de temps on dit que quelqu'un est dans la pière après ne plus détecté personne 
#define Temps_Detection_max 20000

/*
GENERAL
*/
//De combien de temps sont les temps d'inspiration et expiration
#define Temps_Inspiration 12000 
#define Temps_Expiration 8000

/*
MUSIQUE
*/
//Combien de temps se lance la musique après une détection 
#define Delay_Musique 1000
/*A quelle vitesse la respiration va ?
mode 1 : 12 s d'inspiration et 8 s d'expiration
mode 2 : 9 s d'inspiration et 6 s d'expiration
mode 3 : Respiration humaine
*/
#define Vitesse_Musique 1

/*
SOUFFLE
*/
//Combien de temps se lance le souffle après une détection 
#define Delay_Souffle 12000

/*
DIFFUSEUR
*/
//Combien de temps se lance le diffuseur après une détection 
#define Delay_Diffuseur 5500

/*
VENTILATEUR
*/
//Combien de temps se lance le ventilateur après une détection 
#define Delay_Ventilateur 6500

/*
LUMIERE
*/
//Après combien de temps on lance le cycle de lumière après une détection 
#define Delay_Lumiere 12000
//Quelle est l'intensité de la lumière forte (de 0 a 255)
#define Intensitie_Lumiere_Forte 60
//Quelle est l'intensité de la lumière forte (de 0 a 255) (d'expérience 0 à 12 = éteint)
#define Intensitie_Lumiere_Faible 13

/*
DESHUMIDIFICATEUR
*/
//Combien de temps se lance la déshumidification après une détection 
#define Delay_Deshumidificateur 30000


