#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node* next;
};

void Append(struct Node** node, int value){
	
	if(!(*node)){
		(*node) = (struct Node*) malloc (sizeof(struct Node));
		(*node)->value = value;
		(*node)->next = NULL;
	}
	else{
		
		struct Node* aux = *node;
		//o valor do "push" continua constante des que o ponteiro esteja apontado antes.
		while(aux->next)
			aux = aux->next;
		
		aux->next = (struct Node*) malloc (sizeof(struct Node));
		aux->next->next = NULL;
		aux->next->value = value;
	}
}

int PopList(struct Node** node){
	int x;
	struct Node* aux = *node;
	
	if(aux->next == NULL){
		x = aux->value;
		(*node) = NULL;
		
		return x;	
	}
	//o valor do pop continua constante des que o ponteiro esteja apontado antes.
	while(aux->next->next)
		aux = aux->next;
		
	x = aux->next->value;
	aux->next = NULL;
	
	return x;	
}

int main (){

	struct Node* n1 = NULL;
	
	Append(&n1, 2);
	Append(&n1, 3);
	Append(&n1, 4);
	
	printf("Valor retornado: %i\n", PopList(&n1));
	printf("Valor retornado: %i\n", PopList(&n1));			
	printf("Valor retornado: %i\n", PopList(&n1));
	
		
	return 0;	
}
