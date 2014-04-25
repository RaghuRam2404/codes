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

char graph[105][105];
bool visited[105][105];

struct point{
	int x, y, len;
	point(){x = y = len = 0;}
};

int bfs(point start, point end){
	int len = 0;
	queue<point> q;
	q.push(start);
	visited[start.x][start.y] = true;
	while(!q.empty()){
		point t = q.front(), temp;
		q.pop();
		// insert all 4 adjacent nodes
		if(graph[t.x-1][t.y] == 'O' && visited[t.x-1][t.y] == false){
			temp.x = t.x-1;
			temp.y = t.y;
			temp.len = t.len + 1;
			q.push(temp);
			visited[t.x-1][t.y] = true;
			//cout<<temp.x-1<<" "<<temp.y-1<<endl;
		}
		if(graph[t.x+1][t.y] == 'O' && visited[t.x+1][t.y] == false){
			temp.x = t.x+1;
			temp.y = t.y;
			temp.len = t.len + 1;
			q.push(temp);
			visited[t.x+1][t.y] = true;
			//cout<<temp.x-1<<" "<<temp.y-1<<endl;
		}
		if(graph[t.x][t.y-1] == 'O' && visited[t.x][t.y-1] == false){
			temp.x = t.x;
			temp.y = t.y-1;
			temp.len = t.len + 1;
			q.push(temp);
			visited[t.x][t.y-1] = true;
			//cout<<temp.x-1<<" "<<temp.y-1<<endl;
		}
		if(graph[t.x][t.y+1] == 'O' && visited[t.x][t.y+1] == false){
			temp.x = t.x;
			temp.y = t.y+1;
			temp.len = t.len + 1;
			q.push(temp);
			visited[t.x][t.y+1] = true;
			//cout<<temp.x-1<<" "<<temp.y-1<<endl;
		}

		if(graph[t.x-1][t.y]=='#') return t.len+1;
		if(graph[t.x+1][t.y]=='#') return t.len+1;
		if(graph[t.x][t.y-1]=='#') return t.len+1;
		if(graph[t.x][t.y+1]=='#') return t.len+1;

	}
	return -1;
}

int main(){
	//freopen("input.in", "r", stdin);
	int t, m, n, i, j;
	s(t);
	while(t--){
		s(m), s(n);
		memset(graph, '*', sizeof(graph));
		memset(visited, false, sizeof(visited));
		point start, end;
		char temp[105];
		for(i=1; i<=m; i++){
			sstring(temp);
			for(j=1; j<=n; j++){
				if(temp[j-1] == '$') start.x = i, start.y = j;
				if(temp[j-1] == '#') end.x = i, end.y = j;
				graph[i][j] = temp[j-1];
			}
		}

		for(i=0; i<=n+1; i++) graph[0][i] = graph[m+1][i] = '*';
		for(i=0; i<=m+1; i++) graph[i][0] = graph[i][n+1] = '*';
		/*	
		for(i=0; i<=m+1; i++){
			for(j=0; j<=n+1; j++)
				cout<<graph[i][j]<<" ";
			cout<<endl;
		}
		*/

		cout<<bfs(start, end)<<endl;

	}
	return 0;
}