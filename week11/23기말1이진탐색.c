#include <stdio.h>
#include <stdlib.h>

int s_b(int*list,int low,int high,int search){ //sort해야 제대로 돌아감!!!
    int m=(low+high)/2; //list중앙값
    if(low<=high){
		if(search==list[m]) //찾는값과 정확히 같다면 1 return
			return 1;
		else if(search<list[m]) //중앙값보다 검색값이 작으면 중앙기준 왼쪽부분만 탐색
			return s_b(list,low,m-1,search);
		else if(search>list[m]) // 크면 중앙기준 오른쪽부분만 탐색
			return s_b(list,m+1,high,search);
		}
    else return -1; //다 찾았는데 없다면 -1 return

}void merge(int *A, int p, int q, int r, int* temp) {
	int i,j,t;

	i = p;
	j = q+1;
	t = p;

	while(1) {
		if(i>q || j>r) //전부정렬하면 끝
			break;
		
		if(A[i] < A[j]) {
			temp[t] = A[i]; //i와 t중 더 작은걸 temp배열에 넣음
			i++; //i와 t중 더작은거 넣고 넣은거 ++함
		}
		else {
			temp[t] = A[j];
			j++;
		}
		t++;
	}

	if(i>q) { //왼쪽 subarray의 처리가 끝.
		//오른쪽 subarray 잔여 아이템을 복사
		for( ; j<=r ; j++, t++) //남은것들 다 temp에 넣음
			temp[t] = A[j];
	}
	else {
		for( ; i<=q ; i++, t++)
			temp[t] = A[i];
	}

	for(i=p; i<=r; i++) //temp 다시 A로 복사
		A[i] = temp[i];
}

void merge_sort(int *A, int p, int r, int *temp) {
	if(p<r) {
		int q = (p+r)/2;
		merge_sort(A, p, q, temp); //왼쪽정렬
		merge_sort(A, q+1, r, temp); //오른쪽정렬
		merge(A, p, q, r, temp); //정렬된거 합치기
	}
}

int main(){

    int m,n;

    scanf("%d",&m); //물건개수
    int* M=(int*)malloc(sizeof(int)*m);
    int* temp=(int*)malloc(sizeof(int)*m); //mergesort할때 임시저장용(함수안에서 만들기 애매하니까 그냥 인자로 보냄)
    for(int i=0;i<m;i++)
        scanf("%d",&M[i]); //마트에서 팔고있는 물건들

    scanf("%d",&n); // 구입하려는 물건 개수
    int* N=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&N[i]); //구입하고자하는 물건들

    int total=0;
    merge_sort(M,0,m-1,temp); //sort해야함!!
    for(int i=0;i<n;i++){
        if(s_b(M,0,m-1,N[i])==1) //찾는값(N[i])이 있다면 1을 return받음, 1이면 tot+=1;
			total+=1;
       // printf("%d ",total);
    }
    printf("%d",total);

    free(M);
    free(N);
}