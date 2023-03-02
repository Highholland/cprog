/* 
* naam student: Aron Hoogendam
*Student nummer: 21106029
* naam student 2: Stef Vernet
* Student nummer2: 19027869
*Opdracht: G1,2

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
void koppelA (struct Queue *Q, struct Queue *R);
void koppelB (struct Queue *Q, struct Queue *R);
struct Queue* copy (struct Queue Q);



int main ()	{
	int antwoord; //variabelen int aanmaken genaamd antwoord
	int hoofd;	//variabelen int aanmaken genaamd hoofd
	Queue Q, R; //variabelen Queue aanmaken genaamd Q	
	Queue *T; //variabelen pointer T die naar een Queue struct wijst

	Q.head = NULL; //de eerste pointer in Q op NULL zetten
	Q.tail = NULL; //de tweede pointer in Q op NULL zetten
	R.head = NULL; //de head van R op NULL zetten
	R.tail = NULL; //de tail van R op NULL zetten

	antwoord = isLeeg(Q); //Variabelen de waarde geven de functie is leeg returned, struct Q wordt meegegeven als parameter
	printf("%d \n", antwoord);  //1 of 0 printen
	delHead (&Q) ;//het leegmaken van de Q.head echter bestaat deze node nog niet dus wordt de else in die functie uiigevoerd
	
	voegToe(&R, 8); //8 toevoegen aan struct R
	voegToe(&R, 9); //9 toevoegen aan struct R
	voegToe(&R, 10); //10 toevoegen aan struct R

	voegToe(&Q, 5); //node toe voegen met getal 5
	voegToe(&Q, 6); //node toe voegen met getal 6
	voegToe(&Q, 7); //node toe voegen met getal 7
	
	printf("%d \n", R.tail->getal);//uit printen van het getal van in de node tail van R staat
	hoofd = head(Q); //variabelen hoofd zetten naar het getal in de eerste nood
	printf("%d \n", hoofd);//deze variabelen printen
	printf("%d \n", Q.head->getal);//de head->getal printen om te kijken of het hetzelfde is als de variabelen hoofd
	printf("%d \n", Q.tail->getal);//de tail uitprinten om te kijken of de laatste node gezet is
	delHead (&Q);//de head node verwijderen en die naar de volgende laten wijzen
	printf("%d \n", Q.head->getal);//de nieuwe head->getal laten zien om te bewijzen dat er een head is verwijderd
	//koppelB(&Q, &R);//Q en R aan elkaar verbinden door middle van functie A
	koppelA(&Q, &R); //Q en R aan elkaar verbinden door middle van functie B
	printf("%d \n", Q.head->getal); //head getal van Q printen om te kijken of het nog steeds klopt
	printf("%d \n", Q.tail->getal); //tail bekijken of die naar de juist is veranderd
	T = copy(Q); //kopieren van struct Q
	printf("%d \n", T->head->getal);//controleren wat er in t head getal staat
	printf("%d \n", T->tail->getal);//controleren wat er in t tail getal staat
	printf("%p \n", Q.head); //het adress van q head laten zien
	printf("%p \n", Q.tail); //het adress van q tail laten zien
	printf("%p \n", T->head); //het adress van t head laten zien en deze moet anders zijn dat q
	printf("%p \n", T->tail); //het adress van t head laten zien en deze moet anders zijn dat q
	return 0;
}

int isLeeg(	struct Queue Q ) {//functie aanmaken isLeeg met struct Q als parameter
	if (Q.head == NULL && Q.tail == NULL)	{//vergelijking die kijkt of er een Node in head en tail zitten.
		return 1;//zo ja returnen we 1/waar
	} 
	else {//zo nee
		return 0;//dat returnen we 0/niet waar
		}
}
int head (	struct Queue Q ) {//functie head aanmaken met struct Q als parameter
	if(Q.head == NULL)return 0;//kijken of is leeg waar is zo ja 505 returnen want dan is er geen getal om te returnen
		return Q.head->getal; //zo nee het getal dat in node head staat returnen
}
void delHead (	struct Queue *Q ) {//functie delhead aanmaken met pointer naar Q als parameter 
	if(Q->head == Q->tail && !isLeeg(*Q)){
	free(Q->head);//leeg maken van q->head
	Q->head = NULL; //de eerste pointer in Q op NULL zetten
	Q->tail = NULL; //de tail op NULL zetten
	}
	else if(!isLeeg(*Q)){//kijken of isleeg nietwaar is, als dit namelijk waar is is er geen node om te verwijderen
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
	Q->tail->next = NULL;//de pointer next op NULL zetten
}


void koppelA (struct Queue *Q, struct Queue *R) { 
	while(!isLeeg(*R)){//while loop terwijl pointer R niet leeg is.
//		printf("%d \n",R->head->getal);//toont de head van R ter controle
		voegToe(Q, R->head->getal);//voegt het getal in R->head toe aan Q met de functie voegToe
		delHead(R);//verwijderd de head van R
}
}

void koppelB (struct Queue *Q, struct Queue *R){//functie die R koppelt aan Q
	Q->tail->next = R->head; //de tail next van Q laten wijzen naar de head van R
	Q->tail= R->tail; //de tail van q laten wijzen naar de tail van R
	R->head = NULL;//R head nergens naar laten wijzen
	R->tail = NULL;//R tail nergerns naar laten wijzen
}

struct Queue* copy (struct Queue Q){//functie die een pointer naar een struct retourneert 
	Queue *T = malloc(sizeof(Queue));//struct T ruimte geven in het geheugen (head)
	node *B = Q.head; //node pointer aanmaken oom door Q door te lopen, die begint door naar Q head te wijzen
	T->head = NULL;//head van t naar NULL zetten
	T->tail = NULL;//tail van t naar NULL zetten
	if(Q.head == NULL)//als Q.head leeg is, is er ook niks om te kopieren 
		return T; //retourneren van T
	else{
		node *nptr = malloc(sizeof(node));//nptr pointer naar node aanmaken en de node in de heap zetten
		while( B != NULL){//zolang B niet leeg is
			nptr->getal = B->getal;//het getal in nptr gelijk stellen aan het getal in B
			if(T->head==NULL) {//als t nog leeg is
				T->head = nptr; //T head op nptr zetten
				T->tail = nptr; //maar ook T tail op nptr zetten aangezien deze bij één node in T hetzelfde zijn
			}
			else{
				T->tail->next = nptr;  //De next van tail naar nptr laten wijzen
				T->tail = nptr;  //nu de tail naar 
				}
			nptr->next = malloc(sizeof(node));//de next node van nptr ruimte geven in het geheugen (heap)
			nptr = nptr->next;//nptr als de next nptr zetten
			T->tail->next = NULL; //de tail->next pointer op NULL zetten want die bestaat niet
			B = B->next; //de volgende stap in Q zetter
			}
		return T; //retouneren van de pointer van T
	}
}

