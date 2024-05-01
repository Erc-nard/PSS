#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, k;
	int m;
	int now = 0;
	int count = 0;
	scanf("%d %d %d", &n, &k,&m);
	int all[1000];
	int j = 0;
	while (m != 0) {
		all[j++] = m % 10;
		m /= 10;
	}

	now += k;
	int c;
	
	int cc[10000];
	int cnow = 0;
	

	while (now < n) {
		int countnow[10000];
		c = now;
		count = 0;
		while (c != 0) {
			countnow[count++]=c%10;
			c = c / 10;
			if (c == 0) break;
		}
		for (int i = 0; i < count; i++) {
			cc[cnow] = countnow[count - i-1];
			cnow++;
		}
		now += k;
	}
	int flag = 0;
	for (int i = 0; i < cnow; i++) {
		if (cc[i] == all[0]) {
			//printf("%d %d\n",cc[i],cc[i+1]);
			for (int k = 0; k < j; k++) {
				//printf("%d %d\n", cc[i + k], all[k]);
				if (cc[i + k] != all[k]) break;
				
				if (k + 1 == j) { flag = i+1; printf("%d", flag);};
			}
		}
		if (flag != 0) break;
	}
	if (flag == 0) printf("-1");


}
