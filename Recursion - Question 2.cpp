#include <stdio.h>
#include <stdlib.h>

int Potencia (int x, int y){
	
	if(x == 0){
		return 1;
	}
	
	return y * Potencia(x-1, y);
}


int main (){

	int x,y;
	 x = 3;
	 y = 4;
	printf("Potencia de %i elevado a %i eh : %i", y, x, Potencia(x, y));
	
	return 0;
}
