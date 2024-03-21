#include <stdio.h>
int calculateReverse(int n) {
    int pn = 0;
    while (n != 0) {
        pn = pn * 10 + n % 10;
        n = n / 10;
    }
    return pn;
}
int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    while (calculateReverse(calculateReverse(n) + n) != (calculateReverse(n) + n)) {
        if (calculateReverse(calculateReverse(n) + n) <= 0) {
            count = -1;
            printf("Overflow");
            break;
        }
        n=calculateReverse(n) + n;
        count++;
    }
    if (count != -1)
        printf("%d %d", count, calculateReverse(n) + n);
}
