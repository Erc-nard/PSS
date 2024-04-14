#include <stdio.h>

int right_max_sum(int A[], int left, int right) {
	int i, max, sum;
	max = A[left];
	sum = A[left];
	for(i=left+1; i<=right; i++) {
		sum = sum + A[i];
		if(max < sum)
			max = sum;
	}
	return max;
} // Lab
int left_max_sum(int *A, int left, int right) {
	int i, max, sum;
	max = A[left];
	sum = A[left];
	for(i=left+1; i<=right; i++) {
		sum = sum + A[i];
		if(max < sum)
			max = sum;
	}
	return max;
} // Lab

int max_subarray(int *A, int left, int right) {
    int v1,v2,v3;
	int i, max=0, sum;
    if(left==right) return max;
    
    int m=(left+right)/2;
	v1=right_max_sum(A,m+1,right);
	v2=left_max_sum(A,left,m);
	//printf("%d %d %d \n",v1,v2,v3);
	
	max = A[right];
	sum = A[right];
	for(i=right-1; i>=left; i--) {
		sum = sum + A[i];
		if(max < sum)
			max = sum;
	}
	v3=max;
	
	
    //max_subarray(A,m+1,right);
   	//max_subarray(A,left,m);
	


} // ����

int main() {
 //int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // tc #1: max는 6
 //int A[] = {2, -1, 5, -2, 2, -3, 1}; // tc #2: max는 6
 //int A[] = {3, -1, 1, 2, 3, 1, -1, 5}; // tc #3: max는 13
 //int A[] = {1, 2, 3}; // tc #4: max는 6
 int A[] = {-1, -2, -3, -4}; //tc #5: max는 -1
 //int A[] = {5}; // tc #6: max는 5
 int lastIndex = sizeof(A) / sizeof(int) - 1;
 int max = max_subarray(A, 0, lastIndex);
 printf("max value = %d\n", max );
}
