#include <bits/stdc++.h>
using namespace std;

int shape[100][100];
int ht, wt;
struct shape1{ int h,w,deg; int presence[4][4]; }s1;
struct shape2{ int h,w,deg; int presence[3][3]; }s2;
struct shape3{ int h,w,deg; int presence[2][2]; }s3;
struct shape4{ int h,w,deg; int presence[3][3]; }s4;
struct shape5{ int h,w,deg; int presence[3][3]; }s5;
struct shape6{ int h,w,deg; int presence[3][3]; }s6;
struct shape7{ int h,w,deg; int presence[3][3]; }s7;

void init(){

	s1.deg = s2.deg = s3.deg = s4.deg = s5.deg = s6.deg = s7.deg = 0;

	s1.h=1, s1.w=4;
	s1.presence[0][0] = 1;
	s1.presence[0][1] = 1;
	s1.presence[0][2] = 1;
	s1.presence[0][3] = 1;

	s2.h=2, s2.w=3;
	s2.presence[0][0]=0;
	s2.presence[0][1] = s2.presence[0][2] = s2.presence[1][0] = s2.presence[1][1] = s2.presence[1][2] = 1;

	s3.h=2, s3.w=2;
	s3.presence[0][0] = s3.presence[0][1] = s3.presence[1][0] = s3.presence[1][1] = 1;

	s4.h=2, s4.w=3;
	s4.presence[0][0] = s4.presence[1][0] = s4.presence[1][1] = s4.presence[1][2] = 1;
	s4.presence[0][1] = s4.presence[0][2] = 0;

	s5.h=2, s5.w=3;
	s5.presence[0][1] = s5.presence[0][0] = 0;
	s5.presence[0][2] = s5.presence[1][0] = s5.presence[1][1] = s5.presence[1][2] = 1;

	s6.h=2, s6.w=3;
	s6.presence[0][0] = s6.presence[0][1] = s6.presence[1][1] = s6.presence[1][2] = 1;
	s6.presence[0][2] = s6.presence[1][0] = 0;

	s7.h=2, s7.w=3;
	s7.presence[0][0] = s7.presence[1][2] = 0;
	s7.presence[0][1] = s7.presence[0][2] = s7.presence[1][0] = s7.presence[1][1] = 1;
}

struct shape1 rotateShape1(struct shape1 s1){
	struct shape1 tempS1 = s1;
	tempS1.h = s1.w;
	tempS1.w = s1.h;
	int deg = s1.deg;
	switch(deg){
		case 0:   deg = 270; break;
		case 270: deg = 180; break;
		case 180: deg = 90; break;
		case 90:  deg = 0; break;
	}
	if(s1.h==1 && s1.w==4){
		s1.presence[0][0] = 1;
		s1.presence[1][0] = 1;
		s1.presence[2][0] = 1;
		s1.presence[3][0] = 1;
	}else{	
		s1.presence[0][0] = 1;
		s1.presence[0][1] = 1;
		s1.presence[0][2] = 1;
		s1.presence[0][3] = 1;
	}
	return tempS1;
}

struct shape2 rotateShape2(struct shape2 s2){
	struct shape2 tempS2 = s2;
	tempS2.h = s2.w;
	tempS2.w = s2.h;
	if(s1.h==2 && s1.w==3){

	}else{

	}
	return tempS2;
}

struct shape4 rotateShape4(struct shape4 s4){
	struct shape4 temps4 = s4;
	temps4.h = s4.w;
	temps4.w = s4.h;
	int deg = s4.deg;
	switch(deg){
		case 0:   
			temps4.deg = 90; 
			temps4.presence[0][0] = temps4.presence[0][1] = temps4.presence[1][0] = temps4.presence[2][0] = 1;
			temps4.presence[1][1] = temps4.presence[2][1] = 0;
		break;
		case 90: 
			temps4.deg = 180;
			temps4.presence[0][0] = temps4.presence[0][1] = temps4.presence[0][2] = temps4.presence[1][2] = 1;
			temps4.presence[1][0] = temps4.presence[1][1] = 0;
		break;
		case 180: 
			temps4.deg = 270; 
			
		break;
		case 270:  deg = 0; break;
	}
	return temps4;
}

int inRange(int x, int y){
	return (x>=0&&x<ht&&y>=0&&y<wt);
}

int findShape1deg0(int x, int y){
	struct shape1 temps1 = s1;
	int i, j;
	for(i=0; i<temps1.h; i++,x++){
		for(j=0; j<temps1.w; j++,y++){
			if(temps1.presence[i][j]==1 && inRange(x,y) && shape[x][y]==1);
			else if(temps1.presence[i][j]==0);
			else return 0;
		}
	}
	return -1;	
}
int findShape1deg90(int x, int y){
	
	return -1;	
}
int findShape1deg180(int x, int y){

	return -1;	
}
int findShape1deg270(int x, int y){
	
	return -1;	
}

int findShape4deg0(int x, int y){
	struct shape4 temps1 = s4;
	int tx, ty;
	int i, j;
	for(i=0,tx=x; i<temps1.h; i++,tx++){
		for(j=0,ty=y; j<temps1.w; j++,ty++){
			//cout<<temps1.presence[i][j]<<","<<shape[tx][ty]<<","<<tx<<","<<ty<<"     ";
			if(temps1.presence[i][j]==1 && inRange(tx,ty) && shape[tx][ty]==1);
			else if(temps1.presence[i][j]==0);
			else return -1;
		}
	}
	return 4;
}
int findShape4deg90(int x, int y){
	struct shape4 temps1 = rotateShape4(s4);
	int tx, ty;
	int i, j;
	for(i=0,tx=x; i<temps1.h; i++,tx++){
		for(j=0,ty=y; j<temps1.w; j++,ty++){
			if(temps1.presence[i][j]==1 && inRange(tx,ty) && shape[tx][ty]==1);
			else if(temps1.presence[i][j]==0);
			else return -1;
		}
	}
	return 4;
}
int findShape4deg180(int x, int y){
	struct shape4 temps4 = s4;
	temps4 = rotateShape4(temps4);
	temps4 = rotateShape4(temps4);
	int i, j, tx, ty;
	for(i=0,tx=x; i<temps4.h; i++,tx++){
		for(j=0,ty=y; j<temps4.w; j++,ty++){
			//cout<<temps4.presence[i][j]<<","<<shape[tx][ty]<<","<<tx<<","<<ty<<"     ";
			if(temps4.presence[i][j]==1 && inRange(tx,ty) && shape[tx][ty]==1);
			else if(temps4.presence[i][j]==0);
			else return -1;
		}
	}
	return 4;	
}
int findShape4deg270(int x, int y){
	
	return -1;	
}

int find(int no, int x, int y){
	switch(no){
		case 1:

		break;
		case 2:

		break;
		case 3:

		break;
		case 4:
			if(findShape4deg0(x,y) == no || findShape4deg90(x,  y) == no || findShape4deg180(x, y) == no || findShape4deg270(x,y) == no){
				return no;
			}else
				return -1;
		break;
		case 5:

		break;
		case 6:

		break;
		case 7:

		break;
	}
}

int* findFigure(int no){
	int i, j;
	int *ans = new int[2];
	ans[0] = -1, ans[1] = -1;
	for(i=0; i<ht; i++){
		for(j=0; j<wt; j++){
			int result = find(no, i, j);
			if(result == no){
				ans[0] = i, ans[1] = j;
				return ans;
			}
		}
	}
	return ans;
}

int main(){
	int size,i,j,no;
	freopen("input.in", "r", stdin);
	cin>>ht>>wt;
	for(i=0; i<ht; i++){
		for(j=0; j<wt; j++){
			cin>>shape[i][j];
		}
	}
	cin>>no;
	init();
	int *pt = new int[2];
	pt = findFigure(no);
	cout<<pt[0]<<" "<<pt[1]<<endl;
}