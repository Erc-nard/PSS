#include <stdio.h>
int calculateReverse(int n) {
    int pn = 0;
    while (n != 0) {
        pn=pn*10+n%10; //n�� 1���ڸ����� �� �ְ� �Ź� 10�����ؼ� �ڸ���������Ŵ
        n=n/10;
    }
    return pn; //�Ųٷε� ���� ����
}
int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    while (calculateReverse(calculateReverse(n) + n) != (calculateReverse(n) + n)) {
        //� ���� n�� n�� ������ n���� ���ϴ� ���� �ݺ��Ͽ� �Ӹ����ã��
        if (calculateReverse(calculateReverse(n) + n) <= 0) {
            //�Ӹ���� ������� �����Ǹ� overflow���
            count = -1;
            printf("Overflow");
            break;
        }
        n=calculateReverse(n) + n;
        count++; //��� ���������� ī��Ʈ
    }
    if (count != -1)
        printf("%d %d", count, calculateReverse(n) + n);
}
