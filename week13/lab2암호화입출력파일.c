#include <stdio.h>
#include <stdlib.h>

void makeCode(char code[], int dist){
	int i = 0;
	for(i=0; i<26; i++){
		code[i] = 'A' + (char)(i+dist);
		if(code[i] > 'Z')
			code[i] = code[i] - 26;
	}
}

void printCode(char code[]){
	int i = 0;
	for(i=0; i<26; i++)
		printf("%c", 'A' + (char)i);
	printf("\n");
	for(i=0; i<26; i++)
		printf("%c", code[i]);
	printf("\n");
}

void encode(char code[], char s[], char e[]){
	int i;

	for(i=0; s[i]!='\0'; i++){
		if(s[i] >= 'A' && s[i] <= 'Z') {
			int idx = s[i] - 'A';
			e[i] = code[idx];
		}
		else
			e[i] = s[i];
	}
}

int main(void)
{
	char code[26]; // code[0]���� ��A���� ��ȣȭ���ڸ� ����
	int distance;
	char sentence[80] = {0};
	char encodedSentence[80] = {0};
    FILE *fp1,*fp2;

	printf("Enter a distance for encoding:");
	scanf("%d", &distance);

	makeCode(code, distance);
	printCode(code);

    if ((fp1 = fopen("C:\\Users\\�Ž�1\\Desktop\\original.txt", "rt")) == NULL) {
        printf("���� ���� ����1"); exit(1);
    }
    if ((fp2 = fopen("C:\\Users\\�Ž�1\\Desktop\\encoded.txt", "wt")) == NULL) {
        printf("���� ���� ����2"); exit(1);
    }
    while (fgets(sentence, sizeof(sentence), fp1) != NULL) {
        encode(code, sentence, encodedSentence);
        fputs(encodedSentence, fp2);
    }
    fclose(fp1);fclose(fp2);
}