#include<stdio.h>
#include "../include/20_MoveZeroes.h"

int main()
{
	int arr[6] = { 1,2,0,1,0};
	MoveZeroes(arr, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d	", arr[i]);
	}

	
}
