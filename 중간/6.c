#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pick(int item[], int n, int bucket[], int m, int toPick,int total,int *count) {
	int i, lastIndex, smallest;

	if (toPick == 0) {
		int tot = 0;
		for (i = 0; i < m; i++)
			tot += item[bucket[i]];
		if (tot == total)(*count)++;
	}

	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(item, n, bucket, m, toPick - 1,total,count);
	}
}



int main(void) {
	int n, m;
	int a[10000];
    int bucket[10000];
	scanf("%d", &n);
	scanf("%d", &m);
    int count = 0;
	for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
	}

    pick(a, n, bucket, m, m, 0, &count);
    printf("%d", count);
}
