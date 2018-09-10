#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct Node{
	int value;
	struct Node* next;
};

void Append(struct Node** node, int value){
	if(!*node){
		*node = (struct Node*) malloc (sizeof(struct Node));
		(*node)->value = value;
		(*node)->next = NULL;
	}
	else{
		struct Node *aux = *node;
		while(aux->next)
			aux = aux->next;
			
			aux->next = (struct Node*) malloc (sizeof(struct Node));
			aux->next->value = value;
			aux->next->next = NULL;
	}
}
void UniqueList(struct Node** node1, struct Node** node2, struct Node** node3){
	struct Node* aux1 = *node1;
	struct Node* aux2 = *node2;
	struct Node* aux3 = *node3 = (struct Node*) malloc (sizeof(struct Node));
	int i; 
	
	aux3->next = NULL;
	for(i=0;i<2*MAX_SIZE;i++){
		
		if(aux2 == NULL ||  aux1 == NULL || aux1->value<=aux2->value){
			while(aux3->next !=NULL ){
				aux3 = aux3->next;
			}
			
			if(aux1 !=NULL){
				aux3->value = aux1->value;
				printf("Valor do 1: %i\n", aux3->value);
				
			}else{
				aux3->value = aux2->value;
				printf("Valor do 2: %i\n", aux3->value);
				aux2 = aux2->next;
				
			}
			
			aux1 = aux1->next;
			if(aux1 != NULL || aux2 !=NULL){
			aux3->next = (struct Node*) malloc (sizeof(struct Node));
			aux3->next->next = NULL;	
			}
		
		}else{
			while(aux3->next !=NULL ){
				aux3 = aux3->next;
			}
			
			if(aux2 !=NULL){
				aux3->value = aux2->value;
				printf("Valor do 2: %i\n", aux3->value);
			
			}
			
			aux2 = aux2->next;
			if(aux1 != NULL || aux2 !=NULL){
			aux3->next = (struct Node*) malloc (sizeof(struct Node));
			aux3->next->next = NULL;	
			}
		}
	}		
}

int main (){
	
	struct Node* n1 = NULL;
	struct Node* n2 = NULL;
	struct Node* n3 = NULL;
	int i, x;
	
	for(i = 0;i<MAX_SIZE; i++){
		scanf("%i", &x);
		Append(&n1, x);	
	}
	
	for(i = 0;i<MAX_SIZE; i++){
		scanf("%i", &x);
		Append(&n2, x);	
	}
	
	UniqueList(&n1,&n2,&n3);
	
	return 1;
}
