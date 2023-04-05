/* 
* naam student: Aron Hoogendam
* student nummer: 21106029
* naam student2: Stef Vernet
* student nummer2; 19027869
*/

#include <stdio.h>
#include <math.h>
void abc(double a, double b, double c){
	double antwoordEen = (-1*b+sqrt(b*b - 4*a*c))/(2*a); //uitrekenen eerste antwoord abc formule en in double zetten
	double antwoordTwee = (-1*b-sqrt(b*b - 4*a*c))/(2*a); //uitrekenen tweede antwoord abc formule en in double zetten
	if(antwoordEen == antwoordTwee) { //kijken of de antwoorden hetzelfde zijn
		printf("De oplossing van %lfx^2 + %lfx + %lf is:\n x = %lf",a, b, c, antwoordEen); //als de antwoorden gelijk zijn wordt er maar 1 antwoord geprint
		} else {printf("De oplossingen van %lfx^2 + %lfx + %lf zijn:\nx1 = %lf, x2 = %lf",a, b, c, antwoordEen, antwoordTwee);} //als de antwoorden niet gelijk zijn worden er meerdere geprint
	}
double discriminant (double a, double b, double c){
	return b*b - 4*a*c; //uitrekenen discriminant
}
int main (void){
	double a, b, c; //variabelen aanmaken double
	int i, testcases; //variabelen aanmaken int
	scanf("%d\n", &testcases); //hoeveelheid testcases inlezen 
	for (i = 1; i <= testcases; i++) {//for loop voor de hoeveelheid testcases beginnen
		scanf("%lf %lf %lf", &a, &b, &c); //inlezen vaan double a, b en c
		if(discriminant( a, b, c) < 0){ //kijken of de discriminant kleiner is dan twee
		printf("Discriminant is negatief.\n");//zo ja dan wordt er aangegeven dat de discriminant negatief is
		printf("De vergelijking %lfx^2 + %lfx + %lf heeft geen reele oplossingen.",a, b, c); //en wordt de formule geprint
		} else { //zo niet gaat het de abc functie in.
			abc(a,b,c);	//begint the abc functie	
		}
	
}
return 0;
}
