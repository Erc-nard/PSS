#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int n, char* plama,int* bucket, int bucketSize, int k,int* count,int*all) { //�ߺ� ����
    int i, lastIndex, smallest, item;
    int total = 0;
    if (k == 0) {
        for (i = 0; i < bucketSize; i++) {
            //printf(" %c", plama[bucket[i]]);
            //printf(" %d", all[i]);
            if (plama[bucket[i]] == '-') total -= (all[i]);
            else if(plama[bucket[i]]=='+') total += (all[i] );
            //^�� �տ� ������ 0���� �����ϰ� ó��
        }
        //printf(" =%d\n", total);
        if(total==0)(*count)+=1;
        return;
    }
    lastIndex = bucketSize - k - 1; // ���� �ֱٿ� ���� ���� ����� ��ġ index
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
    char a[] = { '+','-','^' }; //^�� �տ� ������ 0ó��
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
