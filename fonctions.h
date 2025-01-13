#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
FILE*tp;
char name_unit[15];
typedef struct Livre {
char id[5];
char titre[15];
char auteur[15];
char description[30];
char name_user[15];
float prix;
char cathe[5];
char dispo[15];

}Livre;
void menu();
void ajouter();
void modifier();
void supprimer();
void afficher();
void stocker();
void rechercher();
void trier();



#endif // FONCTIONS_H_INCLUDED
