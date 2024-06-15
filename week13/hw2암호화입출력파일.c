#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_duplicated_char(char* word) //중복문자 삭제
{
    int alpah[26] = { 0 };
    char ch[30];
    int l = 0;

    for (int i = 0; i < strlen(word); i++) {
        int now = word[i] - 'A';
        if (alpah[now] == 0) { //alpah 배열에 없으면 (0)
            ch[l++] = word[i]; //ch배열에 추가하기
            alpah[now] += 1; //alpah 배열 수 +1 한번 추가되면 그뒤로 같은거 나오면 그냥 넘어감
        }
    }
    ch[l] = '\0'; //끝에 꼭 넣어주기
    strcpy(word, ch); //word로 ch 복사해서 넣기
}

void makeCode(char code[], int dist, char* key) { //코드변환
    int alpeh[26] = { 0 };

    for (int i = 0; i < strlen(key); i++) {
        int n = key[i] - 'A';
        alpeh[n] = 1; //key들 이미 잇다는거 확인용으로 저장해둠
    }
    for (int i = 0; i < 26; i++)
        code[i] = '+'; //code전체에 +채움ㄴ

    for (int i = 0; key[i] != '\0'; i++) {
        code[i + dist] = key[i]; //key들은 dist만큼 이동한 거리에 먼저 집어넣음
    }

    int now = 0;
    for (int i = 0; i < 26; i++) {
        int flag = 0;
        if (code[(i + dist + strlen(key)) % 26] != '+')continue; //이미 저장되어있으면 넘김
        while (alpeh[now] == 1)now++; //저장되어잇으면 넘김 now+1 안저장되어잇는곳 나올때까지 ...
        code[(i + dist + strlen(key)) % 26] = (char)(now)+'A'; //숫자집어넣음
        if (code[(i + dist + strlen(key)) % 26] > 'Z') //사실 이 줄은 필요없음 %26 해서..
            code[(i + dist + strlen(key)) % 26] -= 26;
        now++;
    }
    code[26] = '\0'; //마지막에 꼭 넣기

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