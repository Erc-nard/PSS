#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int n, char* plama,int* bucket, int bucketSize, int k,int* count,int*all) { //중복 조합
    int i, lastIndex, smallest, item;
    int total = 0;
    if (k == 0) {
        for (i = 0; i < bucketSize; i++) {
            //printf(" %c", plama[bucket[i]]);
            //printf(" %d", all[i]);
            if (plama[bucket[i]] == '-') total -= (all[i]);
            else if(plama[bucket[i]]=='+') total += (all[i] );
            //^이 앞에 붙은건 0으로 간주하고 처리
        }
        //printf(" =%d\n", total);
        if(total==0)(*count)+=1;
        return;
    }
    lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index
    smallest = 0;
    for (item = smallest; item < n; item++) {
        bucket[lastIndex + 1] = item;
        pick(n, plama,bucket, bucketSize, k-1,count,all);
    }
}
int main() {
	int n;
    int count=0;
	scanf("%d", &n);
    char a[] = { '+','-','^' }; //^이 앞에 붙으면 0처리
    int* bucket = (int*)malloc(sizeof(int)*n);
    int* item = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&item[i]);
    }
    pick(3, a,bucket,n, n,&count,item);
    printf("%d",count);

    free(bucket);
    free(item);

}
