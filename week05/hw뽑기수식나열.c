#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int n, char* plama,int* bucket, int bucketSize, int k) { //중복 조합
    int i, lastIndex, smallest, item;
    int total = 0;
    if (k == 0) {
        for (i = 0; i < bucketSize; i++) {
            printf(" %c", plama[bucket[i]]);
            printf(" %d", i+1);
            if (plama[bucket[i]] == '-') total -= (i + 1);
            else total += (i + 1);
        }
        printf(" = %d", total);

        printf("\n");
        return;
    }
    lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index
    smallest = 0;
    for (item = smallest; item < n; item++) {
        bucket[lastIndex + 1] = item;
        pick(n, plama,bucket, bucketSize, k-1);
    }

}
int main() {
	int n;
	scanf("%d", &n);
    char a[] = { '+','-' };
    int* bucket = (int*)malloc(sizeof(int));
    pick(2, a,bucket,n, n);
}
