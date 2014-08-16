#include <stdio.h>
#define s(a) scanf("%d", &a)

int liesOn(int x1, int y1, int x2, int y2, double x, double y){
	double a = y2-y1;
	double b = x1 - x2;
	double c = b*y1 + a*x1;
	printf("%lf %lf\n", x,y);
	if((a*x + b*y) == c)
		return 1;
	return 0;
}

int main(){
	int x1, x2, y1, y2;
	double i, j, answer;
	int x3, x4, y3, y4;
	double x, y, m;
	double slope;
	s(x1), s(y1), s(x2), s(y2);
	s(x3), s(y3), s(x4), s(y4);
	
	if((x2 - x1) == 0){
		for(i=x1,j=y1; i<=x2&&j<=y2; ){
			answer = liesOn(x3,y3,x4,y4,i,j);
			if(answer == 1) break;
			j+=slope;
		}
		if(answer == 1){
			printf("Overlaps on %lf %lf\n", i, j);
		}else
			printf("No Overlaps\n");
	}else{
		slope = (double)(y2-y1)/(double)(x2-x1);
		printf("%lf\n", slope);
		for(i=x1,j=y1; i<=x2&&j<=y2; ){
			answer = liesOn(x3,y3,x4,y4,i,j);
			if(answer == 1) break;
			if(slope == 0) i++;
			else i+=(1/slope), j+=slope;
		}
		if(answer == 1){
			printf("Overlaps on %lf %lf\n", i, j);
		}else
			printf("No Overlaps\n");
	}
}