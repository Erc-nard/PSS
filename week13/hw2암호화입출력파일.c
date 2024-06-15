#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_duplicated_char(char* word) //�ߺ����� ����
{
    int alpah[26] = { 0 };
    char ch[30];
    int l = 0;

    for (int i = 0; i < strlen(word); i++) {
        int now = word[i] - 'A';
        if (alpah[now] == 0) { //alpah �迭�� ������ (0)
            ch[l++] = word[i]; //ch�迭�� �߰��ϱ�
            alpah[now] += 1; //alpah �迭 �� +1 �ѹ� �߰��Ǹ� �׵ڷ� ������ ������ �׳� �Ѿ
        }
    }
    ch[l] = '\0'; //���� �� �־��ֱ�
    strcpy(word, ch); //word�� ch �����ؼ� �ֱ�
}

void makeCode(char code[], int dist, char* key) { //�ڵ庯ȯ
    int alpeh[26] = { 0 };

    for (int i = 0; i < strlen(key); i++) {
        int n = key[i] - 'A';
        alpeh[n] = 1; //key�� �̹� �մٴ°� Ȯ�ο����� �����ص�
    }
    for (int i = 0; i < 26; i++)
        code[i] = '+'; //code��ü�� +ä��

    for (int i = 0; key[i] != '\0'; i++) {
        code[i + dist] = key[i]; //key���� dist��ŭ �̵��� �Ÿ��� ���� �������
    }

    int now = 0;
    for (int i = 0; i < 26; i++) {
        int flag = 0;
        if (code[(i + dist + strlen(key)) % 26] != '+')continue; //�̹� ����Ǿ������� �ѱ�
        while (alpeh[now] == 1)now++; //����Ǿ������� �ѱ� now+1 ������Ǿ��մ°� ���ö����� ...
        code[(i + dist + strlen(key)) % 26] = (char)(now)+'A'; //�����������
        if (code[(i + dist + strlen(key)) % 26] > 'Z') //��� �� ���� �ʿ���� %26 �ؼ�..
            code[(i + dist + strlen(key)) % 26] -= 26;
        now++;
    }
    code[26] = '\0'; //�������� �� �ֱ�

}

void printCode(char code[]) {
    int i = 0;
    for (i = 0; i < 26; i++)
        printf("%c", 'A' + (char)i);
    printf("\n");
    for (i = 0; i < 26; i++)
        printf("%c", code[i]);
    printf("\n");
}

void encode(char code[], char s[], char e[]) {
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            int idx = s[i] - 'A';
            e[i] = code[idx];
        }
        else
            e[i] = s[i];
    }
}

int main(void)
{
    char code[27]; // code[0]���� ��A���� ��ȣȭ���ڸ� ����
    char key[30];
    int distance;
    char sentence[80] = { 0 };

    char intput[30];
    char ouput[30];
    FILE* fp1, * fp2;

    printf("Enter a key to use for encodings(�빮�ڷ� �� �ܾ��Է�):");
    scanf("%s", key);
    remove_duplicated_char(key);

    printf("Enter a distance for encoding:");
    scanf("%d", &distance);

    makeCode(code, distance, key);
    printCode(code);

    getchar();

    printf("�Է�����:");
    fgets(intput, 30, stdin);
    intput[strlen(intput) - 1] = '\0';
    printf("�������:");
    fgets(ouput, 30, stdin);
    ouput[strlen(ouput) - 1] = '\0';

    if ((fp1 = fopen(intput, "r")) == NULL) {
        printf("���� ���� ����1"); exit(1);
    }
    if ((fp2 = fopen(ouput, "w")) == NULL) {
        printf("���� ���� ����2"); exit(1);
    }
    while (fgets(sentence, sizeof(sentence), fp1) != NULL) {
        char encodedSentence[80] = { 0 };
        encode(code, sentence, encodedSentence);
        fputs(encodedSentence, fp2);
    }
    fclose(fp1); fclose(fp2);
}