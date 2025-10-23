#include<gtk/gtk.h>



typedef struct
{

int jour;
int mois;
int annee;


} date;

typedef struct
{

char nombre[30];
char emplacement;
char lieu[30];
char type[50];
char marque [50];

int cap_used ;
date d;

} capteur ;



void ajouter_capteur(capteur p);

void afficher_capteur(GtkWidget *liste);
void Supprimer_capteur(capteur p); 
void modifier_capteur(capteur e );
void CHECK(int etat[], char texte[] );
void checkout(int check[], char out[] );
int capteur_used(capteur tab[50]);
int verif_capused(capteur cap);
int disponible_capt(char nombcap[100][50],char emplacement ,date d,int  cap_used);
void use_cap( capteur p);
