#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define s(a) scanf("%d",&a)
#define p(a) printf("%d\n",a)

struct positionDetails{
	int x, y;
	int k;
	int steps;
	positionDetails(){ steps=0; }
};
typedef positionDetails position;

int dx[8] = {2,-2,1,-1,2,-2,1,-1};
int dy[8] = {1,1,2,2,-1,-1,-2,-2};
int dist[2][101][101];
char posMap[101][101];
bool visited[101][101];
int n, m;
vector<position> v;

bool inRange(int x, int y){
	return (x>=0 && x<n)&&(y>=0 && y<m);
}

int reach(int fromx, int fromy, int tox, int toy){
	bool visit[15][15] = {false};
	visit[fromx][fromy] = true;
	if(fromx == tox && fromy == toy) return 0;
	// bfs
	queue<int> q;
	q.push(fromx);
	q.push(fromy);
	q.push(0);
	while(!q.empty()){
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		int steps = q.front(); q.pop();

		if(x==tox && y==toy) return steps;

		for(int i=0; i<8; i++){
			if(inRange(x+dx[i], y+dy[i]) && visit[x+dx[i]][y+dy[i]] == false){
				visit[x+dx[i]][y+dy[i]] = true;
				q.push(x+dx[i]);
				q.push(y+dy[i]);
				q.push(steps+1);
			}
		}
	}
	return -1;
}

void bfs(position riderPosition, int riderindex, int riderCount){
	int i, ii, j, jj;
	int k = riderPosition.k;
	int x = riderPosition.x;
	int y = riderPosition.y;
	dist[1][x][y]=0;
	for(ii=0; ii<n; ii++){
		for(jj=0; jj<m; jj++){
			int steps = reach(x,y,ii,jj);
			if(steps == -1)
				dist[1][ii][jj] = -1, dist[0][ii][jj]=-1;
			else{
				dist[1][ii][jj] = steps/k;
				if(steps%k != 0) dist[1][ii][jj] ++;
				if(dist[0][ii][jj]!=-1){
					if(dist[0][ii][jj]==INT_MAX)
						dist[0][ii][jj] = dist[1][ii][jj];
					else
						dist[0][ii][jj] += dist[1][ii][jj];
				}
			}
			//cout<<steps<<","<<dist[riderCount][ii][jj]<<endl;
		}
	}

}

int main(){
	freopen("input.in", "r", stdin);
	int t, i, j, k;
	s(t);
	for(int test=1; test<=t; test++){
		s(n), s(m);
		v.clear();
		for(i=0; i<n; i++){
			cin>>posMap[i];
			for(j=0; j<m; j++){
				if(posMap[i][j] != '.'){
					k = posMap[i][j] - '0';
					position temp;
					temp.x = i;
					temp.y = j;
					temp.k = k;
					temp.steps = 0;
					v.push_back(temp);
				}
			}
		}

		memset(dist, INT_MAX, sizeof(dist));
		// for each guy find the minimum path to travel to each cell
		int riderCount = v.size();
		for(i=0; i<n; i++){
			for(j=0; j<m; j++)
				dist[0][i][j] = INT_MAX;
		}
		for(int riderindex=0; riderindex<riderCount; riderindex++){
			memset(visited, false, sizeof(visited));
			position riderPosition = v[riderindex];
			dist[1][riderPosition.x][riderPosition.y] = 0;
			bfs(riderPosition, riderindex, riderCount);
		}
		if(riderCount==0){
			cout<<"Case "<<test<<": "<<0<<endl;
			continue;
		}
		int minSteps = INT_MAX;
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				//cout<<dist[riderCount][i][j]<<" ";
				if(dist[0][i][j] != -1)
					minSteps = min(minSteps, dist[0][i][j]);
			}//cout<<endl;
		}
		if(minSteps == INT_MAX)
			cout<<"Case "<<test<<": "<<-1<<endl;
		else
			cout<<"Case "<<test<<": "<<minSteps<<endl;
			//cout<<minSteps<<endl;
	}
	return 0;
}