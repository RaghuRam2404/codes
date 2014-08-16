#include <stdio.h>

int dc[2] = {-1,0};
int dr[2] = {0,+1};
int dxx[4] = {+1, -1, 0, 0};
int dyy[4] = {0, 0, +1, -1};

int noOfHits;
char hits[100][3];
int **board;
char rays[15][15][2];
int modified[15][15];
int height, width;
char r[10];
char c[10];
int rpos[10], cpos[10];

void setRays(int i, int j, int k, char c){
	//rays[j][i][k]=c;
	rays[i][j][k] = c;
}

char getRays(int i, int j, int k){
	return rays[i][j][k];
	return rays[j][i][k];
}

void setModified(int i, int j, int c){
	modified[i][j] = c;
}

int getModified(int i, int j){
	return modified[i][j];
}

void initialize(){
	int i, j;
	board = malloc(height*(sizeof(char*)));
	for(i=0; i<width; i++)
		board[i] = malloc(width*(sizeof(char)));
	for(i=0; i<height; i++)
		for(j=0; j<width; j++)
			if(j==0 || i==0 || i==height-1 || j==width-1) board[i][j] = '.';
			else board[i][j] = '-';
	for(i=0; i<=width+1; i++)
		for(j=0; j<=height+1; j++)
			setRays(i,j,0,' '), setRays(i,j,1,' '), setModified(i,j,0);
	for(i=1; i<=height; i++){
		setRays(i,0,0,'R');
		setRays(i,0,1,'0'+i);
	}
	for(i=1; i<=width; i++){
		setRays(height-1, i, 0, 'C');
		setRays(height-1, i, 1, '0'+i);
	}

	setRays(0,0,0,'D');
	setRays(0,0,1,'1');
	setRays(0,height-1,0,'D');
	setRays(0,height-1,1,'2');

	memset(r, 'R', sizeof(char)*10);
	memset(c, 'C', sizeof(char)*10);
}

void getInputAtoms(){
	int n, i, j, x, y;
	printf("No of Atoms : ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d %d", &x, &y);
		board[x][y] = 'x';
		//printf("x:%d y:%d asdfas\n", x, y);
	}
}

void getHitOrder(){
	int n, i;
	printf("Enter the no of hits : ");
	scanf("%d", &noOfHits);
	for(i=0; i<noOfHits; i++)
		scanf("%s", hits[i]), hits[i][2]='\0';
}

char get(int x, int y){
	return board[x][y];
}

int inRange(int x, int y){
	if(x>=1 && x<=height-2 && y>=1 && y<=width-2) return 1;
	return 0;
}

void printBoard(){
	int i, j;
	printf("\n");
	for(i=0; i<height; i++){
		for(j=0; j<width; j++){
			if(i==0 && j==0){
				if(getModified(i,j) == 1){
					printf("%c%c ", getRays(i,j,0), getRays(i,j,1));
				}else  printf("   ");
			}else if(i==0 && j==width-1) printf("\n");
			else if(i==height-1 && j==0){
				if(getModified(i,j)) printf("%c%c ", getRays(i,j,0), getRays(i,j,1));
				else printf("   ");
			}else if(i==height-1 && j==width-1){
				if(getModified(i,j)) printf("%c%c \n", getRays(i,j,0), getRays(i,j,1));
				else printf("\n");
			}else if(j==0){
				if(getModified(i,j)) printf("%c%c ", getRays(i,j,0), getRays(i,j,1));
				else printf("   ");
			}else if(j==width-1){
				if(getModified(i,j)) printf("%c%c \n", getRays(i,j,0), getRays(i,j,1));
				else printf(" . \n");
			}else if(i==0){
				if(getModified(i,j)) printf("%c%c ", getRays(i,j,0), getRays(i,j,1));
				else printf(" . ");
			}else if(i==height-1){
				if(getModified(i,j)) printf("%c%c ", getRays(i,j,0), getRays(i,j,1));
				else printf("   ");
			}else{
				printf(" %c ", get(i,j));
			}
		}
	}
	printf("\n");
}

void move(char hit[3]){
	int i,dx,dy,startx=1, starty=1, originx=0, originy=0, found=0,x,y;
	char fill = ' ';
	int move, right=1, left=2, up=4, down=8;
	int upleft = up+left, upright=up+right, downright=down+right, downleft = down+left;

	if(hit[0] == 'R') dx=0, dy=1, startx=hit[1]-'0', originx=hit[1]-'0', originy = 0, move=right;
	else if(hit[0] == 'C') dx = -1, dy=0, starty=hit[1]-'0', originx = height-1, originy = hit[1]-'0', move=up;
	else if(hit[0] == 'D' && hit[1] == '1') dx = 1, dy=1, starty=1, originx=0, originy = 0, move=downright;
	else if(hit[0] == 'D' && hit[1] == '2') dx = -1, dy=1, starty=1, originx=height-1, originy = 0, move=upright;

	if(getModified(originx,originy)) return;

	found = 0;
	//printf("NEW MOVE %s\n", hit);
	// reflection rule
	{
		if(hit[0] == 'R' && ((inRange(originx-1,originy+1) && get(originx-1,originy+1)=='x') || (inRange(originx+1,originy+1) && get(originx+1,originy+1)=='x'))){
			//printf("In reflection 1\n");
			setRays(originx, originy, 0, ' ');
			setRays(originx, originy, 1, 'R');
			setModified(originx,originy,1);
			return;
		}else if(hit[0] == 'C' && ((inRange(originx-1, originy-1)&&get(originx-1,originy-1)=='x') || (inRange(originx-1, originy+1) && get(originx-1,originy+1)=='x'))){
			//printf("In reflection 2\n");
			setRays(originx, originy, 0, ' ');
			setRays(originx, originy, 1, 'R');
			setModified(originx,originy,1);
			return;
		}

	}

	// deflection and other rules
	{
		fill = ' ';
		x = originx, y = originy;
		for(;;){
			//printf("%d %d ", x, y);
			switch(0){
				case 4:
					printf("UP\n");
					break;
				case 2:
					printf("LEFT\n");
					break;
				case 1:
					printf("RIGHT\n");
					break;
				case 8:
					printf("DOWN\n");
					break;
				case 5:
					printf("UPRIGHT\n");
					break;
				case 9:
					printf("DOWNRIGHT\n");
					break;
				case 10:
					printf("DOWNLEFT\n");
					break;
				case 6:
					printf("UPLEFT\n");
					break;
			}

			if(move == right){
				if(get(x,y) == 'x'){
					move = left;
					dx = 0, dy = -1;
					fill = 'H';
				}else if(inRange(x+1, y+1) && get(x+1,y+1)=='x' && inRange(x-1, y+1) && get(x-1,y+1)=='x'){
					move = left;
					dx = 0, dy = -1;
					fill = 'R';
				}else if(inRange(x-1, y+1) && get(x-1,y+1)=='x'){
					move = down;
					dx = 1, dy = 0;
				}else if(inRange(x+1, y+1) && get(x+1,y+1)=='x'){
					move = up;
					dx = -1, dy = 0;
				}
			}else if(move == left){
				if(get(x,y)=='x'){
					fill = 'H';
					move = right;
					dx = 0, dy = -1;
				}else if(inRange(x+1, y-1) && get(x+1,y-1)=='x' && inRange(x-1,y-1) && get(x-1,y-1)=='x'){
					move = right;
					fill = 'R';
					dx = 0, dy = -1;
				}else if(inRange(x-1,y-1) && get(x+1,y-1)=='x'){
					move = down;
					dx = 1, dy=0;
				}else if(inRange(x+1, y-1) && get(x-1,y-1)=='x'){
					move = up;
					dx = -1, dy=0;
				}
			}else if(move == up){
				if(get(x,y)=='x'){
					move = down;
					dx = 1, dy = 0;
					fill = 'H';
				}else if(inRange(x-1, y-1) && get(x-1,y-1)=='x' && inRange(x-1, y+1) && get(x-1,y+1)=='x'){
					move = down;
					dx = 1, dy = 0;
					fill = 'R';
				}else if(inRange(x-1, y-1) && get(x-1,y-1)=='x'){
					move = right;
					dx = 0, dy = 1;
				}else if(inRange(x-1, y+1) && get(x-1,y+1)=='x'){
					move = left;
					dx = 0, dy = -1;
				}
				//printf("MOVE UP\n");
			}else if(move == down){
				if(get(x,y)=='x'){
					move = up;
					dx = -1, dy = 0;
					fill = 'H';
				}else if(inRange(x+1,y-1) && get(x+1,y-1)=='x' && inRange(x+1, y+1) && get(x+1,y+1)=='x'){
					move = up;
					fill = 'R';
					dx = 0-1, dy = 0;
				}else if(inRange(x+1,y-1) && get(x+1,y-1)=='x'){
					move = right;
					dx = 0, dy = 1;
				}else if(inRange(x+1, y+1) && get(x+1,y+1)=='x'){
					move = left;
					dx = 0, dy = 1;
				}
			}else if(move == downleft){
				if(get(x,y) == 'x'){
					move = upright;
					dx=-1, dy=1;
					fill = 'H';
				}else if(inRange(x+1,y+1) && get(x+1,y+1)=='x' && inRange(x-1,y-1) && get(x-1,y-1)=='x'){
					move = upright;
					dx = -1, dy = 1;
					fill = 'R';
				}else if(inRange(x+1,y+1) && get(x+1,y+1)=='x'){	
					move = upleft;
					dx = -1, dy=-1;
				}else if(inRange(x-1,y-1) && get(x-1,y-1)=='x'){
					move = downright;
					dx = 1, dy = 1;
				}else if(inRange(x+1, y) && get(x+1,y)=='x'){
					move = upleft;
					dx = -1, dy = -1;
				}
			}else if(move == downright){
				if(get(x,y)=='x'){
					move = upleft;
					dx = -1, dy = -1;
					fill = 'H';
				}else if(inRange(x-1,y+1) && get(x-1,y+1)=='x' && inRange(x+1,y-1) && get(x+1,y-1) == 'x'){
					move = upleft;
					fill = 'R';
					dx = -1, dy = -1;
				}else if(inRange(x-1,y+1) && get(x-1,y+1)=='x'){
					move = downleft;
					dx = 1, dy = -1;
				}else if(inRange(x+1,y) && get(x+1,y) == 'x'){
					move = upright;
					dx =-1, dy = 1;
				}else if(inRange(x,y+1) && get(x,y+1)=='x'){
					move = downleft;
					dx = 1, dy = -1;
				}
			}else if(move == upleft){
				if(get(x,y)=='x'){
					move = downright;
					dx = 1, dy = 1;
					fill = 'H';
				}else if(inRange(x-1, y+1) && get(x-1,y+1)=='x' && inRange(x+1, y-1) && get(x+1,y-1)=='x'){
					move = downright;
					dx = 1, dy = 1;
					fill = 'R';
				}else if(inRange(x-1, y+1) && get(x-1,y+1)=='x'){
					move = downleft;
					dx = 1, dy = -1;
				}else if(inRange(x+1, y-1) && get(x+1,y-1)=='x'){
					move = upright;
					dx = -1, dy = 1;
				}else if(inRange(x-1,y-1) && get(x-1,y-1)=='x'){
					move = downleft;
					dx = 1, dy = -1;
				}
			}else if(move == upright){
				if(get(x,y) == 'x'){
					move = downleft;
					dx = 1, dy = -1;
					fill = 'H';
				}else if(inRange(x-1,y-1) && get(x-1,y-1)=='x' && inRange(x+1, y+1) && get(x+1,y+1)=='x'){
					move = downleft;
					dx = 1, dy = -1;
					fill = 'R';
				}else if(inRange(x-1,y-1) && get(x-1,y-1)=='x'){
					move = downright;
					dx = 1, dy = 1;
				}else if(inRange(x+1, y+1) && get(x+1,y+1)=='x'){
					move = upleft;
					dx = -1, dy = -1;
				}else if(inRange(x-1,y-1) && get(x-1,y+1)=='x'){
					move = downright;
					dx = 1, dy = 1;
				}	
			}
			
			x+=dx, y+=dy;
			if(!inRange(x,y)){
				break;
			}
		}
		setModified(x,y,1);
		//printf("PRINTING IN %d %d\n", x, y);
		setRays(x,y,0,(fill=='H' || fill=='R')?' ':hit[0]);
		setRays(x,y,1,(fill=='H' || fill=='R')?fill:hit[1]);
		if(fill!='H' && fill!='R'){
			//printf("PRINTING IN %d %d\n", originx, originy);
			setRays(originx, originy, 0, hit[0]);
			setRays(originx, originy, 1, hit[1]);
			setModified(originx, originy, 1);
		}
		//printBoard();
	}

}

void detectChanges(){
	int i, j;
	for(i=0; i<noOfHits; i++){
		move(hits[i]);
	}
}

int main(){
	freopen("rays.in", "r", stdin);
	printf("Enter the height of the board : ");
	scanf("%d", &height);
	height+=2;
	printf("Enter the width of the board : ");
	scanf("%d", &width);
	width += 2;
	initialize();
	getInputAtoms();
	getHitOrder();
	detectChanges();
	printBoard();
}