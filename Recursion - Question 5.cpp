#include <stdio.h>
#include <stdlib.h>


int Fribonacci(int n, int last, int novo){


	if(n == 0){
		return 1;
	}	
	
	if(last == 0 && novo == 0){
		printf("1");
		novo = 1;
		return Fribonacci(n-1, last, novo);
		
	}else{
		printf(",%i",(last+novo));
	}

	return Fribonacci(n-1, novo, last+novo);
}

int main(){
	
	Fribonacci(10,0,0);
	return 0;
}
