#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define s(a) scanf("%d",&a)
#define p(a) printf("%d\n",a)
#define sll(a) scanf("%lld", &a)
#define pll(a) printf("%lld\n", a)
#define ss(a) scanf("%llu", &a)
#define pp(a) printf("%llu\n", a)
#define sstring(a) scanf("%s", a)

struct position{
	int posX, posY;
	int steps;
	position(){ steps = 0; }
};
typedef position pos;
int posHx, posHy;
char positionMap[25][25];
bool visited[25][25];
int m, n;

bool inRange(int x, int y){
	return ((x>=0)&&(x<m))&&((y>=0)&&(y<n))&&(positionMap[x][y]!='#'&&positionMap[x][y]!='m')&&!visited[x][y];
}

int bfs(pos a){
	memset(visited, false, sizeof(visited));
	queue<pos> q;
	if(inRange(a.posX-1, a.posY)){
		visited[a.posX-1][a.posY] = true;
		pos temp;
		temp.posX = a.posX-1;
		temp.posY = a.posY;
		temp.steps = 1;
		//cout<<temp.posX<<","<<temp.posY<<" ";
		q.push(temp);
	}
	if(inRange(a.posX+1, a.posY)){
		visited[a.posX+1][a.posY] = true;
		pos temp;
		temp.posX = a.posX+1;
		temp.posY = a.posY;
		temp.steps = 1;
		//cout<<temp.posX<<","<<temp.posY<<" ";
		q.push(temp);
	}
	if(inRange(a.posX, a.posY-1)){
		visited[a.posX][a.posY-1] = true;
		pos temp;
		temp.posX = a.posX;
		temp.posY = a.posY-1;
		temp.steps = 1;
		//cout<<temp.posX<<","<<temp.posY<<" ";
		q.push(temp);
	}
	if(inRange(a.posX, a.posY+1)){
		visited[a.posX][a.posY+1] = true;
		pos temp;
		temp.posX = a.posX;
		temp.posY = a.posY+1;
		temp.steps = 1;
		//cout<<temp.posX<<","<<temp.posY<<" ";
		q.push(temp);
	}
	while(!q.empty()){
		a = q.front();
		q.pop();
		if(positionMap[a.posX][a.posY]=='h') return a.steps;
		if(inRange(a.posX-1, a.posY)){
			visited[a.posX-1][a.posY] = true;
			pos temp;
			temp.posX = a.posX-1;
			temp.posY = a.posY;
			temp.steps = a.steps+1;
			//cout<<temp.posX<<","<<temp.posY<<" ";
			q.push(temp);
		}
		if(inRange(a.posX+1, a.posY)){
			visited[a.posX+1][a.posY] = true;
			pos temp;
			temp.posX = a.posX+1;
			temp.posY = a.posY;
			temp.steps =  a.steps+1;
			//cout<<temp.posX<<","<<temp.posY<<" ";
			q.push(temp);
		}
		if(inRange(a.posX, a.posY-1)){
			visited[a.posX][a.posY-1] = true;
			pos temp;
			temp.posX = a.posX;
			temp.posY = a.posY-1;
			temp.steps =  a.steps+1;
			//cout<<temp.posX<<","<<temp.posY<<" ";
			q.push(temp);
		}
		if(inRange(a.posX, a.posY+1)){
			visited[a.posX][a.posY+1] = true;
			pos temp;
			temp.posX = a.posX;
			temp.posY = a.posY+1;
			temp.steps =  a.steps+1;
			//cout<<temp.posX<<","<<temp.posY<<" ";
			q.push(temp);
		}
	}
	return 0;
}

int main(){
	//freopen("input.in", "r", stdin);
	int t, i, j;
	s(t);
	for(int cases = 1; cases<=t; cases++){
		s(m), s(n);
		pos posA, posB, posC;
		for(i=0; i<m; i++){
			cin>>positionMap[i];
			for(j=0; j<n; j++){
				if(positionMap[i][j]=='a'){
					posA.posX = i;
					posA.posY = j;
				}else if(positionMap[i][j] == 'b'){
					posB.posX = i;
					posB.posY = j;
				}else if(positionMap[i][j] == 'c'){
					posC.posX = i;
					posC.posY = j;
				}else if(positionMap[i][j] == 'h'){
					posHx = i; 
					posHy = j;
				}	
			}
		}
		int A = bfs(posA);
		int B = bfs(posB);
		int C = bfs(posC);
		int ans = max(0, max(A, max(B, C)));
		cout<<"Case "<<cases<<": "<<ans<<endl;
	}
	return 0;
}