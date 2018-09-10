#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct Node{
	int value;
	struct Node* next;
};

void Push(struct Node** node, int x){
	
	if(!(*node)){
		(*node) = (struct Node*) malloc (sizeof(struct Node));
		(*node)->value = x;
		(*node)->next = NULL;
	}else{
	struct Node* aux = *node;
	
	while(aux->next != NULL)
		aux = aux->next;
		
	aux->next = (struct Node*) malloc (sizeof(struct Node));
	aux->next->value = x;
	aux->next->next = NULL;	
		
	}
}

int Pop(struct Node** node){
	if(!*node){
		printf("Vazio\n");
		exit(0);
	}else{
		struct Node* aux1 = *node;
		int aux;
		if(aux1->next == NULL){
			aux = aux1->value;
			*node = NULL;
			return aux;
		}
		while (aux1->next->next !=NULL)
			aux1 = aux1->next;
			
		aux = aux1->next->value;
		aux1->next = NULL;
		
		return aux;
	}
	
}

void Revert(struct Node** node){
	int aux[MAX_SIZE];
	int i;
	
	for(i=0;i<MAX_SIZE;i++){
		aux[i] = Pop(&(*node));
	}
	for(i=0;i<MAX_SIZE;i++){
		Push(&(*node), aux[i]);
	}
}
int main(){
	
	struct Node* n1 = NULL;
	int x , i =0;
	
	for(i=0;i<MAX_SIZE;i++){
		scanf("%i",&x);
		Push(&n1,x);
	}
	Revert(&n1);
	
	for(i=0;i<MAX_SIZE;i++){
		printf("Valor: %i\n", Pop(&n1));
	}
	
	return 1;
}
