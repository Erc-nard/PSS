#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long Hn(long long* H, int n) {
	if (n == 1) return 1;

	long long total = 0;

	for (int i = 1; i < n; i++) {
		if (H[i] == -1) {
			H[i] = Hn(H, i);
		}
		total += (H[i] * (n-i));
	}
	return total;
}


int main(void)
{
	int n;
	scanf("%d", &n);
	long long* H = (long long*)malloc(sizeof(long long) * n);
	for (int i = 0; i < n; i++)
		H[i] = -1;
	printf("%lld",Hn(H, n));

	free(H);
}
   
