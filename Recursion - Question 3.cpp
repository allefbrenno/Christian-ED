#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ground= 0;

int Palindrome(char *array, int alt){

	if(array[ground] == array[alt-1]){
		
		if(ground == alt)
			return 1;
		else{
			ground++;
			Palindrome(array, alt-1);
			
		}	
			
	}else{
		return -1;
	}	
}

int main(){
	
	char array [4] = {'u','b','u','u'};
	if(Palindrome(array, 4) == 1){
		printf("eh palindromo!");	
	}else{
		printf("nao eh palindromo!");
	}
	
	return 0;
}
