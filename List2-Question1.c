#include <stdio.h>
#include <stdlib.h>

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

void Prepend(struct Node** node, int value){
	
	if(!(*node)){
		*node = (struct Node*) malloc (sizeof(struct Node));
		(*node)->value = value;
		(*node)->next = NULL;
	}
	else{
		struct Node* aux = (struct Node*) malloc (sizeof(struct Node));
		aux->value = value;
		aux->next = *node;
		*node = aux;
	}
}

void InsertAfter(struct Node* node, int value){
	//precisa de um ponteiro para o anterior.
	struct Node* aux = (struct Node*) malloc (sizeof(struct Node));
	aux->value = value;
	aux->next = node->next;
	node->next = aux;
}

void DeleteAfter(struct Node* node){
	//precisa de um ponteiro no anterior.
	node->next = node->next->next;
}
int main (){
	struct Node* n1 = NULL;
	
	//testanto as funções.
	int i=0;
	Append(&n1, 1);
	Append(&n1, 2);
	Prepend(&n1, 3);
	DeleteAfter(n1);
	
	Append(&n1, 4);
	Append(&n1, 5);
	DeleteAfter(n1);
	
	while (i<5){
		printf("Valor do print: %i \n", n1->value);
		n1 = n1->next;
		i++;
	}
	return 0;
}
