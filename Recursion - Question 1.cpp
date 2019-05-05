#include <stdio.h>
#include <stdlib.h>

 int max = 0;

int MaximunValue(int * array, int tam){

	if(tam == 0){
		return max;
	}
	
	if(array[tam - 1]>= max){
		max = array[tam - 1];
	}
	
	return MaximunValue(array,tam - 1);
}

int main(){
	
	int array[10] = {0,30,20,1,300,70,100,24,9,4};
	
	printf("o item max eh: %i", MaximunValue(array, 10));
	
	return 0;
}
