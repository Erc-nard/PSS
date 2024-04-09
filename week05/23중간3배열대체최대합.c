#include <stdio.h>
#include <stdlib.h>

void insertion_sort1(int *A, int n) {
	int i, j, k, temp;

	for(i=1; i<n; i++) {
		for(j=0; j<i; j++)
			if(A[i] < A[j]) 
				break;

		temp = A[i];

		for(k=i; k>j; k--) 
			A[k] = A[k-1];

		A[j] = temp;
	}
}
void insertion_sort2(int *A, int n) { //내림차순
	int i, j, k, temp;

	for(i=1; i<n; i++) {
		for(j=0; j<i; j++)
			if(A[i] > A[j]) 
				break;

		temp = A[i];

		for(k=i; k>j; k--) 
			A[k] = A[k-1];

		A[j] = temp;
	}
}

int main() {
	int n,k;
	scanf("%d", &n);
	scanf("%d",&k);

    int* items=(int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        scanf("%d",&items[i]);
    }

    int* sequence=(int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        scanf("%d",&sequence[i]);
    }
	
	insertion_sort2(items,n);
	insertion_sort1(sequence,n);

	int max=0;


	for(int i=0;i<k;i++) //k개 꼭!!!바꿔야함
		sequence[i]=items[i];
	for(int i=0;i<n;i++) max+=sequence[i];
		


	printf("%d",max);
	free(items);
	free(sequence);
    
}
