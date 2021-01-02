#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{	
	int valeur=0;	
	FILE* fluxLecture;
	FILE* fluxEcriture;

	fluxLecture=fopen("compte.txt","r");

	if(fluxLecture==NULL){
		fluxLecture=fopen("compte.txt","w");
		printf("1\n");
		fclose(fluxLecture);
		return EXIT_SUCCESS;
	}

	/*Si on arrive ici cest que l'ouverture du fichier cest bien passer*/

	fread(&valeur,sizeof(int),1,fluxLecture);
	printf("%d\n",valeur);
	
	fclose(fluxLecture);
	valeur++;
	
	fluxEcriture=fopen("compte.txt", "w");
	fwrite(&valeur,sizeof(int),1,fluxEcriture);
	fclose(fluxEcriture);

	return EXIT_SUCCESS;
}