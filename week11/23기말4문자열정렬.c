#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void merge(char *A, int p, int q, int r) {
    char temp[500000];
	int i,j,t;

	i = p;
	j = q+1;
	t = p;

	while(1) {
		if(i>q || j>r)
			break;
		
		if(A[i] < A[j]) { //ascii�� ��
			temp[t] = A[i]; 
			i++;
		}
		else {
			temp[t] = A[j];
			j++;
		}
		t++;
	}

	if(i>q) { //���� subarray�� ó���� ��.
		//������ subarray �ܿ� �������� ����
		for( ; j<=r ; j++, t++)
			temp[t] = A[j];
	}
	else {
		for( ; i<=q ; i++, t++)
			temp[t] = A[i];
	}

	for(i=p; i<=r; i++)
		A[i] = temp[i];
}

void merge_sort(char *A, int p, int r) { //char
	if(p<r) {
		int q = (p+r)/2;
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A, p, q, r);
        
	}
}

int main(){
    int a=0,n=0,m=0;
    char s[500000];
    scanf("%s",s); //���ڿ� ����
    int len=strlen(s);

    char*A=(char*)malloc(len);
    char*N=(char*)malloc(len);
    char*M=(char*)malloc(len); //malloc o shinkya nran
    
    for(int i=0;i<strlen(s);i++){
        if(s[i]-64<0) N[n++]=s[i]; //����
        else if(s[i]-64>0 && s[i]-96<0) A[a++]=s[i]; //�빮��(65~90������ ��.)
        else M[m++]=s[i]; //�ҹ��� (97~122)
    }
    A[a]='\0'; //���̶�°� �˼��ְ�!! ���־��ֱ�
    N[n]='\0';
    M[m]='\0';
    //printf("%s %s %s",A,N,M);
    merge_sort(A,0,a-1); //�����ؼ�
    merge_sort(N,0,n-1);
    merge_sort(M,0,m-1);

    printf("%s%s%s",A,M,N); //�������

    free(A); free(N); free(M);
    
}