#include <stdio.h>
#include <stdlib.h>

#define Maxsize  20

struct Stack{
	char stacksize[Maxsize];
	int top;
};

void Push(struct Stack* s, char c){
	if(s->top < (Maxsize - 1)){
		s->stacksize[s->top + 1] = c;
		s->top++;
	}
	else{
		printf("A pilha esta cheia.");
		exit(1);
	}
};

char Pop(struct Stack* s){
	
	if(s->top == -1){
		printf("Sua pilha esta vazia.");
		exit(2);
	}
	
	char aux = s->stacksize[s->top-1];
	s->top--;		
	
	return aux;
};

int main (){
	
	int i;
	char parent[Maxsize];
	struct Stack test;
	test.top = -1;
	
	printf("digite os parenteses: ");
	scanf("%s", parent);
	
	for(i=0; i<20; i++){
		/*Verificação, se o parentese for "(" o programa ira dar push se não, pop*/
		if (parent[i] == '('){
			Push(&test,'(');
			}
			else if(parent[i] == ')'){
				if(test.top == -1 && parent[i] == ')'){
					printf("Numero de parenteses nao e igual!");
					return -1;
				}
				Pop(&test);
			}
	}
	/*Se o numero de push's for igual aos pop's então o numero de parenteses são iguais*/
	 if(test.top == -1){
	 	printf("os parenteses sao iguais!");
	 }else{
	 	printf("os parenteses nao sao iguais!");
	 }

	
	return 0;
}
