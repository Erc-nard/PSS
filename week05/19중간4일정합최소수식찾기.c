#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int n, char* plama,int* bucket, int bucketSize, int k,int target,int* count) { //중복 조합
    int i, lastIndex,  item;
    int total = 0;

    if(k<0)return;
   
    for (i = 0; i < bucketSize-k; i++) {
            if (plama[bucket[i]] == '-') total -= (i + 1);
            else total += (i + 1);   
    }//일단 실행해서 최종 합 얼마인지 계산
    if(target==total){
        (*count)++;} 

    if(k==0) return; //위에 다실행되고 k가 0이면 return

    lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index
    for (item = 0; item < n; item++) {
        bucket[lastIndex + 1] = item; //+,-인덱스 버켓에 저장
        pick(n, plama,bucket, bucketSize, k-1,target,count);
    }

}
int main() {
	int n;
    int count=0;
	scanf("%d", &n);
    char a[] = { '+','-' };
    int* bucket = (int*)malloc(sizeof(int)*n);
    pick(2, a,bucket,n, n,n,&count);
    printf("%d",count);

    free(bucket);

}
