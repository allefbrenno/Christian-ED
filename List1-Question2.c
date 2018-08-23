#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

struct Stack{
	char stackSize[MAX_SIZE];
	int top;
};

void Push (struct Stack* s, char c)
{	
	if(s->top == (MAX_SIZE - 1)){
		printf("A lista esta cheia!\n Tente adicionar mais espaco.");
		exit(1);
	}
	s->top++;
	s->stackSize[s->top] = c;
};

char Pop (struct Stack* s){
	char aux;
	
	if(s->top == -1){
		printf("A pilha esta vazia!\n Impossivel remover itens.");
		exit(2);
	}
	
	aux = s->stackSize[s->top];
	s->top--;
	
	return aux;
};

int main(){
	
	int i;
	struct Stack test;
	test.top = -1;
	char frase [MAX_SIZE];
	int tamanho;
	
	test.top = -1;
	printf("Digite a frase: ");
	/* Comando para reconhecer palavras com espaço */
	scanf("%[^\n]s", frase);
	setbuf(stdin, NULL);
	
	tamanho = strlen(frase);
	
	/* Adiciona um push para cade letra ate o final da frase */
	for(i = 0 ;i<tamanho; i++){
		
		Push(&test, frase[i]);	
	}
	/* Apenas copio o pop agora para o inicio do array, fazendo assim a frase ficar invertida */
	for(i=0;i<tamanho; i++){
		
		frase[i] = Pop(&test);
	}
	/*Mostra a frase ao contrario */
	printf("ESARF AUS: ");
	
	for(i=0;i<tamanho; i++){
		
		printf("%c",frase[i]);
	}
	
	return 0;
}
