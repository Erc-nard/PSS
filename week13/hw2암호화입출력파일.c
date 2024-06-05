#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_duplicated_char(char* word)
{
    int alpah[26] = { 0 };
    char ch[30];
    int l = 0;

    for (int i = 0; i < strlen(word); i++) {
        int now = word[i] - 'A';
        if (alpah[now] == 0) {
            ch[l++] = word[i];
            alpah[now] += 1;
        }
    }
    ch[l] = '\0';
    strcpy(word, ch);
}

void makeCode(char code[], int dist, char* key) {
    int alpeh[26] = { 0 };

    for (int i = 0; i < strlen(key); i++) {
        int n = key[i] - 'A';
        alpeh[n] = 1;
    }
    for (int i = 0; i < 26; i++)
        code[i] = '+';

    for (int i = 0; key[i] != '\0'; i++) {
        code[i + dist] = key[i];
    }

    int now = 0;
    for (int i = 0; i < 26; i++) {
        int flag = 0;
        if (code[(i + dist + strlen(key)) % 26] != '+')continue;
        while (alpeh[now] == 1)now++;
        code[(i + dist + strlen(key)) % 26] = (char)(now)+'A';
        if (code[(i + dist + strlen(key)) % 26] > 'Z')
            code[(i + dist + strlen(key)) % 26] -= 26;
        now++;
    }
    code[26] = '\0';

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
    char code[27]; // code[0]부터 ‘A’의 암호화문자를 넣음
    char key[30];
    int distance;
    char sentence[80] = { 0 };

    char intput[30];
    char ouput[30];
    FILE* fp1, * fp2;

    printf("Enter a key to use for encodings(대문자로 된 단어입력):");
    scanf("%s", key);
    remove_duplicated_char(key);

    printf("Enter a distance for encoding:");
    scanf("%d", &distance);

    makeCode(code, distance, key);
    printCode(code);

    getchar();

    printf("입력파일:");
    fgets(intput, 30, stdin);
    intput[strlen(intput) - 1] = '\0';
    printf("출력파일:");
    fgets(ouput, 30, stdin);
    ouput[strlen(ouput) - 1] = '\0';

    if ((fp1 = fopen(intput, "r")) == NULL) {
        printf("파일 오픈 에러1"); exit(1);
    }
    if ((fp2 = fopen(ouput, "w")) == NULL) {
        printf("파일 오픈 에러2"); exit(1);
    }
    while (fgets(sentence, sizeof(sentence), fp1) != NULL) {
        char encodedSentence[80] = { 0 };
        encode(code, sentence, encodedSentence);
        fputs(encodedSentence, fp2);
    }
    fclose(fp1); fclose(fp2);
}