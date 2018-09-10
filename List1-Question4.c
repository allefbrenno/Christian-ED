#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int main(){
	
	struct Node* n1 = NULL;
	char teste[100];
	int i, str;
	int x,y;
	printf("Digite a conta: ");
	scanf("%[^\n]s", teste);
	str = strlen(teste);
	
	for(i = 0; i<str; i++){
		if(teste[i] == '+'){
			Push(&n1,Pop(&n1)+Pop(&n1));
		}else
		 	if(teste[i] == '-'){
				y = Pop(&n1)*(-1);
				Push(&n1,y+Pop(&n1));
		}
		else 
			if(teste[i] == '*'){
				Push(&n1, Pop(&n1)*Pop(&n1));
		}else 
			if(teste[i] == '/'){
				y = Pop(&n1);
				Push(&n1, Pop(&n1)/y);
		}else
		{
		x = teste[i]-'0';
		Push(&n1,x);
		}
	}
	
	printf("%i", Pop(&n1));
	
	return 1;
}
