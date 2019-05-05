#include <stdio.h>
#include <stdlib.h>


int BinarySearch(int n, int low, int high, int *array){
	
	int mid = (low+ high)/2;
	
	if(low > high)
		return -1;
		
	if(array[mid] == n){
		printf("encontrado\n");
		return mid;
		
	}
	
	if(array[mid] > n){
		return BinarySearch(n,low, mid-1, array);
	}else{
		return BinarySearch(n,mid+1, high, array);
	}
	
}


int main(){
	
	int merda[10] = {0,3,5,12,15,16,17,20,30,31};
	
	printf("%i", BinarySearch(25,0,10,merda));
	
	return 0;
}
