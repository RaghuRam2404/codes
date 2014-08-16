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

// draw or erase a rectangle
void drawRectangle(int x, int y, int width, int height, char borderColor, char fillColor){
	int i,j;
	char bg = d.backgroundColor;
	if(borderColor != bg)
		logFig[figCount].isPresent = 1;
	else
		logFig[figCount].isPresent = 0;
	for(i=x; i<width+x; i++){
		for(j=y; j<height+y; j++){
			if(!checkRange(i,j)) continue;
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
			printf("%c", d.pixels[i][j]);
		}
		printf("\n");
	}printf("\n");
}

void printlogFig(){
	int i;
	for(i=0; i<figCount; i++){
		if(logFig[i].type == RECT){
			printf("%d RECTANGLE : x-%d y-%d width-%d height-%d borderColor-%c fillColor-%c\n",i, logFig[i].x, logFig[i].y, logFig[i].width, logFig[i].height, logFig[i].borderColor, logFig[i].fillColor);
		}else{
			printf("%d KITE : x-%d y-%d length-%d borderColor-%c fillColor-%c\n",i, logFig[i].x, logFig[i].y, logFig[i].length, logFig[i].borderColor, logFig[i].fillColor);
		}
	}
	printf("\n");
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
				drawRectangle(logFig[i].x, logFig[i].y, logFig[i].width, logFig[i].height, d.backgroundColor, d.backgroundColor);
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
	printf("\n");
	for(i=0; i<d.height; i++){
		for(j=0; j<d.width; j++){
			if(d.overlapCount[i][j]!=0){
				minx = min(minx, i);
				maxx = max(maxx, i);
				miny = min(miny, j);
				maxy = max(maxy, j);
			}
		}
	}
	minx --, maxx++, miny--, maxy++;
	for(i=0; i<d.height; i++){
		for(j=0; j<d.width; j++){
			if((i==minx && j==miny) || (i==maxx && j==maxy)) printf("+");
			else if((i==minx&&j==maxy) || (i==maxx&&j==miny)) printf("+");
			else if((i==minx || i==maxx) && (j>=miny && j<=maxy)) printf("-");
			else if((j==miny || j==maxy) && (i>=minx && i<=maxx)) printf("|");
			else if((i==0 || i==d.height-1 || j==0 || j==d.width-1) && d.overlapCount[i][j]==0){
				printf("*");
			}
			else printf("%c", d.pixels[i][j]);
		}
		printf("\n");
	}printf("\n");
}

void getAndPrintRectangle(){
	int x, y, width, height;
	printf("Enter the left top corner x : ");
	scanf("%d", &x);
	printf("Enter the left top corner y : ");
	scanf("%d", &y);
	printf("Enter the widht of the rectangle : "); scanf("%d", &width);
	printf("Enter the height of the rectangle : "); scanf("%d", &height);
	drawRectangle(x,y,width, height, 'B', 'G');
}

void getAndPrintKite(){
	int x, y, length;
	printf("Enter the center x : ");
	scanf("%d", &x);
	printf("Enter the center y : ");
	scanf("%d", &y);
	printf("Enter the length : "); scanf("%d", &length);
	drawKite(x,y,length, 'B', 'P');
}

int main(){
	int x, y, height, width, length, n, i, typ, noOfDeletions;
	freopen("input7.in", "r", stdin);
	//freopen("output7.out", "w", stdout);
	printf("Enter the details of the image\n");
	printf("Height : ");
	scanf("%d", &d.height);
	printf("Width : ");
	scanf("%d", &d.width);
	allocatePixels();
	printf("Enter no of figures : ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("Enter the type of the figure : ");
		scanf("%d", &typ);
		if(typ == 1){
			getAndPrintRectangle();
		}else if(typ == 2){
			getAndPrintKite();
		}
	}
	printBoardWithBoundary();
	printlogFig();

	for(i=0; i<n; i++){
		printOverlapping(i);
	}


	printf("No of deletions to be performed on the board : ");
	scanf("%d", &noOfDeletions);
	for(i=0; i<noOfDeletions; i++){
		scanf("%d", &typ);
		deleteAllOverlappingFor(typ);
	}
	printBoardWithBoundary();;

}