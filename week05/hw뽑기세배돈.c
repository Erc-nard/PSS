#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int n, int* plama,int* bucket, int bucketSize, int k) { //�ߺ� ����
    int i, lastIndex, item;
    if (k == 0) { //������ �´ٸ� ���
        for (i = 0; i < bucketSize; i++) {
            printf( "%d ", plama[bucket[i]] );
        }
        printf("\n");
    }
    lastIndex = bucketSize;
    for (i = 0; i < n; i++) {
        if ((k - plama[i]) >= 0) { //k���� ���� ���������� 0�̻��϶��� ����
            if (bucketSize > 0)
                if( plama[i] > plama[bucket[bucketSize-1]]) continue;
            bucket[bucketSize] = i;

            pick(n, plama, bucket, bucketSize + 1, k - plama[i]);
            //���ϴ°����� ��������ŭ �� 
        }
        
    }

}
int main() {
	int n;
	scanf("%d", &n);
    int a[] = { 1000, 5000, 10000 };
    int m = n / 1000;
    int* bucket = (int*)malloc(sizeof(int)*m); //*m���ֱ�
    pick(3, a,bucket,0, n);
    
    free(bucket); //malloc free
    return 0;
}
