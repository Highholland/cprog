/* 
* naam student: Aron Hoogendam
*Student nummer: 21106029
* naam student2: Stef Vernet
*Student nummer2: 19027869
*Opdracht: C2
*/
#include <stdio.h>
double bereken_gemiddelde (int getal)
{
 static int som = 0;//static variabelen aanmaken om waarde behouden wanneer deze functie meerdere keren aangeroepen wordt
 static double berekening = 0;
 static int aantal = 1;
 som = som + getal;//elk getal wordt bij de andere getallen opgeteld
 berekening = (double)som / aantal;// uitrekenen gemiddelde
 aantal++;//verhogen aantal getallen dat ingevoerd zijn
 return berekening;
 
}
int main(void)
{
 double gemiddelde;//variabele aanmaken double
 while (1) //while loop zolang er geen 0 ingevoerd wordt
 {
 int getal;//variabele aanmaken int
 scanf("%d", &getal);//inlezen van getal
 if (getal == 0)//kijken of getal 0 is
 break;//zo ja dan wordt er uit de while loop gegaan met een break
 else //zo niet krijgt de double gemiddelde een waarde met de functie bereken_gemiddelde
 gemiddelde = bereken_gemiddelde(getal);
 }
 printf("%.1f\n", gemiddelde);//en wordt de double gemiddelde geprint
 
 return 0;
}

