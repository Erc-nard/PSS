#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, k;
	int now = 0;
	int count = 0;
	scanf("%d %d", &n, &k);
	now += k;
	int c ;
	while (now <= n) {
		c = now;
		while (c != 0) {
			count++;
			c = c/10;
			if (c == 0) break;
		}
		now += k;
	}
	printf("%d", count);
	
}
