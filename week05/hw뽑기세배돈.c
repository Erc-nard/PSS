#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int n, int* plama,int* bucket, int bucketSize, int k) { //중복 조합
    int i, lastIndex, item;
    if (k == 0) { //가격이 맞다면 출력
        for (i = 0; i < bucketSize; i++) {
            printf( "%d ", plama[bucket[i]] );
        }
        printf("\n");
    }
    lastIndex = bucketSize;
    for (i = 0; i < n; i++) {
        if ((k - plama[i]) >= 0) { //k에서 가장 작은값빼도 0이상일때만 실행
            if (bucketSize > 0)
                if( plama[i] > plama[bucket[bucketSize-1]]) continue;
            bucket[bucketSize] = i;

            pick(n, plama, bucket, bucketSize + 1, k - plama[i]);
            //원하는값에서 뽑은값만큼 뺌 
        }
        
    }

}
int main() {
	int n;
	scanf("%d", &n);
    int a[] = { 1000, 5000, 10000 };
    int m = n / 1000;
    int* bucket = (int*)malloc(sizeof(int)*m); //*m해주기
    pick(3, a,bucket,0, n);
    
    free(bucket); //malloc free
    return 0;
}
