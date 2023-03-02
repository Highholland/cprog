/* 
* naam student: Aron Hoogendam
*Student nummer: 21106029
* naam student 2: Stef Vernet
* Student nummer2: 19027869
*Opdracht: F1,2,3,4

*/

#include <stdio.h>
#include <stdlib.h>
struct Node //struct Node aanmaken
{
  int getal; //eerste element van de stuct als int zetten
  struct Node* next; //tweede element is pointer naar volgende struct
};
typedef struct Node node; //struct hernamen naar node voor makkelijk aanroepen
struct Queue //struct Queue aanmaken
{
  node* head; //eerste element van struct is pointer naar een struct node genaamd head
  node* tail;//tweede element van struct is pointer naar een struct node genaamd tail
};
typedef struct Queue Queue; //struct hernmen naar Queue vor makkelijk aanroepen

int isLeeg (	struct Queue Q ) ; 
int head (	struct Queue Q ) ;
void delHead (	struct Queue *Q ) ;
void voegToe (	struct Queue *Q, int x ) ;



int main ()	{
	int antwoord; //variabelen int aanmaken genaamd antwoord
	int hoofd;	//variabelen int aanmaken genaamd hoofd
	Queue Q; //variabelen Queue aanmaken genaamd Q	
	Q.head = NULL; //de eerste pointer in Q op NULL zetten
	Q.tail = NULL; //de tweede pointer in Q op NULL zetten
//	Q.head = &N;
//	Q.tail = &N;
//  Q.head->next->getal = 8; KAN NOOIT WANT DIE BESTAAT NOG NIET JE MOET EERST DIE RUIMTE MAKEN IN HET GEHEugen

	antwoord = isLeeg(Q); //Variabelen de waarde geven de functie is leeg returned, struct Q wordt meegegeven als parameter
	printf("%d \n", antwoord);  //1 of 0 printen
//	printf("%d \n", Q.tail->getal);//2
	delHead (&Q) ;//het leegmaken van de Q.head echter bestaat deze node nog niet dus wordt de else in die functie uiigevoerd
	voegToe(&Q, 5); //node toe voegen met getal 5
	voegToe(&Q, 6); //node toe voegen met getal 6
	voegToe(&Q, 7); //node toe voegen met getal 7
	hoofd = head(Q); //variabelen hoofd zetten naar het getal in de eerste nood
	printf("%d \n", hoofd);//deze variabelen printen
	printf("%d \n", Q.head->getal);//de head->getal printen om te kijken of het hetzelfde is als de variabelen hoofd
	printf("%d \n", Q.tail->getal);//de tail uitprinten om te kijken of de laatste node gezet is
	delHead (&Q);//de head node verwijderen en die naar de volgende laten wijzen
	printf("%d \n", Q.head->getal);//de nieuwe head->getal laten zien om te bewijzen dat er een head is verwijderd
	
	return 0;
}

int isLeeg(	struct Queue Q ) {//functie aanmaken isLeeg met struct Q als parameter
	if (Q.head == NULL && Q.tail == NULL)	{//vergelijking die kijkt of er een Node in head en tail zitten.
		return 1;//zo ja returnen we 1/waar
	} else 
		{//zo nee
		return 0;//dat returnen we 0/niet waar
		}
}
int head (	struct Queue Q ) {//functie head aanmaken met struct Q als parameter
	if(Q.head == NULL)return 505;//kijken of is leeg waar is zo ja 505 returnen
	return Q.head->getal; //zo nee het getal dat in node head staat returnen
}
void delHead (	struct Queue *Q ) {//functie delhead aanmaken met pointer naar Q als parameter 
	if(!isLeeg(*Q)){//kijken of isleeg nietwaar is, als dit namelijk waar is is er geen node om te verwijderen
		node *hulp = Q->head->next;//hulp variabeln die naar next wijst, want the node waar next in zit wordt verwijderd.
		free(Q->head); //Hier wordt de node verwijdered maar the pointer naar next hebben we dus nog in de hulp variabelen. 
		Q->head = hulp; //hier wordt de invalid head aangewezen naar de hulp pointer die naar de next wijst. Waardoor de head nu de next is geworden. 
		hulp = NULL;// hulp variabel resetten
	}
else printf("Error there is no Node to delete.\n");//als de head leeg is wordt dit geprint
}

void voegToe (struct Queue *Q, int x){//functie voeg toe aan maken met int en pointer naar Q als variabelen
	node *ptr = malloc(sizeof(node));//pointer naar node hulp variabelen aanmaken en deze ruite associeren in het geheugen met malloc in een node
	ptr->getal = x;//het getal in de node ptr wordt als x int variabelen gezet
	if(isLeeg(*Q)) {//er wordt gekeken of de Q leeg is
		Q->head = ptr; //zo ja gaat head wijzen naar de node waar ptr naar wijst
		Q->tail = ptr; //zo ja gaat head wijzen naar de node waar ptr naar wijst
	}
	else{
		Q->tail->next = ptr; //zo nee dan wijst de pointer van tail->next naar de node in ptr
		Q->tail = ptr;//zo nee dan wijst de Q->tail nu naar de ptr waardoor het de next is geworden.
	}
}




