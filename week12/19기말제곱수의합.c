#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n,int*bucket,int bucketSize,int toPick,int tot,int*min) {
	int now=n;

	if (tot == 0) {
		if (*min > bucketSize - toPick) *min = bucketSize - toPick;
	}
	if (tot < 0) return 0;

	for (int i = 0; i < n; i++) {
		if (tot - ((n-i) * (n-i)) >= 0) {
			bucket[bucketSize - toPick] = (n - i);
			tot -= ((n - i) * (n - i));
			for (int i = 0; i < tot; i++) {
				if ((tot - i) * (tot - i) < tot) {
					now = i;
					break;
				}
			}
			pick(now, bucket, bucketSize, toPick - 1, tot, min);
		}
	}
}


int main(void)
{
	int n;
	int min = 100000;
	scanf("%d", &n);
	int* bucket = (int*)malloc(sizeof(int) * n);
	if (n > 100) {
		int now;
		for (int i = 0; i <= 100; i++) {
			if (((100 - i) * (100 - i)) <= n) {
				now = 100 - i;
				break;
			}
		}
		printf("%d", now);
		pick(now, bucket, n, n, n,&min);
	}
	else {
		pick(n, bucket, n, n, n,&min);
	}
	printf("%d", min);
	free(bucket);
}
   
