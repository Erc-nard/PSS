#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

int screen[HEIGHT][WIDTH] = {
0,0,0,-1,-1,-1,-1,-1,-1,-1,
-1,-1, 0, -1,-1,-1,-1, -1,-1,-1,
-1,0,0, 0, 0, 0, 0, -1,-1,-1,
-1,-1,-1, -1,0,-1,0,-1,-1,-1,
-1,-1,-1, -1, 0, -1, 0, -1,-1,-1,
-1,-1,0, 0,0, -1,0,0,0,-1,
-1,-1,-1, -1,0, -1,0,-1,-1,-1,
-1,-1,-1, -1,0, -1, 0, -1,0,-1,
-1,-1,-1,-1,0,-1,-1,-1,0,-1,
-1,-1,-1,-1,0,0,0,0,0,0
};
int count =1;

void display(int s[][WIDTH]);

void flood_fill(int x, int y) {
	if(screen[x][y] == 0) {
		screen[x][y] = count++;
        if(y+1<WIDTH) //�Ʒ��� ���鼭 ��ä�� 0�ƴϸ� ����
		flood_fill(x, y+1);
        if(x+1<WIDTH) //�����ʰ��鼭 �� ä�� 0�ƴϸ� ����
		    flood_fill(x+1, y);
        if(y-1>0) //���� ���鼭 ��ä�� 0�ƴϸ� ����
		flood_fill(x, y-1);
        if(x-1>0) //���ʰ��鼭 �� ä�� 0�ƴϸ� ����
            flood_fill(x-1, y);
        
        
	}
}

int main(void) {
    printf("�̷�:\n");
    display(screen);
    printf("�������� <0 0>���� �� �̷ι湮(����ǥ��):\n");
	flood_fill(0,0);
	display(screen);
}

void display(int s[][WIDTH]) {
	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++)
			printf("%3d", s[i][j]);
		printf("\n");
	}
}