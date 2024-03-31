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


void display(int s[][WIDTH]);

void flood_fill(int x, int y,int *count) {

	if(screen[x][y] == 0) {
		screen[x][y] = (*count)++;
        if(y+1<WIDTH)
		flood_fill(x, y+1,count);
        if(x+1<WIDTH)
		    flood_fill(x+1, y,count);
        if(y-1>0)
		flood_fill(x, y-1,count);
        if(x-1>0)
            flood_fill(x-1, y,count);
        
	}

}

int main(void) {
    printf("미로:\n");
    display(screen);
    int count=0;
    printf("시작점을 <0 0>으로 한 미로방문(순서표기):\n");
	flood_fill(0,0,&count);
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