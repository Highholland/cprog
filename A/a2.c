/* 
* naam student: Aron Hoogendam
*Student nummer: 21106029
* naam student 2: Stef Vernet
* Student nummer2: 19027869
*Opdracht: A2

*/


#include <stdio.h>

//main aanmaken
int main (){
	//variabelen aanmaken
	double t,v,n;
	//variabelen inlezen
	scanf("%lf%lf%lf",&t,&v,&n);
	//bepaalde term uitrekenen
	double a = t + v * (n-1);
	//de term op het scherm zetten
	printf("Term %.1f is: %.1f", n,a);
	return 0;
}
