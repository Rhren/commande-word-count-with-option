#include <stdio.h>
#include "wcCmd.h"
#include "wcCmd.c"
int main(int argc,char *argv[])
{
	if(argc == 3)
	{
		all_option(argv[2],argv[1]);
	}	
	else if(argc == 2)
	{
		FILE *fichier=NULL;
		wcNoOption(fichier,argv[1]);
	}
	else
	{
		error();
	}
	
	return 0;
}


	


