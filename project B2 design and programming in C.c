/* 
* naam student: Aron Hoogendam
*Student nummer: 21106029
* naam student2: Stef Vernet
* student nummer2; 19027869
*/
// benodigdheden includen
#include<stdio.h>
// nodig voor wiskundige functies
#include<math.h>
int main(){
	//variabelen aanmaken
	int priem, i;
	//priem getal inlezen
	scanf("%d",&priem);
	//kijken of het priemgetal 2 is en aangeven dat het het priemgetal 2 is
	if(priem == 2) printf("Het getal is het priemgetal 2.");
	//kijken of het priemgetal kleiner is dan 2 en aangeven dat het geen priemgetal is als dat zo is
	if(priem< 2) printf("Het getal %d is geen priemgetal want het is te klein.\n", priem);
	//als het priemgetal groter is als 2 en het is geen 2 gaat het de else in
	else{
		//for loop voor het delen van priem door getallen tot i gelijk of groter is dan wortel van het priemgetal
		for( i =2; i<=sqrt(priem);i++){
			//kijken of priemgetal gedeeld door i geen nul is
			if(!(priem % i)) {
				//als dit wel een nul is wordt aangegeven dat het geen priemgetal is
			printf("Het getal %d is geen priemgetal.\n", priem);
			// zorgen dat de for loop stopt door de i in priem te veranderen wat altijd groter is dan wortel priem
			i = priem;}
		}
		//op het scherm zetten dat het daadwerkelijke ook een priemgetal is, door dat i in priem veranderd is als het een priemgetal is.
		if(i<priem)printf("Het getal %d is een priemgetal.", priem);
		
	}
	
	
}
