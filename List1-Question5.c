#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

struct stack{
	
	char stackSize[MAX_SIZE][2];
	int top1,top2;
	
};

void Push(struct stack* s,char c, int p){
	if(p == 1){
	
		if(s->top1 < (MAX_SIZE - 1)){
			s->top1++;
			s->stackSize[s->top1][p-1] = c;
			printf("o valor o item eh: %c\n", s->stackSize[s->top1][p-1]);
		}else{
			printf("Pilha 1 esta cheia!");
			exit(1);
		}
		
	}else if(p == 2){	
	
		if(s->top2 < (MAX_SIZE - 1)){
			s->top2++;
			s->stackSize[s->top2][p-1] = c;	
			printf("o valor o item 2 eh: %c\n", s->stackSize[s->top2][p-1]);
		}
		printf("Pilha 2 esta cheia!");
		exit(1);		

	}
};


char Pop(struct stack* s, int p){
	char aux;
	
	if(p==1){
		if(s->top1 >= 0){
			aux = s->stackSize[s->top1][p-1];
			s->top1--;
			return aux;
		}
		
	}else 
		if(p==2){
			if(s->top2 >= 0){
				aux = s->stackSize[s->top2][p-1];
				s->top2--;
				return aux;
		}
	}
	
};



int main(){
	
	struct stack teste;
	teste.top1 = -1;
	teste.top2 = -1;
	/*Pilha criada com uma matriz e pronta para ser utilizada, utilizando 0 ou 1 para
	selecionar qual deseja alterar*/
		
	Push (&teste,'6', 1);
	Push (&teste,'4', 0);
	Push (&teste,'6', 1);
	/*Possivelmente será alterado, já que o docente queria com apenas utilizando array, e não matriz.*/
	printf("O valor do pop eh:%c \n", Pop(&teste,1));
	printf("O valor do pop eh:%c \n", Pop(&teste,1));
	
	return 0;
}
