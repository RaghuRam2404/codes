#include <stdio.h>
struct diagram{
	int height, width;
	char **pixels;
}d;

void allocatePixels(){
	int i,j;
	d.pixels = malloc(d.height*(sizeof(int*)));
	for(i=0; i<d.height; i++){
		d.pixels[i] = malloc(d.width*sizeof(int));
	}
	for (i=0; i<d.height; i++)
		for(j=0; j<d.width; j++)
			d.pixels[i][j] = 'w';
}

void setPixels(int x, int y, char color){
	d.pixels[y-1][x-1] = color;
}

void drawRectangle(int x, int y, int width, int height, char borderColor, char fillColor){
	int i,j;
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

int main(){
	scanf("%d %d", &d.height, &d.width);
	allocatePixels();
	printBoard();
}