#include <stdio.h>
#define min(a,b) (a>b)?b:a
#define s(a) scanf("%d", &a)

int board[8][8];
int dx[8] = {-2, -2, -1, -1,  1, 1,  2, 2};
int dy[8] = {-1,  1, -2, +2, -2, 2, -1, 1};

int inRange(int x, int y){
	if(x>=0 && x<=7 && y>=0 && y<=7) return 1;
	return 0;
}

void moveFrom(int x, int y, int step){
	int i,tempx,tempy;
	printf("%d %d--->\n", x, y);
	int tempboard[8][8];
	memset(tempboard, 0, sizeof(tempboard));
	for(i=0; i<8; i++){
		tempx = x+dx[i];
		tempy = y+dy[i];
		if(!inRange(tempx, tempy)) continue;
		if(board[tempx][tempy] == -1){
			printf("%d %d\n", tempx, tempy);
			board[tempx][tempy] = step;
			tempboard[tempx][tempy] = -1;
		}
	}
	printBoard();
	for(i=0; i<8; i++){
		tempx = x+dx[i];
		tempy = y+dy[i];
		if(!inRange(tempx, tempy)) continue;
		if(tempboard[tempx][tempy] == -1){
			moveFrom(tempx, tempy, step+1);
		}
	}
}

void printBoard(){
	int i, j;
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			printf("%d ", board[i][j]);
		}printf("\n");
	}
}

int main(){
	int x1, y1, x2, y2;
	s(x1), s(y1), s(x2), s(y2);
	x1--, y1--, x2--, y2--;
	memset(board, -1, sizeof(board));
	board[x1][y1]=0;
	moveFrom(x1,y1,1);
	//printf("No of steps : %d\n", board[x2][y2]);
	printBoard();
}