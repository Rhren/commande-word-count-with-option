#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Fonction qui retourne le nombre de caractère du fichier
int wcOption_c(FILE *fichier)
{
	int nbr=0;
	while(fgetc(fichier) != EOF)
	{
		nbr++;
	}
	rewind(fichier);
	return nbr;
}
char *allocation(int nbr)
{
	char *tab=NULL;
	tab=(char*)malloc(nbr*sizeof(char));
	if(tab == NULL)
	{
		printf("Erreur d'allocation");
		exit(1);
	}
	return (tab);
}
//Fonction qui retourne le nombre de ligne du fichier
int wcOption_l(FILE *fichier,char *chaine,int nbr)
{
	int i;
	int j=0;
	for(i=0 ; i<nbr;i++)
	{
		fscanf(fichier,"%c",&chaine[i]);
	}
	for(i=0 ; i<nbr; i++)
	{
		if(chaine[i] == '\n')
		{
			j++;
		}
	}
	
	return (j);
}
//Fonction qui retourne le nombre de mot du fichier
int wcOption_w(FILE *fichier,char *chaine,int nbr)
{
	int j=0;
	while(fscanf(fichier,"%s",chaine) == 1)
	{
		j++;
	}
		
		return (j);
}
//Fonction qui retourne la valeur maximal de l'affichage
int wcOption_L(FILE *fichier)
{
	int max_caracteres = 0;
    	int caracteres_actuels = 0;
   	 int c;

    while ((c = fgetc(fichier)) != EOF) 
    {
        if (c == '\n') 
	{
            if (caracteres_actuels > max_caracteres)
            {
                max_caracteres = caracteres_actuels;
		
	    }
            caracteres_actuels = 0; // Réinitialiser le compteur pour la prochaine ligne
	} 
	else 
        {
            caracteres_actuels++;
        }
    }

    if (caracteres_actuels > max_caracteres)
    {
        max_caracteres = caracteres_actuels;
	
    }
	return max_caracteres;
}
void error()
{
	printf("option invalid \n");
	exit(1);
}

void all_option(char *file,char *argm)
{
	FILE *fichier=NULL;
	fichier=fopen(file,"r");
	if(fichier == NULL)
	{
		printf("Erreur d'ouverture du fichier\n");
		exit(1);
	}
	else
	{
		if(strcmp(argm,"-c") == 0 || strcmp(argm,"--bytes") == 0 || strcmp(argm,"-m") == 0 || strcmp(argm,"--chars") == 0 )
		{
			printf("%d %s\n",wcOption_c(fichier),file);
		}
		else if(strcmp(argm,"-l") == 0 || strcmp(argm,"--lines") == 0 )
		{
			int nbr=wcOption_c(fichier);
			char *chaine=allocation(nbr);
				printf("%d %s\n",wcOption_l(fichier,chaine,nbr),file);
				free(chaine);
		}
		else if(strcmp(argm,"-w") == 0 || strcmp(argm,"--words") == 0 )
		{
			int nbr=wcOption_c(fichier);
			char *chaine=allocation(nbr);
			printf("%d %s\n",wcOption_w(fichier,chaine,nbr),file);
		}
		else if(strcmp(argm,"-L") == 0 || strcmp(argm,"--max-line-length") == 0 )
		{
			printf("%d %s\n",wcOption_L(fichier),file);
		}
		
		else
		{
			error();
		}
	
	fclose(fichier);
	}
}
void wcNoOption(FILE *fichier,char *file)
{
	fichier=fopen(file,"r");
	if(fichier == NULL)
	{
		printf("Erreur d'ouverture du fichier\n");
		exit(1);
	}
	else
	{
		int nbr=wcOption_c(fichier);
		char *chaine=allocation(nbr);
		printf(" %d ",wcOption_l(fichier,chaine,nbr));
		printf("%d ",wcOption_w(fichier,chaine,nbr));
		printf("%d ",wcOption_c(fichier));
		printf("%s\n",file);
		
		free(chaine);
	fclose(fichier);		
	}	
}





