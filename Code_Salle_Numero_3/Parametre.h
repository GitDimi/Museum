// -------------- GESTION DES TIMINGS -------------------- //

/*
CAPTEUR
*/
//Pendant combien de temps laisse t’ont allumé le souffle alors qu'on ne détecte plus personne dans la pièce 
#define Temps_Detection_max 20000
//Si le mode test est activé (1) on ne prend pas compte des capteurs et on tourne en boucle comme si quelqu’un était toujours là. Autrement (0)
#define Mode_Test 0

/*
GENERAL
*/
//De combien de temps sont les temps d'inspiration et expiration
#define Temps_Inspiration 9000 
#define Temps_Expiration 6000

/*
LUMIERE
*/
//Après combien de temps on lance le cycle de lumière après le souffle
#define Delay_Lumiere_Start 0
//Quelle est l'intensité de la lumière forte (de 0 à 255)
#define Intensitie_Lumiere_Forte 75
//Quelle est l'intensité de la lumière forte (de 0 à 255) (d'expérience 0 à 12 = éteint)
#define Intensitie_Lumiere_Faible 20
//Combien de temps allume-t-on la lumière en mode Forte
#define Temps_Lumiere_Forte 8000 
//Combien de temps allume-t-on la lumière en mode faible 
#define Temps_Lumiere_Faible 5000 
//Combien de temps laisse t’ont le mode faible avant de reprendre l'augmentation 
#define Temps_Lumiere_Pause 2000 
/*
Cela fonctionne en 3 temps 
- On passe de Intensitie_Lumiere_Faible à Intensitie_Lumiere_Forte en Temps_Lumiere_Forte ms
- On passe de Intensitie_Lumiere_Forte à Intensitie_Lumiere_Faible en Temps_Lumiere_Faible ms
- On reste en Intensitie_Lumiere_Faible pendant Temps_Lumiere_Pause ms
*/

/*
MUSIQUE
*/
//Combien de temps se lance la musique après le souffle 
#define Delay_Musique_Start 0

/*
SOUFFLE
*/
//Combien de temps se lance le souffle après une détection 
#define Delay_Souffle_Start 0
//Dès la détection d'une personne on projet de la vapeur instantanément pendant un court instant pour projeter les quelque goute de condensation brulante qui se sont créé du a un long moment d'inactivité
#define Security_Souffle 3000

/*
DIFFUSEUR
*/
//Combien de temps se lance le diffuseur après le souffle 
#define Delay_Diffuseur_Start 7000
//Combien de temps dure une diffusion (Diffuseur allumé)
#define Temps_Diffuseur 8000

/*
VENTILATEUR
*/
//Combien de temps se lance le ventilateur après le souffle 
#define Delay_Ventilateur_Start 8000
//Le pourcentage de vitesse du ventilateur (non-linaire à faire au jugé)
#define Vitesse_Ventilateur 95
//Combien de temps dure une ventilation (Ventilateur allumé)
#define Temps_Ventilateur 9000

/*
DESHUMIDIFICATEUR
*/
//Combien de temps se lance la déshumidification après qu'on ne détecte plus personne 
#define Delay_Deshumidificateur 30000

/*
Activer ou désactiver les périphériques
1 = activé
0 = désactivé
*/
//Diffuseur d'odeur
#define Diffuseur 1
//Musique
#define Musique 1
//Déshumidification
#define Deshumidificateur 1
//Souffle
#define Souffle 1
//Détecteur 1 
#define Detecteur_1 1
// Détecteur 2 
#define Detecteur_2 1
//LED
#define LED 1
//Ventilateur 
#define Ventilateur 1
//Lumière
#define Lumiere 1
//Lumière en mode DMX
#define Lumiere_DMX 1


