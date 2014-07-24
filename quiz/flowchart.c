#include <stdio.h>
struct node{
	struct node *next;
	int figCount;
};
struct diagram{
	int height, width;
	char **pixels;
	int **overlapCount;
	char backgroundColor;
	struct node ***data, nod;
}d;
struct logFigs{
	int type, x, y, width, height, borderColor, fillColor, length;
	int isOverlapping;
	int overlapping[100];
}logFig[100];
int figCount = 0, RECT=1, KITE=2;

void allocatePixels(){
	int i,j;
	d.backgroundColor = '.';
	d.pixels = malloc(d.height*(sizeof(char*)));
	d.overlapCount = malloc(d.height*sizeof(int*));
	d.data = malloc(d.height*sizeof(struct node));
	for(i=0; i<d.height; i++){
		d.pixels[i] = malloc(d.width*sizeof(char));
		d.overlapCount[i] = malloc(d.width*sizeof(int));
		d.data[i] = malloc(d.width*sizeof(struct node));
	}
	for (i=0; i<d.height; i++)
		for(j=0; j<d.width; j++)
			d.pixels[i][j] = d.backgroundColor, d.overlapCount[i][j]=0, d.data[i][j] = malloc(sizeof(struct node));
}

void addlogFig(int type, int x, int y, int width, int height, int length, char borderColor, char fillColor){
	logFig[figCount].type = type;
	logFig[figCount].x = x;
	logFig[figCount].y = y;
	logFig[figCount].width = width;
	logFig[figCount].height = height;
	logFig[figCount].length = length;
	logFig[figCount].borderColor = borderColor;
	logFig[figCount].fillColor = fillColor;
	figCount ++;
}

void checkAndAddOverlapData(int x, int y){
	int present = 0;
	struct node *tempNode = d.data[x][y];
	while(tempNode->next != NULL){
		if(tempNode->figCount == figCount){
			present = 1;
			break;
		}
		tempNode = tempNode->next;
	}
	
	if(!present){
		tempNode = d.data[x][y];
		while(tempNode != NULL && tempNode->next != NULL){
			printf("%d\n", tempNode->figCount);
			tempNode = tempNode->next;
		}
		tempNode->next = malloc(sizeof(struct node));
		tempNode->figCount = figCount;
		d.overlapCount[x][y] ++;
	}
}

void setPixels(int x, int y, char color){
	d.pixels[y-1][x-1] = color;
	if(color != d.backgroundColor)
		checkAndAddOverlapData(y-1,x-1);
}

int checkRange(int i, int j){
	if(i>=1 && i<=d.width && j>=1 && j<=d.height) return 1;
	return 0;
}

void drawRectangle(int x, int y, int width, int height, char borderColor, char fillColor){
	int i,j;
	char bg = d.backgroundColor;
	for(i=x; i<width+x; i++){
		for(j=y; j<height+y; j++){
			if(!checkRange(i,j)) continue;
			//if(i==x || j==y || i==x+width-1 || j==y+height-1) setPixels(i,j,borderColor);
			if((i==x && j==y)||(i==x+width-1&&j==y+height-1)) setPixels(i,j,(borderColor!=bg)?'+':bg);
			else if((i==x && j==y+height-1) || (j==y && i==x+width-1)) setPixels(i,j,(borderColor!=bg)?'+':bg);
			else if(i==x || i==x+width-1) setPixels(i,j,(borderColor!=bg)?'|':bg);
			else if(j==y || j==y+height-1) setPixels(i,j,(borderColor!=bg)?'-':bg);
			else setPixels(i,j,fillColor);
		}
	}
	if(borderColor != bg)
		addlogFig(RECT, x, y, width, height, 0, borderColor, fillColor);
}

// do it with 2 loops
void drawKite(int x, int y, int length, char borderColor, char fillColor){
	int i, j, tempy;
	char bg = d.backgroundColor;
	int len = 0, indc = 1, rangeStart, rangeEnd;
	tempy = y-length;
	rangeStart = rangeEnd = x;
	do{
		for(i=rangeStart; i<=rangeEnd; i++){
			if(!checkRange(i,tempy)) continue;
			if(i==rangeStart && i==rangeEnd) setPixels(i, tempy, (borderColor!=bg)?'x':bg);
			else if((i==rangeStart && indc==1) || (i==rangeEnd && indc==-1)) setPixels(i,tempy, (borderColor!=bg)?'/':bg);
			else if((i==rangeEnd && indc==1) || (i==rangeStart && indc==-1)) setPixels(i, tempy, (borderColor!=bg)?'\\':bg);
			else setPixels(i,tempy,fillColor);
		}
		if(rangeEnd-rangeStart >= 2*length) indc *= -1;
		tempy ++;
		rangeStart -= indc; rangeEnd += indc;
	}while(rangeStart != rangeEnd);
	if(checkRange(i,tempy))
		setPixels(rangeStart, tempy, (borderColor!=bg)?'x':bg);
	if(borderColor != bg)
		addlogFig(KITE, x, y, 0, 0, length, borderColor, fillColor);
}

void printBoard(){
	int i, j;
	for(i=0; i<d.height; i++){
		for(j=0; j<d.width; j++){
			printf("%c", d.pixels[i][j]);
		}
		printf("\n");
	}printf("\n");
}

void printlogFig(){
	int i;
	for(i=0; i<figCount; i++){
		if(logFig[i].type == RECT){
			printf("RECTANGLE : x-%d y-%d width-%d height-%d borderColor-%c fillColor-%c\n", logFig[i].x, logFig[i].y, logFig[i].width, logFig[i].height, logFig[i].borderColor, logFig[i].fillColor);
		}else{
			printf("KITE : x-%d y-%d length-%d borderColor-%c fillColor-%c\n", logFig[i].x, logFig[i].y, logFig[i].length, logFig[i].borderColor, logFig[i].fillColor);
		}
	}
}

void printData(){
	int i, j;
	for(i=0; i<d.height; i++){
		for(j=0; j<d.width; j++)
			printf("%d", d.overlapCount[i][j]);
		printf("\n");
	}
}

void removeFigure(int figIndCount){
	if(logFig[figIndCount].type==RECT){
		drawRectangle(logFig[figIndCount].x, logFig[figIndCount].y, logFig[figIndCount].width, logFig[figIndCount].height, d.backgroundColor, d.backgroundColor );
	}else{
		drawKite(logFig[figIndCount].x, logFig[figIndCount].y, logFig[figIndCount].length, d.backgroundColor, d.backgroundColor);
	}
}

void removeAllFiguresFromAPoint(int x, int y){
	int temp = x; x = y-1; y = temp-1;
	if(checkRange(x,y) && d.overlapCount[x][y] > 0){
		struct node* tempNode = d.data[x][y];
		while(tempNode != NULL){
			removeFigure(tempNode->figCount);
			printf("%d\n", tempNode->figCount);
			tempNode = tempNode->next;
		}
	}
}

int main(){
	d.height = 40, d.width = 40;
	//scanf("%d %d", &d.height, &d.width);
	allocatePixels();
	drawRectangle(2,3,10,5,'B','G');
	drawKite(7,7,3,'B','P');
	drawRectangle(35,25,10,10,'B','R');
	drawKite(15,15,5,'B','Y');
	drawKite(30,30,4,'B','G');
	drawRectangle(7,4,2,2,'B','U');
	printBoard();
	printlogFig();
	printData();
	removeAllFiguresFromAPoint(7,4);
	printBoard();
}