#include <bits/stdc++.h>
using namespace std;

/*** QUEUE ***/
int q1[100000];
int q2[100000];
int qfirst = -1, qsecond = -1, s=0;

int size(){
	return s;
}

void print(){
	int i;
	cout<<"DATA : ";
	for(i=qfirst; i<=qsecond; i++){
		cout<<q1[i]<<","<<q2[i]<<" ";
	}cout<<endl;
}

void enqueue(int x, int y){
	if(qfirst==-1){
		qfirst++; qsecond++;
		q1[qfirst] = x;
		q2[qfirst] = y;
	}
	else{
		qsecond++;
		q1[qsecond] = x;
		q2[qsecond] = y;
	}
	s++;
}

int* dequeue(){
	int *data = new int[2];
	data[0] = -1, data[1] = -1;
	if(size()<=0) return data;
	data[0] = q1[qfirst];
	data[1] = q2[qfirst]; 
	if(qfirst == qsecond){
		qfirst = qsecond = -1;
	}else{
		qfirst++;
	}
	s--;
	return data;
}
/*** END OF QUEUE ***/

/*** HORSE RIDING ***/
int board[8][8];
int dx[8] = {-2, -2, -1, -1,  1, 1,  2, 2};
int dy[8] = {-1,  1, -2, +2, -2, 2, -1, 1};

int inRange(int x, int y){
	return (x>=0&&x<8&&y>=0&&y<8);
}

void precalculate(int x, int y){
	enqueue(x,y);
	board[x][y] = 0;
	while(size()>0){
		int *data = dequeue();
		int tempx, tempy;
		for(int i=0; i<8; i++){
			tempx = data[0]+dx[i];
			tempy = data[1]+dy[i];
			if(inRange(tempx, tempy) && board[tempx][tempy]==-1){
				enqueue(tempx, tempy);
				board[tempx][tempy] = board[data[0]][data[1]]+1;
			}
		}
	}
}
/*** END OF HORSE RIDING ***/


int main(){
	memset(board, -1, sizeof(board));
	//freopen("input.in", "r", stdin);
	int fromx, fromy, tox, toy;
	cin>>fromx>>fromy;
	precalculate(fromx, fromy);
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cin>>tox>>toy;
	cout<<"minimum no of steps : "<<board[tox][toy]<<endl;
}