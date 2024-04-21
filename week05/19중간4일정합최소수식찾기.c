#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int n, char* plama,int* bucket, int bucketSize, int k,int target,int* count) { //�ߺ� ����
    int i, lastIndex,  item;
    int total = 0;

    if(k<0)return;
   
    for (i = 0; i < bucketSize-k; i++) {
            if (plama[bucket[i]] == '-') total -= (i + 1);
            else total += (i + 1);   
    }//�ϴ� �����ؼ� ���� �� ������ ���
    if(target==total){
        (*count)++;} 

    if(k==0) return; //���� �ٽ���ǰ� k�� 0�̸� return

    lastIndex = bucketSize - k - 1; // ���� �ֱٿ� ���� ���� ����� ��ġ index
    for (item = 0; item < n; item++) {
        bucket[lastIndex + 1] = item; //+,-�ε��� ���Ͽ� ����
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
