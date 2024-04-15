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

	max = A[right];
	sum = A[right];
	for(i=right-1; i>=left; i--) {
		sum = sum + A[i];
		if(max < sum)
			max = sum;
	}
	return max;
} // Lab

int max_subarray(int *A, int left, int right) {
    int v1,v2,v3;

    	if(left==right) return A[left];
    int m=(left+right)/2;
	v1=max_subarray(A,m+1,right);
	v2=max_subarray(A,left,m);
	v3=right_max_sum(A,m+1,right)+left_max_sum(A,left,m);

	//printf("%d %d %d \n",v1,v2,v3);
	if(v3>=v1 && v3>=v2) return v3;
	else if(v2>=v1 && v2>=v3) return v2;
	else return v1;
} 

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
