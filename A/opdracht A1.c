/* 
* naam student: Aron Hoogendam
*Student nummer: 21106029
* naam student 2: Stef Vernet
* Student nummer2: 19027869
*Opdracht: A1
*/

#include <stdio.h>
int main () {
	//variabelen aanmaken:
	double kelvin, celcius, fahrenheit;
	//celcius inlezen
	scanf ("%lf", &celcius);
	//kelvin berekenen
	kelvin = celcius + 273.15; 
	//fahrenheit berekenen
	fahrenheit = celcius * 1.8 + 32;
	//Temperaturen printen
	printf ("C		K		F\n");
	printf ("%.2f		%.2f		%.2f\n", celcius, kelvin, fahrenheit);
	return 0;
}
