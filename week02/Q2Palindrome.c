#include <stdio.h>
int calculateReverse(int n) {
    int pn = 0;
    while (n != 0) {
        pn=pn*10+n%10; //n을 1의자리부터 쭉 넣고 매번 10을곱해서 자리수증가시킴
        n=n/10;
    }
    return pn; //거꾸로된 숫자 리턴
}
int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    while (calculateReverse(calculateReverse(n) + n) != (calculateReverse(n) + n)) {
        //어떤 숫자 n와 n을 뒤집은 n’을 합하는 것을 반복하여 팰린드롬찾기
        if (calculateReverse(calculateReverse(n) + n) <= 0) {
            //팰린드롬 만들던중 음수되면 overflow출력
            count = -1;
            printf("Overflow");
            break;
        }
        n=calculateReverse(n) + n;
        count++; //몇번 뒤집었는지 카운트
    }
    if (count != -1)
        printf("%d %d", count, calculateReverse(n) + n);
}
