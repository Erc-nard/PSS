#include <stdio.h>
#include <stdlib.h>

int s_b(int*list,int low,int high,int search){ //sort hitsuyo
    int m=(low+high)/2;
    if(low<=high){
    if(search==list[m]) return 1;
    else if(search<list[m])
        return s_b(list,low,m-1,search);
    else if(search>list[m])
        return s_b(list,m+1,high,search);
    }
    else return -1;

}void merge(int *A, int p, int q, int r, int* temp) {
	int i,j,t;

	i = p;
	j = q+1;
	t = p;

	while(1) {
		if(i>q || j>r)
			break;
		
		if(A[i] < A[j]) {
			temp[t] = A[i];
			i++;
		}
		else {
			temp[t] = A[j];
			j++;
		}
		t++;
	}

	if(i>q) { //왼쪽 subarray의 처리가 끝.
		//오른쪽 subarray 잔여 아이템을 복사
		for( ; j<=r ; j++, t++)
			temp[t] = A[j];
	}
	else {
		for( ; i<=q ; i++, t++)
			temp[t] = A[i];
	}

	for(i=p; i<=r; i++)
		A[i] = temp[i];
}

void merge_sort(int *A, int p, int r, int *temp) {
	if(p<r) {
		int q = (p+r)/2;
		merge_sort(A, p, q, temp);
		merge_sort(A, q+1, r, temp);
		merge(A, p, q, r, temp);
	}
}

int main(){

    int m,n;

    scanf("%d",&m);
    int* M=(int*)malloc(sizeof(int)*m);
    int* temp=(int*)malloc(sizeof(int)*m);
    for(int i=0;i<m;i++)
        scanf("%d",&M[i]);

    scanf("%d",&n);
    int* N=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&N[i]);

    int total=0;
    merge_sort(M,0,m-1,temp);
    for(int i=0;i<n;i++){
        if(s_b(M,0,m-1,N[i])==1) total+=1;
       // printf("%d ",total);
    }
    printf("%d",total);

    free(M);
    free(N);
}