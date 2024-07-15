#include <stdio.h>

void wcNoOption(FILE *fichier,char *file);
int wcOption_c(FILE *fichier);
int wcOption_l(FILE *fichier,char *chaine,int nbr);
int wcOption_w(FILE *fichier,char *chaine,int nbr);
int wcOption_L(FILE *fichier);
void all_option(char *file,char *argm);
void error();
