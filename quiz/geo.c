#include <stdio.h>
#define s(a) scanf("%d", &a)

int main(){
	int x1, x2, y1, y2;
	int x3, x4, y3, y4;
	double a1,a2,b1,b2,c1,c2,det,x5,y5;
	double m1, m2;
	s(x1), s(y1), s(x2), s(y2);
	s(x3), s(y3), s(x4), s(y4);
	a1 = y2-y1; b1 = x1-x2; c1 = a1*x1+b1*y1;
	a2 = y4-y3; b2 = x3-x4; c2 = a2*x3+b2*y3;
	printf("%lf %lf %lf \n", a1, b1, c1);
	printf("%lf %lf %lf \n", a2, b2, c2);
	det = a1*b2 - b1*a2;
	printf("%lf\n", det);
	if(det == 0){
		if((a1==a2 && b1==b2 && c1==c2 ) || (abs(b1)==abs(b2) && abs(c1)==abs(c2)))
			printf("Overlapping\n");
		else
			printf("Parallel\n");
	}else{
		x5 = (b2*c1-b1*c2)/det;
		y5 = (a1*c2-a2*c1)/det;
		printf("%lf %lf\n", x5, y5);
	}
}