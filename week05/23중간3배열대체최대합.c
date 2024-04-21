#include <stdio.h>
#include <stdlib.h>

void insertion_sort1(int *A, int n) { //오름차순
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
	
	insertion_sort2(items,n); //배열a내림차순 정렬
	insertion_sort1(sequence,n);//배열b 올림차순 정렬

	int max=0;


	for(int i=0;i<k;i++) //k개 꼭!!!바꿔야함
		sequence[i]=items[i]; //작은수들 큰 a수들로 대체
	for(int i=0;i<n;i++) max+=sequence[i]; //최댓값 구하기
		


	printf("%d",max);
	free(items);
	free(sequence);
    
}
