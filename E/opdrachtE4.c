/* 
* naam student: Aron Hoogendam
*Student nummer: 21106029
* naam student 2: Stef Vernet
* Student nummer2: 19027869
*Opdracht: E4

*/



#include <stdio.h>
#include <string.h>


int main (void) {
	int gelijk = 0; //variabelen gelijk maken en op nul zetten.
	char zin [50]; //string aanmaken in de vorm van een char array die max 50 char lang is
	char *pzin = zin; //pointer maken die naar zin wijst
	char *pzinnen = zin;//tweede pointer die naar zin wijst
	pzinnen++;//pzinnen wijst nu naar het tweede char in de char array
	fgets(zin, sizeof(zin), stdin); //het inlesen van de zin met behulp van fgets
	char letter1,letter2; //aanmaken van twee chars
	scanf("%c %c", &letter1, &letter2);//inlezen van de chars
	while(*pzinnen)	{//while loop terwijl *pzinnen niet nul is oftewijl zolang het waar is
		if(letter1 == *pzin && letter2 == *pzinnen)	{//if als char letter 1 gelijk is aan een char in het array en letter 2 gelijk is aan het daar opvolgende char in het array aangegeven met pointers.
			gelijk++;}//tellen hoevaak het overeen komt 
		pzin++;//de eerste pointer gaat wijzen naar het volgende char in het array
		pzinnen++; //de tweede pointer gaat ook naar de volgende char in het array
	}
	printf("%d",gelijk);//laten zien hoeveel er overeenkomen. 
	return 0;
}
