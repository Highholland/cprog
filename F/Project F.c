#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int getal;
  struct Node* next;
};
typedef struct Node node;
struct Queue
{
  node* head;
  node* tail;
};
typedef struct Queue Queue;

int isLeeg (	struct Queue Q ) ;
int head (	struct Queue Q ) ;
void delHead (	struct Queue *Q ) ;
void voegToe (	struct Queue *Q, int x ) ;



int main ()	{
	int antwoord;
	int hoofd;	
	Queue Q ;
//	node N;
//	N.getal = 2;
//	N.next->getal = 8; DIT KAN DUS NOOIT VRIENDELIJKE GROET DE 4 UUR DIE JE HIER NAAR GEKEKEN HEBT.
//	N.next->next = NULL;	
	Q.head = NULL;
	Q.tail = NULL;
//	Q.head = &N;
//	Q.tail = &N;

	antwoord = isLeeg(Q);
	printf("%d \n", antwoord);  //1
//	printf("%d \n", Q.tail->getal);//2
	delHead (&Q) ;
	voegToe(&Q, 5);
	voegToe(&Q, 6);
	voegToe(&Q, 7);
	hoofd = head(Q);
	printf("%d \n", hoofd);//5
	printf("%d \n", Q.head->getal);//5
	printf("%d \n", Q.tail->getal);//7
	delHead (&Q) ;
	printf("%d \n", Q.head->getal);//6
	
	return 0;
}

int isLeeg(	struct Queue Q ) {
	if (Q.head == NULL && Q.tail == NULL)	{
		return 1;
	} else {
		return 0;
	}
}
int head (	struct Queue Q ) {
	if(Q.head == NULL)return 69;
	return Q.head->getal;
}
void delHead (	struct Queue *Q ) {
	if(!isLeeg(*Q)){//
		node *hulp = Q->head->next;//hulp variabeln die naar next wijst, want the node waar next in zit wordt verwijderd.
		free(Q->head); //Hier wordt de node verwijdered maar the pointer naar next hebben we dus nog in de hulp variabelen. 
		Q->head = hulp; //hier wordt de invalid head aangewezen naar de hulp pointer die naar de next wijst. Waardoor de head nu de next is geworden. 
		hulp = NULL;// hulp variabel resetten
	}
else printf("Error stop, the c is on fire can't you c.\n");
}

void voegToe (struct Queue *Q, int x){
	node *ptr = malloc(sizeof(node));
	ptr->getal = x;
	if(isLeeg(*Q)) {
		Q->head = ptr;
		Q->tail = ptr;
	}
	else{
		Q->tail->next = ptr;
		Q->tail = ptr;
	}
}




