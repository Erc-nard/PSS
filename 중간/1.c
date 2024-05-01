#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	int a[10000];
	int max = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i == 0)max = a[i];
		if (a[i] > max) max = a[i];
		printf("%d ", max);
	}
}
