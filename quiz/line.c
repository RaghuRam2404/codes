#include <stdio.h>
#define errorPercent 0.05
#define s(a) scanf("%d", &a)

double abs(double a){
	if(a>0) return a;
	return -a;
}

int liesOn(int x1, int y1, int x2, int y2, double x, double y){
	double a = y2-y1;
	double b = x1 - x2;
	double c = b*y1 + a*x1;
	if(abs((a*x + b*y)-c)<=errorPercent)
		return 1;
	return 0;
}

int overlapping(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4){
	if(liesOn(x3,y3,x4,y4,x1,y1) && liesOn(x3,y3,x4,y4,x2,y2)){
		return 1;
	}
	return 0;
}

int parallel(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4){
	double a1 = y2-y1;
	double a2 = y4-y3;
	double b1 = x1-x2;
	double b2 = x3-x4;
	if(abs(a1)==abs(a2) && abs(b1)==abs(b2)) return 1;
	return 0;
}

int crosses(int x1, int x2, int x3, int x4){
	int temp;
	if(x1>x2){ temp = x1,x1=x2;x2=temp; }
	if(x3>x4){ temp = x3,x3=x4;x4=temp; }
	if(((x1>x4)&&(x2>x4)) || (x1<x3&&x2<x3)) return 0;
	return 1;
}

int main(){
	int x1, x2, x3, x4, y1, y2, y3, y4,found = 0,temp;
	double dx, use = 1, usex, usey;
	
	s(x1), s(y1), s(x2), s(y2);
	s(x3), s(y3), s(x4), s(y4);

	dx = 0.0001;
	usex = x1, usey = y1;
	if(x1>x2) {temp = x1; x1 = x2; x2 = temp; temp = y1; y1 = y2; y2 = temp; usex = x1, usey = y1;}
	printf("%d x cross\n",crosses(x1,x2,x3,x4));
	printf("%d y cross\n",crosses(y1,y2,y3,y4));
	if(overlapping(x1,x2,x3,x4,y1,y2,y3,y4)){
		printf("They are overlapping\n");
	}else if(parallel(x1,x2,x3,x4,y1,y2,y3,y4)){
		printf("They are parallel\n");
	}else if(!(crosses(x1,x2,x3,x4) && crosses(y1,y2,y3,y4))){
		printf("NOT FOUND\n");
	}else{
		for(;(x1<x2 && usex<=x2) || (x1>x2&&usex>=x1);){
			if(liesOn(x3,y3,x4,y4,usex,usey)){	
				found = 1;
				printf("%lf %lf--->found\n", usex, usey);
				break;
			}
			if(x1<x2) usex+=dx;
			else usex-=dx;
		}
		if(!found){
			printf("NOT FOUND\n");
		}
	}

}