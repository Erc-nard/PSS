#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(int n,int*bucket,int bucketSize,int toPick,int tot,int*min,int *m) {
	int now=n;
	int all=tot;

	if (tot == 0) { //다 뺐을때 비교
		if (*min > bucketSize - toPick) 
			*min = bucketSize - toPick;
		return 0;
	}
	if (tot < 0) return 0;


	for (int i = 0; i < n; i++) {

		all=tot;
		if (all - ((n-i) * (n-i)) >= 0) { //최대 제곱수
			bucket[bucketSize - toPick] = (n - i);
			all -= ((n - i) * (n - i));
			for (int i = 0; i < all; i++) {
				if ((all - i) * (all - i) < all) {
					now = i;
					break;
				}
			}
			if(m[now]==-1)
				m[now]=pick(now, bucket, bucketSize, toPick - 1, all, min,m); //메모에 없으면 구하기
			else return m[now]; //지금수일때 최소항개수 return
		}
	}
}


int main(void)
{
	int n;
	int min = 100000;
	scanf("%d", &n);
	int* bucket = (int*)malloc(sizeof(int) * n);
	int* m = (int*)malloc(sizeof(int) * n);
	for(int i=0;i<n;i++)
		m[i]=-1; //메모용

	if (n > 100) { //100보다 크면 최대제곱수 먼저 구함
		int now;
		for (int i = 0; i <= 100; i++) {
			if (((100 - i) * (100 - i)) <= n) {
				now = 100 - i; //최대제곱수
				break;
			}
		}
		pick(now, bucket, n, n, n,&min,m);
	}
	else {
		pick(n, bucket, n, n, n,&min,m);
	}
	printf("%d", min);
	free(bucket);
}

