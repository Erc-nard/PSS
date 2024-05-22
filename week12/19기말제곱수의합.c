#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(int n,int*bucket,int bucketSize,int toPick,int tot,int*min,int *m) {
	int now=n;
	int all=tot;

	if (tot == 0) {
		if (*min > bucketSize - toPick) 
			*min = bucketSize - toPick;
		return 0;
	}
	if (tot < 0) return 0;


	for (int i = 0; i < n; i++) {

		all=tot;
		if (all - ((n-i) * (n-i)) >= 0) { //최대 제곱수
				//printf("n:%d tot=%d\n",n-i,tot);
			bucket[bucketSize - toPick] = (n - i);
			all -= ((n - i) * (n - i));
			for (int i = 0; i < all; i++) {
				if ((all - i) * (all - i) < all) {
					now = i;
					break;
				}
			}
			if(m[now]==-1)
				m[now]=pick(now, bucket, bucketSize, toPick - 1, all, min,m);
			else return m[now];
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
		m[i]=-1;
	if (n > 100) {
		int now;
		for (int i = 0; i <= 100; i++) {
			if (((100 - i) * (100 - i)) <= n) {
				now = 100 - i; //최대제곱수
				break;
			}
		}
		//printf("%d\n", now);
		pick(now, bucket, n, n, n,&min,m);
	}
	else {
		pick(n, bucket, n, n, n,&min,m);
	}
	printf("%d", min);
	free(bucket);
}

