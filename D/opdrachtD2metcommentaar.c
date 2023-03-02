/* 
* naam student: Aron Hoogendam
*Student nummer: 21106029
* naam student 2: Stef Vernet
* Student nummer2: 19027869
*Opdracht: D2

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void puntenArray(char park[][10]); //aangeven dat er later een funcie wordt gebruikt
void letterArray(char park [][10]); //aangeven dat er later een funcie wordt gebruikt
void printArray(char park [][10]); //aangeven dat er later een funcie wordt gebruikt

int main (void) {
	char park[10][10]; //2D char array maken dat 10x10 groot is
	puntenArray(park); //puttenArray functie aanroepen met parameter park
	letterArray(park); //letterArray functie aanroepen met parameter park
	printArray(park); //printArray functie aanroepen met parameter park
	return 0;
}

void puntenArray(char park [][10]) { //aanmaken functie puntenarray, die het 2d array vult met punten
	int i,j; //variabelen i en j aanmaken
	for(i=0; i < 10; i++) {//for loop terwijl i kleiner is dan 10
		for(j=0; j < 10; j++) {//for loop terwijl j kleiner is dan 10
			park [i][j] = '.';//zorgt dat een punt wordt ingevuld op alle plekken waar de for loops langslopen
		}
	}
}
void letterArray(char park [][10]) {//aanmaken functie letterarray, die random letters loop door het array
	int y,x,i,w, teller, ok; //maken van 6 variabelen
	x = 0; //x gelijkstellen aan 0
	y = 0; //y gelijkstellen aan 0
	srand(time(NULL));//random getal opzetten m.b.v. tijd
	park[y][x] = 65; //Plek nul nul in het array als A zetten
	for (i= 1; i < 26; i++)	{//for loop voor alle letters oftewijl 25 sprongetjes om alle letters mee tenemen
		w = rand () % 4; //random getall bepalen wat 0 t/m 3 kan zijn.
		ok=0; //ok gelijk stellen aan nul
		teller = 0; //teller gelijk stellen aan nul
		while ( ok == 0 && teller < 4 ) {//while loop voor zolang ok nul is en teller kleiner dan vier. Dit is omdat ok aangeeft of het goed was of niet en de teller of alle mogelijkheden zijn geprobeerd.
			switch (w)	{//switch case om te kijken wat er moet gebeuren in elke scenario 
				case 0: //als her random getal 0 is gebeurd er dit
					if(x+1 < 9 && park[y][x+1] == 46 ) {//valt de stap naar recht binnen het array en staat er een punt
						x++; //zo ja dan wordt de x permanent omhoog gedaan
						park[y][x] = i+65; //op deze plek wordt het volgende letter geplaatst
						ok=1;//en aangeven dat het gelukt is en die dus uit de while loop kan
					}
					else {//als het niet kan omdat het uit de array valt of dat het al ingevuld is met een letter dan gebeurt dit.
						w++; //het random getal wordt met 1 omhoog gedaan zodat er de volgende keer in de while en de switch er hopeijk een ander resultaat uitkomt
						teller++; //de teller telt hoevaak het random getal veranderd is en als dit 4x veranderd is heeft alle mogelijke waardes gehad
					}
					break; //slaat het uit de witch case terug naar de while
				case 1:
					if(x-1 > 0 && park[y][x-1] == 46 ) {//valt de stap naar links binnen het array en staat er een punt
						x--; //zo ja dan wordt de x permanent omlaag gedaan
						park[y][x] = i+65;//op deze plek wordt het volgende letter geplaatst
						ok=1;//en aangeven dat het gelukt is en die dus uit de while loop kan
					}
					else {//als het niet kan omdat het uit de array valt of dat het al ingevuld is met een letter dan gebeurt dit.
						w++; //het random getal wordt met 1 omhoog gedaan zodat er de volgende keer in de while en de switch er hopeijk een ander resultaat uitkomt
						teller++; //de teller telt hoevaak het random getal veranderd is en als dit 4x veranderd is heeft alle mogelijke waardes gehad
					}
					break; //slaat het uit de witch case terug naar de while
				case 2:
					if(y+1 < 9 && park[y+1][x] == 46 ) {//valt de stap naar beneden binnen het array en staat er een punt
						y++; //zo ja dan wordt de y permanent omhoog gedaan
						park[y][x] = i+65; //op deze plek wordt het volgende letter geplaatst
						ok=1;//en aangeven dat het gelukt is en die dus uit de while loop kan
					}
					else {//als het niet kan omdat het uit de array valt of dat het al ingevuld is met een letter dan gebeurt dit.
						w++; //het random getal wordt met 1 omhoog gedaan zodat er de volgende keer in de while en de switch er hopeijk een ander resultaat uitkomt
						teller++; //de teller telt hoevaak het random getal veranderd is en als dit 4x veranderd is heeft alle mogelijke waardes gehad
					}
					break; //slaat het uit de witch case terug naar de while
				case 3:
					if(y-1 > 0 && park[y-1][x] == 46 ) {//valt de stap naar boven binnen het array en staat er een punt
						y--; //zo ja dan wordt de y permanent omlaag gedaan
						park[y][x] = i+65;//op deze plek wordt het volgende letter geplaatst
						ok=1;//en aangeven dat het gelukt is en die dus uit de while loop kan
					}
					else {//als het niet kan omdat het uit de array valt of dat het al ingevuld is met een letter dan gebeurt dit.
						w = w-3;//het random getal wordt met 3 omlaag gedaan zodat er de volgende keer in de while en de switch er hopeijk een ander resultaat uitkomt
						teller++; //de teller telt hoevaak het random getal veranderd is en als dit 4x veranderd is heeft alle mogelijke waardes gehad
					}
					break; //slaat het uit de witch case terug naar de while
			}
			
							
		}
		if (teller == 4) {//als de teller 4 is zijn er geen mogelijke richtingen meer en hoeft de for loop dus niet door te gaan
				break;//dit zorgt ervoor dat de for loop gestopt wordt. 
		}
	}
}
void printArray(char park [][10]) {//aanmaken printArray dat het arraymet de letters laat zien
	int k,l;//2 variabelen aanmaken voor de for loop
	for(k=0; k < 10; k++) {//zolang k kleiner is dan 10
		for(l=0; l < 10; l++) {//zolang l kleiner is dan 10
			printf("%c ", park[k][l] ); //uitprinten van het char in het array
		}
		printf("\n");//nieuwe regel zodat het 2D array niet in een D te zien is. Oftewijl dat het niet allemaal achter elkaar staat.
	}
}
