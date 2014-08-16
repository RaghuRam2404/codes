#include <stdio.h>
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

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
	int isPresent;
	int overlapping[100];
}logFig[100];
int figCount = 0, RECT=1, KITE=2, toRemove=-1;


// initialize
void allocatePixels(){
	int i,j;
	d.backgroundColor = ' ';
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

// adding the log while inserting a new figure into the board
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

// add overlapping data
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
			tempNode = tempNode->next;
		}
		tempNode->next = malloc(sizeof(struct node));
		tempNode->figCount = figCount;
		d.overlapCount[x][y] ++;
	}
}

// removing the overlap data while erasing out a particular figure
void removeNodeData(int x, int y){
	struct node* tempNode = d.data[x][y];
	if(tempNode->figCount == toRemove){
		d.data[x][y] = malloc(sizeof(struct node));
		d.data[x][y]->next = tempNode->next;
	}else{
		struct node* prev = tempNode;
		tempNode = tempNode->next;
		while(tempNode != NULL){
			if(tempNode->figCount == toRemove){
				prev->next = tempNode->next;
				break;
			}
			prev = tempNode;
			tempNode = tempNode->next;
		}
	}
	d.overlapCount[x][y]--;
}

// setting the value in the board, and check for overlapping
void setPixels(int x, int y, char color){
	if(d.pixels[y-1][x-1] != d.backgroundColor && color != d.backgroundColor){
		logFig[figCount].isOverlapping = 1;
		struct node *tempNode = d.data[y-1][x-1];
		while(tempNode != NULL){
			if(logFig[tempNode->figCount].isPresent){
				logFig[figCount].overlapping[tempNode->figCount]=1;
				logFig[tempNode->figCount].isOverlapping = 1;
				logFig[tempNode->figCount].overlapping[figCount]=1;
			}
			tempNode = tempNode->next;
		}
	}
	d.pixels[y-1][x-1] = color;
	if(color != d.backgroundColor)
		checkAndAddOverlapData(y-1,x-1);
	else
		removeNodeData(y-1, x-1);
}

// check if the point is inside the board
int checkRange(int i, int j){
	if(i>=1 && i<=d.width && j>=1 && j<=d.height) return 1;
	return 0;
}

int next(int count){
	if(count <= 8) return count+1;
	return 1;
}

// draw or erase a rectangle
void drawRectangle(int x, int y, int width, int height, char borderColor, char fillColor, int divisibility){
	int i,j,x1,x2,y1,y2,count=1;
	char bg = d.backgroundColor;
	if(borderColor != bg)
		logFig[figCount].isPresent = 1;
	else
		logFig[figCount].isPresent = 0;
	/**/
	for(i=x, j=y; j<=height+y-1; j++){
		if(!checkRange(i,j)) continue;
		setPixels(i,j,'0'+count);
		count = next(count);
	}
	
	for(i=x+1, j=y+height-1; i<=x+width-1; i++){
		if(!checkRange(i,j)) continue;
		setPixels(i,j,'0'+count);
		count = next(count);
	}

	for(i=x+width-1, j=y+height-2; j>=y; j--){
		if(!checkRange(i,j)) continue;
		setPixels(i,j,'0'+count);
		count = next(count);
	}
	
	for(i=x+width-2, j=y; i>x; i--){
		if(!checkRange(i,j)) continue;
		setPixels(i,j,'0'+count);
		count = next(count);
	}


	for(i=x; i<width+x; i++){
		for(j=y; j<height+y; j++){
			if(!checkRange(i,j)) continue;
			if(i==x && j==y){ 
				//setPixels(i,j,'1');
			}else if((i==x+width-1&&j==y+height-1)){
				//setPixels(i,j,'0'+width);
			}else if((i==x && j==y+height-1)){
				//setPixels(i,j,'0'+height);
			}else if((j==y && i==x+width-1)){
				//setPixels(i,j,'0'+width);
			}else if(i==x || i==x+width-1){
				//if(i==x) setPixels(i,j, (j-y+1)+'0');
				//else setPixels(i,j,height-(j-y+1)+'0'+1);
			}else if(j==y || j==y+height-1){
				//setPixels(i,j,i-x+1+'0');
			}else{
				// original values
				//x1 = d.pixels[i][y];
				//x2 = d.pixels[i][y+height-1];
				//y1 = d.pixels[x][j];
				//y2 = d.pixels[x+width-1][j];
				x1 = y1 = x2 = y2 = -1;
				if(checkRange(i,y)) x1 = d.pixels[y-1][i-1]-'0';
				if(checkRange(i,y+height-1)) x2 = d.pixels[y+height-2][i-1]-'0';
				if(checkRange(x,j)) y1 = d.pixels[j-1][x-1]-'0';
				if(checkRange(x+width-1,j)) y2 = d.pixels[j-1][x+width-2]-'0';
				printf("%d %d %d %d\n", x1,x2,y1,y2);
				if((x1%divisibility==0 && y1%divisibility==0) || (x1%divisibility==0 && y2%divisibility==0) || (x2%divisibility==0 && y1%divisibility==0) || (x2%divisibility==0 && y2%divisibility==0)){
					printf("PRINT\n");
					setPixels(i,j,'0'+divisibility);
				}else
					setPixels(i,j,fillColor);
			}
		}
	}
	if(borderColor != bg)
		addlogFig(RECT, x, y, width, height, 0, borderColor, fillColor);
}

// draw or remove a kite
// do it with 2 loops
void drawKite(int x, int y, int length, char borderColor, char fillColor){
	int i, j, tempy;
	char bg = d.backgroundColor;
	int len = 0, indc = 1, rangeStart, rangeEnd;
	if(borderColor != bg)
		logFig[figCount].isPresent = 1;
	else
		logFig[figCount].isPresent = 0;
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
	printf("\n");
	for(i=0; i<d.height; i++){
		for(j=0; j<d.width; j++){
			if((i==0 || i==d.height-1 || j==0 || j==d.width-1) && d.overlapCount[i][j]==0){
				printf("*");
			}else
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

// removing all the overlapping figures from a particular figure
void deleteAllOverlappingFor(int fcount){
	int i;
	for(i=0; i<100; i++){
		if((logFig[fcount].overlapping[i] || i==fcount) && logFig[i].isPresent){
			if(logFig[i].type == RECT)
				drawRectangle(logFig[i].x, logFig[i].y, logFig[i].width, logFig[i].height, d.backgroundColor, d.backgroundColor,3);
			else
				drawKite(logFig[i].x, logFig[i].y, logFig[i].length, d.backgroundColor, d.backgroundColor);
			logFig[i].isPresent = 0;
			deleteAllOverlappingFor(i);
		}
	}
}

// remove all figures from a particular points
void removeAllFiguresFromAPoint(int x, int y){
	int temp = x; x = y-1; y = temp-1;
	if(checkRange(x,y) && d.overlapCount[x][y] > 0){
		struct node* tempNode = d.data[x][y];
		while(tempNode->next != NULL){
			if(logFig[tempNode->figCount].isPresent)
				deleteAllOverlappingFor(tempNode->figCount);
			tempNode = tempNode->next;
		}
	}
}

void printOverlapping(int fcount){
	int i;
	printf("Overlapping figure for %d : ",fcount);
	for(i=0; i<100; i++){
		if(logFig[fcount].isPresent && logFig[fcount].isOverlapping && logFig[fcount].overlapping[i]){
			printf("%d ", i);
		}
	}
	printf("\n");
}

void printBoardWithBoundary(){
	int i, j;
	int maxx=0, maxy=0, minx=d.width, miny=d.height;
	for(i=0; i<figCount; i++){
		/*if(logFig[i].isPresent){
			if(logFig[i].type == RECT){
				minx = min(minx, logFig[i].x);
				miny = min(miny, logFig[i].y);
				maxx = max(maxx, logFig[i].x+logFig[i].width-1);
				maxy = max(maxy, logFig[i].y+logFig[i].height-1);
			}else{
				minx = min(minx, logFig[i].x-logFig[i].length);
				miny = min(miny, logFig[i].y-logFig[i].length);
				maxx = min(maxx, logFig[i].x+logFig[i].length);
				maxy = min(maxy, logFig[i].y+logFig[i].length);
			}	
		}*/
	}
	for(i=0; i<d.height; i++){
		for(j=0; j<d.width; j++){
			if(d.overlapCount[i][j]!=0){
				printf("%d %d\n", i, j);
				minx = min(minx, i);
				maxx = max(maxx, i);
				miny = min(miny, j);
				maxy = max(maxy, j);
			}
		}
	}
	printf("minx:%d maxx:%d miny:%d maxy:%d\n", minx, maxx, miny, maxy);
	minx --, maxx++, miny--, maxy++;
	for(i=0; i<d.height; i++){
		for(j=0; j<d.width; j++){
			if((i==minx && j==miny) || (i==maxx && j==maxy)) printf("+");
			else if((i==minx&&j==maxy) || (i==maxx&&j==miny)) printf("+");
			else if((i==minx || i==maxx)) printf("-");
			else if(j==miny || j==maxy) printf("|");

			else if((i==0 || i==d.height-1 || j==0 || j==d.width-1) && d.overlapCount[i][j]==0)
				printf("*");
			else printf("%c", d.pixels[i][j]);
		}
		printf("\n");
	}printf("\n");
}

int main(){
	int x, y, height, width, length;
	int divisibility;
	freopen("input4.in", "r", stdin);
	//freopen("output4.out", "w", stdout);
	printf("Enter the details of the image\n");
	printf("Height : ");
	scanf("%d", &d.height);
	printf("Width : ");
	scanf("%d", &d.width);
	allocatePixels();
	printf("Enter the left top corner x : ");
	scanf("%d", &x);
	printf("Enter the left top corner y : ");
	scanf("%d", &y);
	printf("Enter the widht of the rectangle : "); scanf("%d", &width);
	printf("Enter the height of the rectangle : "); scanf("%d", &height);
	printf("Enter the divisibility number : "); scanf("%d", &divisibility);
	drawRectangle(x,y,width, height, 'B', ' ',divisibility);
	printBoard();
}